

%{

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define N 5000 //elementos en la tabla hash
// Estructura de los simbolos
int amb = 0;
int amb2 = 0;
typedef struct sym SYM;
struct sym
{
   unsigned char name[50];
   char value_type;
   int int_value;
   float float_value;
   SYM * sig;
};
// EStructura de nodo del arbol sintactico
typedef struct asr ASR;
struct asr {
   int node_type;
   unsigned char name[50];
   char value_type;
   int int_value;
   float float_value;
   ASR * izquierda;
   ASR * derecha;
   ASR * sig;
   SYM * simb;
};

// Estructura de lista nos permite tener mejor control de sus nodos internos
typedef struct lst LST;
struct lst
{
   unsigned char name[50];
   char value_type;
   LST * sig;
};






extern int yylex();
extern FILE *yyin;
extern int line;
int yyerror(char const * s);

ASR * new_tree_node(int, unsigned char [], char, int, float, ASR *, ASR *, ASR *,SYM*);
ASR * search_node_tree(ASR *,unsigned char []);

char revision_tipos(ASR *);


/*void assign_type(LST *, int);
void assign_type_f(SYM*);
void assign_type_fpar(SYM*);*/

void tabla_simb();
void tabla_simbf();
void tabla_simbf_par();
unsigned int hash(unsigned char []);


LST * nuevo_nodo_lista(unsigned char [], int, LST *);
LST * cola(LST *);

SYM * nuevo_nodo_tabla(unsigned char [], int);
SYM * buscar_simbolo(unsigned char []);
void insert_table_node(SYM *);


SYM * nuevo_nodo_tabla_f(unsigned char [], int);
SYM * buscar_simbolo_f(unsigned char []);
void insert_table_node_f(SYM *);


SYM * nuevo_nodo_tabla_fpar(unsigned char [], int);
SYM * buscar_simbolo_fpar(unsigned char []);
void insert_table_node_fpar(SYM *);

void imprimir_sym();

//metodos del interprete
void check_tree(ASR *);
int expr_int_value(ASR * root);
float expr_float_value(ASR * root);
char expr_value_type(ASR * root);




void print_tree(ASR *, int);
void print_list(LST *);
void print_table();


//inicializacion tabla y lista de simbolos
ASR *tree = NULL;
ASR * tree_fun = NULL;  //arbol de funcionalidades de funciones

ASR *list = NULL;
ASR *list_fun = NULL; // lista de id de funciones
//ASR *list_fun_par = NULL; // lista de variables locales de funciones







SYM *table[N]; // tabla hash de simbolos globales
SYM *tablef[N]; // tabla hash de funciones
//SYM *tablefvar[N]; // tabla hash de funciones

SYM *tablefpar[N]; // tabla hash de funciones

%}

%union{
   struct asr * yynodo;
   unsigned char yyid[50];
   int yyint;
   float yyfloat;
   char yytipo;
}

%token END PROGRAM BEGINI IF ENDIF ELSE FOR STEP DO WHILE READ PRINT SUMA RESTA MULTI DIVIDE PARENI PAREND EQUAL MENORQ MAYORQ MENORIQ MAYORIQ PCOMA DOSPUNTOS COMA OTRO INT FLOAT CONS VAR PYC REPEAT UNTIL ASSIGN THEN FUN CALL RETRN PARS EXEC
%precedence THEN
%precedence ELSE
%token<yyint> NINT
%token<yyfloat> NFLOAT
%token<yyid> IDF
%type <yytipo> type
%type <yynodo> stmt stmt_lst expr term factor expresion opt_stmts  opt_exprs expr_lst       oparams params param            opt_fun_decls fun_decls fun_decl      opt_decls decl_lst decl
%start prog

%%

prog : PROGRAM IDF opt_decls opt_fun_decls BEGINI opt_stmts END { list = $3; tree = $6; tree_fun = $4;  } 
;

opt_decls : //palabra vacia
                           { $$ = NULL; amb2++; }
          | decl_lst                                           { $$ = $1; amb2++;}
;

decl_lst : decl PCOMA decl_lst                                 { $1 -> sig = $3, $$ = $1; }
         | decl                                                { $$ = $1; }
;

decl : VAR IDF DOSPUNTOS type     {

   if (amb2 == 0){
      //LST *n = nuevo_nodo_lista($2, $4, NULL); 

      SYM *n2 = nuevo_nodo_tabla($2, $4); 
      if (buscar_simbolo($2) != NULL){ 
         yyerror("Esta variable ya existe"); 
      } 
      insert_table_node(n2); 
      
      $$ = new_tree_node(VAR, $2, $4, 0, 0.0, NULL, NULL, NULL,n2);
   }else{
      
      //LST *n = nuevo_nodo_lista($2, $4, NULL); 

      SYM *n2 = nuevo_nodo_tabla_fpar($2, $4); 
      if (buscar_simbolo_fpar($2) != NULL){ 
         yyerror("Esta variable ya existe"); 
      } 
      insert_table_node_fpar(n2); 
      
      $$ = new_tree_node(VAR, $2, $4, 0, 0.0, NULL, NULL, NULL,n2);
   }


};

type : INT                                                 { $$ = 'i'; }
     | FLOAT                                               { $$ = 'f'; }
;



//declaracion de funciones
opt_fun_decls: { $$ = NULL; amb++;}//palabra vacía  
               | fun_decls  { $$ = $1; amb++;};


fun_decls : fun_decls fun_decl          { $1 -> sig = $2, $$ = $1; }//{ cola($1) -> sig = $2; $$ = $1; }
          | fun_decl                 { $$ = $1; };




fun_decl : FUN IDF PARENI oparams PAREND DOSPUNTOS type opt_decls BEGINI opt_stmts END  {

   SYM *n2 = nuevo_nodo_tabla_f($2, $7); 
   if (buscar_simbolo_f($2) != NULL){
       yyerror("Esta variable ya existe"); 
   } 

   insert_table_node_f(n2); 

  // list_fun_par =  $8;

  $$ = new_tree_node(FUN, $2, $7, 0, 0.0, $4 ,
  new_tree_node(EXEC, $2, $7, 0, 0.0, $8 ,$10,NULL,n2),NULL,n2); }

   |FUN IDF PARENI oparams PAREND DOSPUNTOS type PCOMA{
         
   SYM *n2 = nuevo_nodo_tabla_f($2, $7); 
   if (buscar_simbolo_f($2) != NULL){
       yyerror("Esta variable ya existe"); 
   } 

   insert_table_node_f(n2); 
    //  assign_type_f(n2, $7);
    $$ = new_tree_node(FUN, $2, $7, 0, 0.0, $4 ,NULL, NULL,n2);

   };

oparams: {$$ = NULL;} 
   | params {$$ = $1;};


params: 
         param COMA params { $1 -> sig = $3, $$ = $1; } //{cola($1) -> sig = $3; $$ = $1;}
         |param{$$ = $1;};

param: IDF DOSPUNTOS type {

      SYM *n4 = nuevo_nodo_tabla_fpar($1, $3); 
      if (buscar_simbolo_fpar($1) != NULL){ 
         yyerror("Esta variable ya existe"); 
      } 
      insert_table_node_fpar(n4); 
     // assign_type_fpar(n4, $7);

      $$ = new_tree_node(PARS, $1, $3, 0, 0.0, NULL ,NULL, NULL,n4);

};




stmt :  IDF ASSIGN expr

      { 
      
      SYM * n = NULL;
         if (amb == 0){
         n = buscar_simbolo_fpar($1); 
         
      }else{
            n = buscar_simbolo($1); 
      }
      
      if (n == NULL) { 
         yyerror("Variable no declarada"); 
      } if (n -> value_type != revision_tipos($3)) { 
         yyerror("Tipos incompatibles"); 
      } 
      $$ = new_tree_node(PYC, ";", '0', 0, 0.0, new_tree_node(ASSIGN, "assign", '0', 0, 0.0, new_tree_node(VAR, $1, '0', 0, 0.0, NULL, NULL, NULL,n), $3, NULL,NULL), NULL, NULL,NULL); }

     | IF expresion THEN stmt                                      { $$ = new_tree_node(PYC, ";", '0', 0, 0.0, new_tree_node(IF, "if", '0', 0, 0.0, $2, $4, NULL,NULL), NULL, NULL,NULL); }
     | IF expresion THEN stmt ELSE stmt                            { $$ = new_tree_node(PYC, ";", '0', 0, 0.0, new_tree_node(IF, "if", '0', 0, 0.0, $2, $4, $6,NULL), NULL, NULL,NULL); }
     | WHILE PARENI expresion PAREND stmt                          { $$ = new_tree_node(PYC, ";", '0', 0, 0.0, new_tree_node(WHILE, "while", '0', 0, 0.0, $3,$5,NULL,NULL), NULL, NULL,NULL); }
     | REPEAT stmt UNTIL PARENI expresion PAREND                   { $$ = new_tree_node(PYC, ";", '0', 0, 0.0, new_tree_node(REPEAT, "repeat", '0', 0, 0.0,  $5, $2,NULL ,NULL), NULL, NULL,NULL); }

           | FOR IDF ASSIGN expr UNTIL expr STEP expr DO stmt
           
           { SYM * n = NULL;
         
           if (amb == 0){n = buscar_simbolo_fpar($2); }else{n = buscar_simbolo($2); }
           if (n == NULL) { 
           yyerror("Variable no declarada"); 
           } 
           if (n -> value_type != revision_tipos($4) || n -> value_type != revision_tipos($6) || n -> value_type != revision_tipos($8)) {
            yyerror("Tipos incompatibles"); 
           } 

            $$ = new_tree_node(PYC, ";", '0', 0, 0.0, 
            new_tree_node(FOR, "for", '0', 0, 0.0,
            
            new_tree_node(PYC, ";", '0', 0, 0.0, new_tree_node(ASSIGN, "assign", '0', 0, 0.0, new_tree_node(VAR, $2, '0', 0, 0.0, NULL, NULL, NULL,n), $4, $6,NULL), NULL, NULL,NULL),$8,$10,NULL),NULL,NULL,NULL);
           
           }
           

     | READ IDF                                            {   SYM * n = NULL;          if (amb == 0){n = buscar_simbolo_fpar($2); }else{n = buscar_simbolo($2); }if (n == NULL) { yyerror("Variable no declarada"); } $$ = new_tree_node(PYC, ";", '0', 0, 0.0, new_tree_node(READ, "read", '0', 0, 0.0, new_tree_node(VAR, $2, '0', 0, 0.0, NULL, NULL, NULL,n), NULL, NULL,NULL), NULL, NULL,NULL); }
     | PRINT expr                                          { $$ = new_tree_node(PYC, ";", '0', 0, 0.0, new_tree_node(PRINT, "print", '0', 0, 0.0, $2, NULL, NULL,NULL), NULL, NULL,NULL); }
     | RETRN expr                                          { char c = expr_value_type($2); $$ = new_tree_node(RETRN, "return", c, 0, 0.0, $2, NULL, NULL,NULL); }
     | BEGINI opt_stmts END                                { $$ = $2; }
;

opt_stmts : //palabra vacia
                                    { $$ = NULL; }
          | stmt_lst                                           { $$ = $1; }
;

stmt_lst : stmt                                                { $$ = $1; }
         | stmt PCOMA stmt_lst                                 { $1 -> sig = $3, $$ = $1; }
;

expr : expr SUMA term                                          { char c1 = revision_tipos($1); if (c1 != revision_tipos($3)) { yyerror("Tipos incompatibles"); } $$ = new_tree_node(SUMA, "+", c1, 0, 0.0, $1, $3, NULL,NULL); }
     | expr RESTA term                                         { char c1 = revision_tipos($1); if (c1 != revision_tipos($3)) { yyerror("Tipos incompatibles"); } $$ = new_tree_node(RESTA, "-", c1, 0, 0.0, $1, $3, NULL,NULL); }
     | term {$$ = $1;}
;

term : term MULTI factor                                       { char c1 = revision_tipos($1); if (c1 != revision_tipos($3)) { yyerror("Tipos incompatibles"); } $$ = new_tree_node(MULTI, "*", c1, 0, 0.0, $1, $3, NULL,NULL); }
     | term DIVIDE factor                                      { char c1 = revision_tipos($1); if (c1 != revision_tipos($3)) { yyerror("Tipos incompatibles"); } $$ = new_tree_node(DIVIDE, "/", c1, 0, 0.0, $1, $3, NULL,NULL); }
     | factor       {$$ = $1;}
;

factor : PARENI expr PAREND                                    { $$ = $2; }
       | IDF                                               {  SYM * n = NULL; if (amb == 0){n = buscar_simbolo_fpar($1); }else{n = buscar_simbolo($1); }  if (n == NULL) { yyerror("Variable no declarada."); } $$ = new_tree_node(VAR, $1, '0', 0, 0.0, NULL, NULL, NULL,n); }
       | NINT                                                  { $$ = new_tree_node(CONS, "int", 'i', $1, 0, NULL, NULL, NULL, NULL); }
       | NFLOAT                                                  { $$ = new_tree_node(CONS, "float", 'f', 0, $1, NULL, NULL, NULL, NULL); }
       | IDF PARENI opt_exprs PAREND                          {  ASR * n  = search_node_tree(tree_fun, $1);  if (n == NULL) { yyerror("función no declarada."); } 
                                                               $$ = new_tree_node(CALL, $1, '0', 0, 0.0, $3, n, NULL,n -> simb); }

;

opt_exprs: {$$ = NULL;}
| expr_lst {$$ = $1;};


expr_lst: expr COMA expr_lst {$1 -> sig = $3, $$ = $1;}
         | expr {$$ = $1;};

expresion : expr MENORQ expr                                    { char c1 = revision_tipos($1); if (c1 != revision_tipos($3)) { yyerror("Tipos incompatibles"); } $$ = new_tree_node(MENORQ, "<", c1, 0, 0.0, $1, $3, NULL,NULL); }
          | expr MAYORQ expr                                    { char c1 = revision_tipos($1); if (c1 != revision_tipos($3)) { yyerror("Tipos incompatibles"); } $$ = new_tree_node(MAYORQ, ">", c1, 0, 0.0, $1, $3, NULL,NULL); }
          | expr EQUAL expr                                    { char c1 = revision_tipos($1); if (c1 != revision_tipos($3)) { yyerror("Tipos incompatibles"); } $$ = new_tree_node(EQUAL, "=", c1, 0, 0.0, $1, $3, NULL,NULL); }
          | expr MENORIQ expr                                    { char c1 = revision_tipos($1); if (c1 != revision_tipos($3)) { yyerror("Tipos incompatibles"); } $$ = new_tree_node(MENORIQ, "<=", c1, 0, 0.0, $1, $3, NULL,NULL); }
          | expr MAYORIQ expr                                    { char c1 = revision_tipos($1); if (c1 != revision_tipos($3)) { yyerror("Tipos incompatibles"); } $$ = new_tree_node(MAYORIQ, ">=", c1, 0, 0.0, $1, $3, NULL,NULL); }
;

%%

int yyerror(char const * s)
{
   fprintf(stderr, "Error en la linea %i: %s\n", line, s);
   exit(1);
}

void main(int argc, char *argv[])
{
   yyin = fopen(argv[1], "r");

   tabla_simb();
   
   tabla_simbf();
   
   tabla_simbf_par();
   yyparse();
   check_tree(tree);
   exit(0);
}

// Nuevo nodo de arbol
ASR * new_tree_node(int node_type, unsigned char name[], char value_type, int int_value, float float_value, ASR * izquierda, ASR * derecha, ASR * sig,SYM*simb)
{
   ASR * aux = (ASR *) malloc(sizeof(ASR)); 
   aux -> node_type = node_type;
   strcpy(aux -> name, name);
   aux -> value_type = value_type;
   aux -> int_value = int_value;
   aux -> float_value = float_value;
   aux -> izquierda = izquierda;
   aux -> derecha = derecha;
   aux -> sig = sig;
   aux -> simb = simb;
   return aux;
}

LST * nuevo_nodo_lista(unsigned char name[], int type, LST * sig)
{
   LST * aux = (LST *) malloc(sizeof(LST)); //nodo de tipo lista
   strcpy(aux -> name, name);
   aux -> value_type = type;
   aux -> sig = sig;

   return aux;
}

SYM * nuevo_nodo_tabla(unsigned char name[], int type)
{
   SYM * aux = (SYM *) malloc(sizeof(SYM)); //nodo de simbolo
   strcpy(aux -> name, name);
   aux -> value_type = type;

   return aux;
}



void insert_table_node(SYM *t)
{
   unsigned int i = hash(t -> name);
   if (table[i] == NULL) { table[i] = t; }
   else
   {
      SYM *n = table[i];
      while (n -> sig != NULL) { 
      n = n -> sig; 
      }
      n -> sig = t;
   }
}


/*metodos para funciones*/
//tabla de funciones
SYM * nuevo_nodo_tabla_f(unsigned char name[], int type)
{
   SYM * aux = (SYM *) malloc(sizeof(SYM)); //nodo de simbolo
   strcpy(aux -> name, name);
   aux -> value_type = type;

   return aux;
}



void insert_table_node_f(SYM *t)
{
   unsigned int i = hash(t -> name);
   if (tablef[i] == NULL) { tablef[i] = t; }
   else
   {
      SYM *n = tablef[i];
      while (n -> sig != NULL) { 
      n = n -> sig; 
      }
      n -> sig = t;
   }
}


// busqueda EN SIMBOLOS de funciones
SYM * buscar_simbolo_f(unsigned char name[])
{
   SYM *n = tablef[hash(name)];
   while (n != NULL) 
   {
      if (strcmp(n -> name, name) == 0) { 
      return n; 
      } 
      n = n -> sig;
   }

   return NULL; 
}






/*metodos para parametros de funciones*/
//tabla de parametros de funciones
SYM * nuevo_nodo_tabla_fpar(unsigned char name[], int type)
{
   SYM * aux = (SYM *) malloc(sizeof(SYM)); //nodo de simbolo
   strcpy(aux -> name, name);
   aux -> value_type = type;

   return aux;
}



void insert_table_node_fpar(SYM *t)
{
   unsigned int i = hash(t -> name);
   if (tablefpar[i] == NULL) { tablefpar[i] = t; }
   else
   {
      SYM *n = tablefpar[i];
      while (n -> sig != NULL) { 
      n = n -> sig; 
      }
      n -> sig = t;
   }
}


// busqueda EN SIMBOLOS de funciones
SYM * buscar_simbolo_fpar(unsigned char name[])
{
   SYM *n = tablefpar[hash(name)];
   while (n != NULL) 
   {
      if (strcmp(n -> name, name) == 0) { 
      return n; 
      } 
      n = n -> sig;
   }

   return NULL; 
}






// elemento cola en lista
LST * cola(LST * head)
{
   LST *n = head;
   while (n -> sig != NULL) { n = n -> sig; } 

   return n; 
}



// busqueda
SYM * buscar_simbolo(unsigned char name[])
{
   SYM *n = table[hash(name)];
   while (n != NULL) 
   {
      if (strcmp(n -> name, name) == 0) { 
      return n; 
      } 
      n = n -> sig;
   }

   return NULL; 
}



// Revision de tipos
char revision_tipos(ASR * root)
{
   ASR *n = root;
   if (n -> node_type == CONS) {
      return n -> value_type; // Si es un numero constante
   }
   else if (n -> node_type == CALL) { 
   return n -> simb -> value_type;
      } // llamada a función


   else if (n -> node_type == VAR) { 
      return n -> simb -> value_type;
      
     // buscar_simbolo(n -> name) -> value_type; 
   } // Variable
   char a = revision_tipos(n -> izquierda); 
   char b = revision_tipos(n -> derecha); 
   if (a == b) { return a; } 
   else { yyerror("Tipos incompatibles"); } 
}

void imprimir_sym()
{
   for (int i = 0; i < N; i++) // Iterate array
   {
      SYM *n = tablefpar[i];
      while (n != NULL) // Iterate list
      {
         printf("nombre: %s,tipo: %c,int:%i, float:%f\n", n -> name, n -> value_type, n -> int_value, n -> float_value); // Content
         n = n-> sig;
      }
   }
}
void tabla_simb()
{
    for (int i = 0; i < N; i++) { table[i] = NULL; } // Iterate array
}
void tabla_simbf()
{
    for (int i = 0; i < N; i++) { tablef[i] = NULL; } // Iterate array
}

void tabla_simbf_par()
{
    for (int i = 0; i < N; i++) { tablefpar[i] = NULL; } // Iterate array
}
unsigned int hash(unsigned char w[])
{

    unsigned int hash = 0;
    int c;
    while ((c = *w++)) { hash = c + (hash << 6) + (hash << 16) - hash; }

    return hash % N;
}




ASR * search_node_tree(ASR * root, unsigned char name[]){
   
   ASR *n = root;
   while (n != NULL) 
   {
      if (strcmp(n -> name, name) == 0) { 
      return n; 
      } 
      n = n -> sig;
   }
   return NULL; 
}









//Execute tree nodes actions

void check_tree(ASR * root)
{
   ASR *parent = root; // ; node

   // NULL
   if (parent == NULL || parent -> node_type  == RETRN) { return; }

   // Bloque punto y coma
   if (parent -> node_type == PYC) 
   {
      ASR *n = parent -> izquierda; //nodo por izquierda

      // tipo asignacion
      if (n -> node_type == ASSIGN)
      {
        // SYM *t = buscar_simbolo(n -> izquierda -> name); // nombre de la variable en la tabla de simbolos, se busca pro nombre
         SYM *t = n -> izquierda -> simb;
         if (t -> value_type == 'i') { t -> int_value = expr_int_value(n -> derecha); } // Int value
         else { t -> float_value = expr_float_value(n -> derecha); } // Float value
      }

      // IF-else
      if (n -> node_type == IF)
      {
         char * op = n -> izquierda -> name; // =, > or <
         if (expr_value_type(n -> izquierda) == 'i') // Int type
         {
            int l_expr = expr_int_value(n -> izquierda -> izquierda); // izquierda expr
            int r_expr = expr_int_value(n -> izquierda -> derecha); // derecha expr
            if (strcmp(op, "=") == 0) { if (l_expr == r_expr) { check_tree(n -> derecha); } else { check_tree(n -> sig); } } // =
            else if (strcmp(op, ">") == 0) { if (l_expr > r_expr) { check_tree(n -> derecha); } else { check_tree(n -> sig); } } // >
            else if (strcmp(op, "<") == 0) { if (l_expr < r_expr) { check_tree(n -> derecha); } else { check_tree(n -> sig); } } // <
            else if (strcmp(op, "<=") == 0) { if (l_expr <= r_expr) { check_tree(n -> derecha); } else { check_tree(n -> sig); } } // <=
            else if (strcmp(op, ">=") == 0) { if (l_expr >= r_expr) { check_tree(n -> derecha); } else { check_tree(n -> sig); } } // >=
         }
         else // Float type
         {
            float l_expr = expr_float_value(n -> izquierda -> izquierda); // izquierda expr
            float r_expr = expr_float_value(n -> izquierda -> derecha); // derecha expr
            if (strcmp(op, "=") == 0) { if (l_expr == r_expr) { check_tree(n -> derecha); } else { check_tree(n -> sig); } } // =
            else if (strcmp(op, ">") == 0) { if (l_expr > r_expr) { check_tree(n -> derecha); } else { check_tree(n -> sig); } } // >
            else if (strcmp(op, "<") == 0) { if (l_expr < r_expr) { check_tree(n -> derecha); } else { check_tree(n -> sig); } } // <
           else if (strcmp(op, "<=") == 0) { if (l_expr <= r_expr) { check_tree(n -> derecha); } else { check_tree(n -> sig); } } // <=
            else if (strcmp(op, ">=") == 0) { if (l_expr >= r_expr) { check_tree(n -> derecha); } else { check_tree(n -> sig); } } // >=
         
         }
      }


      //WHILE
      if (n -> node_type == WHILE)
      {
         char * op = n -> izquierda -> name; 
         if (expr_value_type(n -> izquierda) == 'i') // Int type
         {
            int l_expr = expr_int_value(n -> izquierda -> izquierda); // izquierda expr
            int r_expr = expr_int_value(n -> izquierda -> derecha); // derecha expr
            if (strcmp(op, "=") == 0) // =
            {
               while (l_expr == r_expr){
                  check_tree(n -> derecha); 
                  l_expr = expr_int_value(n -> izquierda -> izquierda); 
                  r_expr = expr_int_value(n -> izquierda -> derecha);
               }
            }
            else if (strcmp(op, ">") == 0) // >
            {

               while (l_expr > r_expr){
                  check_tree(n -> derecha); 
                  l_expr = expr_int_value(n -> izquierda -> izquierda); 
                  r_expr = expr_int_value(n -> izquierda -> derecha);
               }
        
            }
            else if (strcmp(op, "<") == 0) // <
            {
               while (l_expr < r_expr){
                  check_tree(n -> derecha); 
                  l_expr = expr_int_value(n -> izquierda -> izquierda); 
                  r_expr = expr_int_value(n -> izquierda -> derecha);
               }
            }
            else if (strcmp(op, "<=") == 0) // <
            {
               while (l_expr <= r_expr){
                  check_tree(n -> derecha); 
                  l_expr = expr_int_value(n -> izquierda -> izquierda); 
                  r_expr = expr_int_value(n -> izquierda -> derecha);
               }
            }
            else if (strcmp(op, ">=") == 0) // <
            {
               while (l_expr >= r_expr){
                  check_tree(n -> derecha); 
                  l_expr = expr_int_value(n -> izquierda -> izquierda); 
                  r_expr = expr_int_value(n -> izquierda -> derecha);
               }
            }
         }
         else // Float type
         {
            float l_expr = expr_float_value(n -> izquierda -> izquierda); // izquierda expr
            float r_expr = expr_float_value(n -> izquierda -> derecha); // derecha expr
            if (strcmp(op, "=") == 0) // =
            {
               while (l_expr == r_expr){
                  check_tree(n -> derecha); 
                  l_expr = expr_float_value(n -> izquierda -> izquierda); 
                  r_expr = expr_float_value(n -> izquierda -> derecha);
               }
            }
            else if (strcmp(op, ">") == 0) // >
            {

               while (l_expr > r_expr){
                  check_tree(n -> derecha); 
                  l_expr = expr_float_value(n -> izquierda -> izquierda); 
                  r_expr = expr_float_value(n -> izquierda -> derecha);
               }
        
            }
            else if (strcmp(op, "<") == 0) // <
            {
               while (l_expr < r_expr){
                  check_tree(n -> derecha); 
                  l_expr = expr_float_value(n -> izquierda -> izquierda); 
                  r_expr = expr_float_value(n -> izquierda -> derecha);
               }
            }
            else if (strcmp(op, "<=") == 0) // <
            {
               while (l_expr <= r_expr){
                  check_tree(n -> derecha); 
                  l_expr = expr_float_value(n -> izquierda -> izquierda); 
                  r_expr = expr_float_value(n -> izquierda -> derecha);
               }
            }
            else if (strcmp(op, ">=") == 0) // <
            {
               while (l_expr >= r_expr){
                  check_tree(n -> derecha); 
                  l_expr = expr_float_value(n -> izquierda -> izquierda); 
                  r_expr = expr_float_value(n -> izquierda -> derecha);
               }
            }
         }
      }

      // REPEAT UNTIL
      if (n -> node_type == REPEAT)
      {
         char * op = n -> izquierda -> name; // =, > or <
         if (expr_value_type(n -> izquierda) == 'i') // Int type
         {
            int l_expr = expr_int_value(n -> izquierda -> izquierda); // izquierda expr
            int r_expr = expr_int_value(n -> izquierda -> derecha); // derecha expr
            if (strcmp(op, "=") == 0) // =
            {
               do{
                  check_tree(n -> derecha); 
                  l_expr = expr_int_value(n -> izquierda -> izquierda); 
                  r_expr = expr_int_value(n -> izquierda -> derecha);
               }while (l_expr == r_expr);
            }
            else if (strcmp(op, ">") == 0) // >
            {

                do{
                  check_tree(n -> derecha); 
                  l_expr = expr_int_value(n -> izquierda -> izquierda); 
                  r_expr = expr_int_value(n -> izquierda -> derecha);
               }while (l_expr > r_expr);
        
            }
            else if (strcmp(op, "<") == 0) // <
            {
                do{
                  check_tree(n -> derecha); 
                  l_expr = expr_int_value(n -> izquierda -> izquierda); 
                  r_expr = expr_int_value(n -> izquierda -> derecha);
               }while (l_expr < r_expr);
            }
            else if (strcmp(op, "<=") == 0) // <
            {
                do{
                  check_tree(n -> derecha); 
                  l_expr = expr_int_value(n -> izquierda -> izquierda); 
                  r_expr = expr_int_value(n -> izquierda -> derecha);
               }while (l_expr <= r_expr);
            }
            else if (strcmp(op, ">=") == 0) // <
            {
                do{
                  check_tree(n -> derecha); 
                  l_expr = expr_int_value(n -> izquierda -> izquierda); 
                  r_expr = expr_int_value(n -> izquierda -> derecha);
               }while (l_expr >= r_expr);
            }
         }
         else // Float type
         {
            float l_expr = expr_float_value(n -> izquierda -> izquierda); // izquierda expr
            float r_expr = expr_float_value(n -> izquierda -> derecha); // derecha expr
            if (strcmp(op, "=") == 0) // =
            {
                do{
                  check_tree(n -> derecha); 
                  l_expr = expr_float_value(n -> izquierda -> izquierda); 
                  r_expr = expr_float_value(n -> izquierda -> derecha);
               }while (l_expr == r_expr);
            }
            else if (strcmp(op, ">") == 0) // >
            {

                do{
                  check_tree(n -> derecha); 
                  l_expr = expr_float_value(n -> izquierda -> izquierda); 
                  r_expr = expr_float_value(n -> izquierda -> derecha);
               }while (l_expr > r_expr);
        
            }
            else if (strcmp(op, "<") == 0) // <
            {
                do{
                  check_tree(n -> derecha); 
                  l_expr = expr_float_value(n -> izquierda -> izquierda); 
                  r_expr = expr_float_value(n -> izquierda -> derecha);
               }while (l_expr < r_expr);
            }
            else if (strcmp(op, "<=") == 0) // <
            {
               do{
                  check_tree(n -> derecha); 
                  l_expr = expr_float_value(n -> izquierda -> izquierda); 
                  r_expr = expr_float_value(n -> izquierda -> derecha);
               }while (l_expr <= r_expr);
            }
            else if (strcmp(op, ">=") == 0) // <
            {
                do{
                  check_tree(n -> derecha); 
                  l_expr = expr_float_value(n -> izquierda -> izquierda); 
                  r_expr = expr_float_value(n -> izquierda -> derecha);
               }while (l_expr >= r_expr);
            }
         }
      }










      // FOR 
      if (n -> node_type == FOR){

         check_tree(n -> izquierda);
         if (expr_value_type(n -> izquierda -> izquierda -> izquierda) == 'i') // Int type
         {
               for (int i = expr_int_value(n -> izquierda -> izquierda-> izquierda); i <= expr_int_value(n -> izquierda -> izquierda -> sig); i = i + expr_int_value(n -> derecha) )
                     {
                             check_tree(n -> sig); 
                     }
         }
         else{
                  for (float j = expr_float_value(n -> izquierda -> izquierda-> izquierda); j <= expr_float_value(n -> izquierda -> izquierda -> sig); j = j + expr_float_value(n -> derecha) )
                     {
                             check_tree(n -> sig); 
                     }  
         }
      }



      // READ
      if (n -> node_type == READ)
      {
         SYM *t = n -> izquierda -> simb; //buscar_simbolo(n -> izquierda -> name); // Get variable from the symbol table
         if (expr_value_type(n -> izquierda) == 'i') { scanf("%i", &(t -> int_value)); } // Int type
         else { scanf("%f", &(t -> float_value)); } // Float type
      }

      // PRINT
      if (n -> node_type == PRINT)
      {
         if (expr_value_type(n -> izquierda) == 'i') { printf("%i\n", expr_int_value(n -> izquierda)); } // Int type
         else { printf("%f\n", expr_float_value(n -> izquierda)); } // Float type
      }
   }
   

   


   check_tree(parent -> sig);
}

// Return int result of expr
int expr_int_value(ASR * root)
{
   int aux1, aux2;
   if (root == NULL) return 0;
   if (root -> node_type == SUMA || root -> node_type == RESTA || root -> node_type == MULTI || root -> node_type == DIVIDE)
   {
      aux1 = expr_int_value(root -> izquierda); // izquierda expr
      aux2 = expr_int_value(root -> derecha); // derecha expr
      if (root -> node_type == SUMA) { return aux1 + aux2; } // +
      if (root -> node_type == RESTA) { return aux1 - aux2; } // -
      if (root -> node_type == MULTI) { return aux1 * aux2; } // *
      if (root -> node_type == DIVIDE) { return aux1 / aux2; } // /
   }
   else if (root -> node_type == CONS) { return root -> int_value; } // Constant
   else if (root -> node_type == VAR) { return root -> simb -> int_value;}//buscar_simbolo(root -> name) -> int_value; } // Variable
   else if (root -> node_type == PARS) { return root -> simb -> int_value;} //buscar_simbolo_fpar(root -> name) -> int_value; } // Variable
   else if (root -> node_type == CALL) {
      
      ASR * global_par = root -> izquierda;   

      ASR * aux =  root -> derecha;  
      if(aux -> derecha -> node_type == RETURN){
      check_tree(aux);
      return expr_int_value(aux -> derecha -> derecha);
      }
      else{
         check_tree(aux);
         return 0;
      }

   }
  //   ASR * valor_ret = do_fun_tree(root -> name, aux -> derecha);
      //return aux -> int_value; } // Variable
}


// Return float result of expr

float expr_float_value(ASR * root)
{
   float aux1, aux2;
   if (root == NULL) return 0.0;
   if (root -> node_type == SUMA || root -> node_type == RESTA || root -> node_type == MULTI || root -> node_type == DIVIDE)
   {
      aux1 = expr_float_value(root -> izquierda); // izquierda expr
      aux2 = expr_float_value(root -> derecha); // derecha expr
      if (root -> node_type == SUMA) { return aux1 + aux2; } // +
      if (root -> node_type == RESTA) { return aux1 - aux2; } // -
      if (root -> node_type == MULTI) { return aux1 * aux2; } // *
      if (root -> node_type == DIVIDE) { return aux1 / aux2; } // /
   }
   else if (root -> node_type == CONS) { return root -> float_value; } // Constant
   else if (root -> node_type == VAR) {   return root -> simb -> float_value; }//buscar_simbolo(root -> name) -> float_value; } // Variable
   else if (root -> node_type == PARS) {  return root -> simb -> float_value;}// buscar_simbolo_fpar(root -> name) -> float_value; } // Variable
   else if (root -> node_type == CALL) {
      
      ASR * global_par = root -> izquierda;   

      ASR * aux =  root -> derecha;  
      if(aux -> derecha -> node_type == RETURN){
      check_tree(aux);
      return expr_float_value(aux -> derecha -> derecha);
      }
      else{
         check_tree(aux);
         return 0.0;
      }

   }

}


// Return value type of expr
char expr_value_type(ASR * root)
{
   if (root == NULL) return '0';
   if (root -> node_type == VAR) {  return root -> simb -> value_type;}
   if (root -> node_type == PARS) {  return root -> simb -> value_type;}
   if (root -> node_type == CONS) {  return root -> simb -> value_type;}// buscar_simbolo(root -> name) -> value_type; } // Look at the symbol table for the symbol's value type
   else { return root -> value_type; }
}










