

%{

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define N 5000 //elementos en la tabla hash

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
};

// Estructura de lista nos permite tener mejor control de sus nodos internos
typedef struct lst LST;
struct lst
{
   unsigned char name[50];
   char value_type;
   LST * sig;
};


// Estructura de los simbolos
typedef struct sym SYM;
struct sym
{
   unsigned char name[50];
   char value_type;
   int int_value;
   float float_value;
   SYM * sig;
};


// Estructura de los simbolos de funciones
typedef struct sfun SFUN;
struct sfun
{
   unsigned char name[50];
   char value_type;
   int int_value;
   float float_value;
   SFUN * sig;
};


extern int yylex();
extern FILE *yyin;
extern int line;
int yyerror(char const * s);

ASR * new_tree_node(int, unsigned char [], char, int, float, ASR *, ASR *, ASR *);


char revision_tipos(ASR *);
void assign_type(LST *, int);
void assign_type_f(LST *, int);
void assign_type_fvar(LST *, int);


void tabla_simb();
void tabla_simbf();
void tabla_simbf_var();
unsigned int hash(unsigned char []);


LST * nuevo_nodo_lista(unsigned char [], int, LST *);
LST * cola(LST *);

SYM * nuevo_nodo_tabla(unsigned char [], int);
SYM * buscar_simbolo(unsigned char []);
void insert_table_node(SYM *);


SFUN * nuevo_nodo_tabla_f(unsigned char [], int);
SFUN * buscar_simbolo_f(unsigned char []);
void insert_table_node_f(SFUN *);


SFUN * nuevo_nodo_tabla_fvar(unsigned char [], int);
SFUN * buscar_simbolo_fvar(unsigned char []);
void insert_table_node_fvar(SFUN *);

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
LST *list = NULL;

LST *list_fun = NULL; // lista de id de funciones
ASR * tree_fun = NULL;  //arbol de funcionalidades de funciones

LST *list_fun_var = NULL; // lista de variables locales de funciones



SYM *table[N]; // tabla hash de simbolos globales
SFUN *tablef[N]; // tabla hash de funciones
SFUN *tablefvar[N]; // tabla hash de funciones

%}

%union{
   struct asr * yynodo;
   struct lst * yylista;
   unsigned char yyid[50];
   int yyint;
   float yyfloat;
   char yytipo;
}

%token END PROGRAM BEGINI IF ENDIF ELSE FOR STEP DO WHILE READ PRINT SUMA RESTA MULTI DIVIDE PARENI PAREND EQUAL MENORQ MAYORQ MENORIQ MAYORIQ PCOMA DOSPUNTOS COMA OTRO INT FLOAT CONS VAR PYC REPEAT UNTIL ASSIGN THEN FUN CALL
%precedence THEN
%precedence ELSE
%token<yyint> NINT
%token<yyfloat> NFLOAT
%token<yyid> IDF
%type <yytipo> type
%type <yynodo> stmt stmt_lst expr term factor expresion opt_stmts  opt_exprs expr_lst         
%type <yylista> opt_decls decl_lst decl     oparams params param         opt_fun_decls fun_decls fun_decl
%start prog

%%

prog : PROGRAM IDF opt_decls opt_fun_decls BEGINI opt_stmts END { list = $3; tree = $6; list_fun = $4;  } 
;

opt_decls : //palabra vacia
                           { $$ = NULL; }
          | decl_lst                                           { $$ = $1; }
;

decl_lst : decl PCOMA decl_lst                                 { cola($1) -> sig = $3; $$ = $1; }
         | decl                                                { $$ = $1; }
;

decl : VAR IDF DOSPUNTOS type     {

      LST *n = nuevo_nodo_lista($2, $4, NULL); 

      SYM *n2 = nuevo_nodo_tabla($2, $4); 
      if (buscar_simbolo($2) != NULL){ 
         yyerror("Esta variable ya existe"); 
      } 
      insert_table_node(n2); 
      assign_type(n, $4); $$ = n;
}

;

type : INT                                                 { $$ = 'i'; }
     | FLOAT                                               { $$ = 'f'; }
;



//declaracion de funciones
opt_fun_decls: { $$ = NULL; }//palabra vacía  
               | fun_decls  { $$ = $1; };


fun_decls : fun_decl fun_decl        { cola($1) -> sig = $2; $$ = $1; }
          | fun_decl                 { $$ = $1; };




fun_decl : FUN IDF PARENI oparams PAREND DOSPUNTOS type opt_decls BEGINI opt_stmts END  {
   
   list_fun_var = $4;
   tree_fun = $10;

   LST *v = nuevo_nodo_lista($2, $7, NULL); 

   SFUN *n2 = nuevo_nodo_tabla_f($2, $7); 
   if (buscar_simbolo_f($2) != NULL){
       yyerror("Esta variable ya existe"); 
   } 

   insert_table_node_f(n2); 
   assign_type_f(v, $7);
   $$ = v;

   }
   |FUN IDF PARENI oparams PAREND DOSPUNTOS type PCOMA{
         
         list_fun_var = $4;

         LST *v = nuevo_nodo_lista($2, $7, NULL); 

         SFUN *n2 = nuevo_nodo_tabla_f($2, $7); 
         if (buscar_simbolo_f($2) != NULL){
            yyerror("Esta variable ya existe"); 
         } 
         insert_table_node_f(n2); 
         assign_type_f(v, $7);
         $$ = v;



   };

oparams: {$$ = NULL;} 
   | params {$$ = $1;};


params: 
         param COMA params {cola($1) -> sig = $3; $$ = $1;}
         |param{$$ = $1;};

param: IDF DOSPUNTOS type {

      
      LST *n3 = nuevo_nodo_lista($1, $3, NULL); 

      SFUN *n4 = nuevo_nodo_tabla_fvar($1, $3); 
      if (buscar_simbolo_fvar($1) != NULL){ 
         yyerror("Esta variable ya existe"); 
      } 
      insert_table_node_fvar(n4); 
      assign_type_fvar(n3, $3); 
      $$ = n3;


};




stmt :  IDF ASSIGN expr

    { 
      SYM *n = buscar_simbolo($1); 
      if (n == NULL) { 
         yyerror("Variable no declarada"); 
      } if (n -> value_type != revision_tipos($3)) { 
         yyerror("Tipos incompatibles"); 
      } 
      $$ = new_tree_node(PYC, ";", '0', 0, 0.0, new_tree_node(ASSIGN, "assign", '0', 0, 0.0, new_tree_node(VAR, $1, '0', 0, 0.0, NULL, NULL, NULL), $3, NULL), NULL, NULL); }

     | IF expresion THEN stmt                    { $$ = new_tree_node(PYC, ";", '0', 0, 0.0, new_tree_node(IF, "if", '0', 0, 0.0, $2, $4, NULL), NULL, NULL); }

     | IF expresion THEN stmt ELSE stmt          { $$ = new_tree_node(PYC, ";", '0', 0, 0.0, new_tree_node(IF, "if", '0', 0, 0.0, $2, $4, $6), NULL, NULL); }

     | WHILE PARENI expresion PAREND stmt              { $$ = new_tree_node(PYC, ";", '0', 0, 0.0, new_tree_node(WHILE, "while", '0', 0, 0.0, $5,NULL,$3), NULL, NULL); }
     | REPEAT stmt UNTIL PARENI expresion PAREND                   { $$ = new_tree_node(PYC, ";", '0', 0, 0.0, new_tree_node(REPEAT, "repeat", '0', 0, 0.0, $2, NULL,  $5), NULL, NULL); }

           | FOR IDF ASSIGN expr UNTIL expr STEP expr DO stmt
           
           {SYM *n = buscar_simbolo($2); 
           if (n == NULL) { 
           yyerror("Variable no declarada"); 
           } 
           if (n -> value_type != revision_tipos($4)) {
            yyerror("Tipos incompatibles"); 
           } 
/*
            $$ = new_tree_node(PYC, ";", '0', 0, 0.0, 
            new_tree_node(FOR, "for", '0', 0, 0.0, 
            new_tree_node(ASSIGN, "assign", '0', 0, 0.0, new_tree_node(VAR, $2, '0', 0, 0.0, NULL, NULL, NULL), $3, NULL), 
            new_tree_node(ASSIGN, "assign", '0', 0, 0.0, new_tree_node(VAR, $2, '0', 0, 0.0, NULL, NULL, NULL), $3, NULL), 
            
            
            , NULL,  $5),
            NULL,NULL);

           $$ = new_tree_node(PYC, ";", '0', 0, 0.0, 
             new_tree_node(ASSIGN, "assign", '0', 0, 0.0, new_tree_node(VAR, $1, '0', 0, 0.0, NULL, NULL, NULL), $3, NULL), 


          new_tree_node(ASSIGN, "assign", '0', 0, 0.0, new_tree_node(VAR, $1, '0', 0, 0.0, NULL, NULL, NULL), $3, NULL), 
           
           new_tree_node(STEP,"step", '0', 0, 0.0, $6, $8, NULL), NULL); */
           }
           

     | READ IDF                                            { SYM *n = buscar_simbolo($2); if (n == NULL) { yyerror("Variable no declarada"); } $$ = new_tree_node(PYC, ";", '0', 0, 0.0, new_tree_node(READ, "read", '0', 0, 0.0, new_tree_node(VAR, $2, '0', 0, 0.0, NULL, NULL, NULL), NULL, NULL), NULL, NULL); }
     | PRINT expr                                              { $$ = new_tree_node(PYC, ";", '0', 0, 0.0, new_tree_node(PRINT, "print", '0', 0, 0.0, $2, NULL, NULL), NULL, NULL); }
     | BEGINI opt_stmts END                                      { $$ = $2; }
;

opt_stmts : //palabra vacia
                                    { $$ = NULL; }
          | stmt_lst                                           { $$ = $1; }
;

stmt_lst : stmt                                                { $$ = $1; }
         | stmt PCOMA stmt_lst                                 { $1 -> sig = $3, $$ = $1; }
;

expr : expr SUMA term                                          { char c1 = revision_tipos($1); if (c1 != revision_tipos($3)) { yyerror("Tipos incompatibles"); } $$ = new_tree_node(SUMA, "+", c1, 0, 0.0, $1, $3, NULL); }
     | expr RESTA term                                         { char c1 = revision_tipos($1); if (c1 != revision_tipos($3)) { yyerror("Tipos incompatibles"); } $$ = new_tree_node(RESTA, "-", c1, 0, 0.0, $1, $3, NULL); }
     | term {$$ = $1;}
;

term : term MULTI factor                                       { char c1 = revision_tipos($1); if (c1 != revision_tipos($3)) { yyerror("Tipos incompatibles"); } $$ = new_tree_node(MULTI, "*", c1, 0, 0.0, $1, $3, NULL); }
     | term DIVIDE factor                                      { char c1 = revision_tipos($1); if (c1 != revision_tipos($3)) { yyerror("Tipos incompatibles"); } $$ = new_tree_node(DIVIDE, "/", c1, 0, 0.0, $1, $3, NULL); }
     | factor       {$$ = $1;}
;

factor : PARENI expr PAREND                                    { $$ = $2; }
       | IDF                                               { if (buscar_simbolo($1) == NULL) { yyerror("Variable no declarada."); } $$ = new_tree_node(VAR, $1, '0', 0, 0.0, NULL, NULL, NULL); }
       | NINT                                                  { $$ = new_tree_node(CONS, "int", 'i', $1, 0, NULL, NULL, NULL); }
       | NFLOAT                                                  { $$ = new_tree_node(CONS, "float", 'f', 0, $1, NULL, NULL, NULL); }
       | IDF PAREND opt_exprs PAREND                          { if (buscar_simbolo_f($1) == NULL) { yyerror("Variable no declarada."); } 
                                                               $$ = new_tree_node(CALL, $1, '0', 0, 0.0, $3, NULL, NULL); }

;

opt_exprs: {$$ = NULL;}
| expr_lst {$$ = $1;};


expr_lst: expr COMA expr_lst {$1 -> sig = $3, $$ = $1;}
         | expr {$$ = $1;};

expresion : expr MENORQ expr                                    { char c1 = revision_tipos($1); if (c1 != revision_tipos($3)) { yyerror("Tipos incompatibles"); } $$ = new_tree_node(MENORQ, "<", c1, 0, 0.0, $1, $3, NULL); }
          | expr MAYORQ expr                                    { char c1 = revision_tipos($1); if (c1 != revision_tipos($3)) { yyerror("Tipos incompatibles"); } $$ = new_tree_node(MAYORQ, ">", c1, 0, 0.0, $1, $3, NULL); }
          | expr EQUAL expr                                    { char c1 = revision_tipos($1); if (c1 != revision_tipos($3)) { yyerror("Tipos incompatibles"); } $$ = new_tree_node(EQUAL, "=", c1, 0, 0.0, $1, $3, NULL); }
          | expr MENORIQ expr                                    { char c1 = revision_tipos($1); if (c1 != revision_tipos($3)) { yyerror("Tipos incompatibles"); } $$ = new_tree_node(MENORIQ, "<=", c1, 0, 0.0, $1, $3, NULL); }
          | expr MAYORIQ expr                                    { char c1 = revision_tipos($1); if (c1 != revision_tipos($3)) { yyerror("Tipos incompatibles"); } $$ = new_tree_node(MAYORIQ, ">=", c1, 0, 0.0, $1, $3, NULL); }
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
   
   tabla_simbf_var();
   yyparse();
   check_tree(tree);
   //imprimir_sym();
   exit(0);
}

// Nuevo nodo de arbol
ASR * new_tree_node(int node_type, unsigned char name[], char value_type, int int_value, float float_value, ASR * izquierda, ASR * derecha, ASR * sig)
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


// asignacion de tipo
void assign_type(LST * head, int type)
{
   LST *n = head;
   while (n != NULL) 
   {
      SYM *t = buscar_simbolo(n -> name);
      t -> value_type = type;
      n = n -> sig;
   }
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
SFUN * nuevo_nodo_tabla_f(unsigned char name[], int type)
{
   SFUN * aux = (SFUN *) malloc(sizeof(SFUN)); //nodo de simbolo
   strcpy(aux -> name, name);
   aux -> value_type = type;

   return aux;
}


// asignacion de tipo en funciones
void assign_type_f(LST * head, int type)
{
   LST *n = head; 
   while (n != NULL) 
   {
      SFUN *t = buscar_simbolo_f(n -> name);
      t -> value_type = type;
      n = n -> sig;
   }
}

void insert_table_node_f(SFUN *t)
{
   unsigned int i = hash(t -> name);
   if (tablef[i] == NULL) { tablef[i] = t; }
   else
   {
      SFUN *n = tablef[i];
      while (n -> sig != NULL) { 
      n = n -> sig; 
      }
      n -> sig = t;
   }
}


// busqueda EN SIMBOLOS de funciones
SFUN * buscar_simbolo_f(unsigned char name[])
{
   SFUN *n = tablef[hash(name)];
   while (n != NULL) 
   {
      if (strcmp(n -> name, name) == 0) { 
      return n; 
      } 
      n = n -> sig;
   }

   return NULL; 
}










/*metodos para variables de funciones*/
//tabla de variables de funciones
SFUN * nuevo_nodo_tabla_fvar(unsigned char name[], int type)
{
   SFUN * aux = (SFUN *) malloc(sizeof(SFUN)); //nodo de simbolo
   strcpy(aux -> name, name);
   aux -> value_type = type;

   return aux;
}


// asignacion de tipo en funciones
void assign_type_fvar(LST * head, int type)
{
   LST *n = head; 
   while (n != NULL) 
   {
      SFUN *t = buscar_simbolo_fvar(n -> name);
      t -> value_type = type;
      n = n -> sig;
   }
}

void insert_table_node_fvar(SFUN *t)
{
   unsigned int i = hash(t -> name);
   if (tablefvar[i] == NULL) { tablefvar[i] = t; }
   else
   {
      SFUN *n = tablefvar[i];
      while (n -> sig != NULL) { 
      n = n -> sig; 
      }
      n -> sig = t;
   }
}


// busqueda EN SIMBOLOS de var fun
SFUN * buscar_simbolo_fvar(unsigned char name[])
{
   SFUN *n = tablefvar[hash(name)];
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
   else if (n -> node_type == VAR) { return buscar_simbolo(n -> name) -> value_type; } // Variable
   char a = revision_tipos(n -> izquierda); 
   char b = revision_tipos(n -> derecha); 
   if (a == b) { return a; } 
   else { yyerror("Tipos incompatibles"); } 
}

void imprimir_sym()
{
   for (int i = 0; i < N; i++) // Iterate array
   {
      SYM *n = table[i];
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

void tabla_simbf_var()
{
    for (int i = 0; i < N; i++) { tablefvar[i] = NULL; } // Iterate array
}
unsigned int hash(unsigned char w[])
{

    unsigned int hash = 0;
    int c;
    while ((c = *w++)) { hash = c + (hash << 6) + (hash << 16) - hash; }

    return hash % N;
}














//Execute tree nodes actions

void check_tree(ASR * root)
{
   ASR *parent = root; // ; node

   // NULL
   if (parent == NULL) { return; }

   // Bloque punto y coma
   if (parent -> node_type == PYC)
   {
      ASR *n = parent -> izquierda; //nodo por izquierda

      // tipo asignacion
      if (n -> node_type == ASSIGN)
      {
         SYM *t = buscar_simbolo(n -> izquierda -> name); // nombre de la variable en la tabla de simbolos, se busca pro nombre
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
         char * op = n -> sig -> name; // =, > or <
         if (expr_value_type(n -> sig) == 'i') // Int type
         {
            int l_expr = expr_int_value(n -> sig -> izquierda); // izquierda expr
            int r_expr = expr_int_value(n -> sig -> derecha); // derecha expr
            if (strcmp(op, "=") == 0) // =
            {
               while (l_expr == r_expr){
                  check_tree(n -> izquierda); 
                  l_expr = expr_int_value(n -> sig -> izquierda); 
                  r_expr = expr_int_value(n -> sig -> derecha);
               }
            }
            else if (strcmp(op, ">") == 0) // >
            {

               while (l_expr > r_expr){
                  check_tree(n -> izquierda); 
                  l_expr = expr_int_value(n -> sig -> izquierda); 
                  r_expr = expr_int_value(n -> sig -> derecha);
               }
        
            }
            else if (strcmp(op, "<") == 0) // <
            {
               while (l_expr < r_expr){
                  check_tree(n -> izquierda); 
                  l_expr = expr_int_value(n -> sig -> izquierda); 
                  r_expr = expr_int_value(n -> sig -> derecha);
               }
            }
            else if (strcmp(op, "<=") == 0) // <
            {
               while (l_expr <= r_expr){
                  check_tree(n -> izquierda); 
                  l_expr = expr_int_value(n -> sig -> izquierda); 
                  r_expr = expr_int_value(n -> sig -> derecha);
               }
            }
            else if (strcmp(op, ">=") == 0) // <
            {
               while (l_expr >= r_expr){
                  check_tree(n -> izquierda); 
                  l_expr = expr_int_value(n -> sig -> izquierda); 
                  r_expr = expr_int_value(n -> sig -> derecha);
               }
            }
         }
         else // Float type
         {
            float l_expr = expr_float_value(n -> sig -> izquierda); // izquierda expr
            float r_expr = expr_float_value(n -> sig -> derecha); // derecha expr
            if (strcmp(op, "=") == 0) // =
            {
               while (l_expr == r_expr){
                  check_tree(n -> izquierda); 
                  l_expr = expr_float_value(n -> sig -> izquierda); 
                  r_expr = expr_float_value(n -> sig -> derecha);
               }
            }
            else if (strcmp(op, ">") == 0) // >
            {

               while (l_expr > r_expr){
                  check_tree(n -> izquierda); 
                  l_expr = expr_float_value(n -> sig -> izquierda); 
                  r_expr = expr_float_value(n -> sig -> derecha);
               }
        
            }
            else if (strcmp(op, "<") == 0) // <
            {
               while (l_expr < r_expr){
                  check_tree(n -> izquierda); 
                  l_expr = expr_float_value(n -> sig -> izquierda); 
                  r_expr = expr_float_value(n -> sig -> derecha);
               }
            }
            else if (strcmp(op, "<=") == 0) // <
            {
               while (l_expr <= r_expr){
                  check_tree(n -> izquierda); 
                  l_expr = expr_float_value(n -> sig -> izquierda); 
                  r_expr = expr_float_value(n -> sig -> derecha);
               }
            }
            else if (strcmp(op, ">=") == 0) // <
            {
               while (l_expr >= r_expr){
                  check_tree(n -> izquierda); 
                  l_expr = expr_float_value(n -> sig -> izquierda); 
                  r_expr = expr_float_value(n -> sig -> derecha);
               }
            }
         }
      }







      // REPEAT UNTIL
      if (n -> node_type == REPEAT)
      {
         char * op = n -> sig -> name; // =, > or <
         if (expr_value_type(n -> sig) == 'i') // Int type
         {
            int l_expr = expr_int_value(n -> sig -> izquierda); // izquierda expr
            int r_expr = expr_int_value(n -> sig -> derecha); // derecha expr
            if (strcmp(op, "=") == 0) // =
            {
               do{
                  check_tree(n -> izquierda); 
                  l_expr = expr_int_value(n -> sig -> izquierda); 
                  r_expr = expr_int_value(n -> sig -> derecha);
               }while (l_expr == r_expr);
            }
            else if (strcmp(op, ">") == 0) // >
            {

                do{
                  check_tree(n -> izquierda); 
                  l_expr = expr_int_value(n -> sig -> izquierda); 
                  r_expr = expr_int_value(n -> sig -> derecha);
               }while (l_expr > r_expr);
        
            }
            else if (strcmp(op, "<") == 0) // <
            {
                do{
                  check_tree(n -> izquierda); 
                  l_expr = expr_int_value(n -> sig -> izquierda); 
                  r_expr = expr_int_value(n -> sig -> derecha);
               }while (l_expr < r_expr);
            }
            else if (strcmp(op, "<=") == 0) // <
            {
                do{
                  check_tree(n -> izquierda); 
                  l_expr = expr_int_value(n -> sig -> izquierda); 
                  r_expr = expr_int_value(n -> sig -> derecha);
               }while (l_expr <= r_expr);
            }
            else if (strcmp(op, ">=") == 0) // <
            {
                do{
                  check_tree(n -> izquierda); 
                  l_expr = expr_int_value(n -> sig -> izquierda); 
                  r_expr = expr_int_value(n -> sig -> derecha);
               }while (l_expr >= r_expr);
            }
         }
         else // Float type
         {
            float l_expr = expr_float_value(n -> sig -> izquierda); // izquierda expr
            float r_expr = expr_float_value(n -> sig -> derecha); // derecha expr
            if (strcmp(op, "=") == 0) // =
            {
                do{
                  check_tree(n -> izquierda); 
                  l_expr = expr_float_value(n -> sig -> izquierda); 
                  r_expr = expr_float_value(n -> sig -> derecha);
               }while (l_expr == r_expr);
            }
            else if (strcmp(op, ">") == 0) // >
            {

                do{
                  check_tree(n -> izquierda); 
                  l_expr = expr_float_value(n -> sig -> izquierda); 
                  r_expr = expr_float_value(n -> sig -> derecha);
               }while (l_expr > r_expr);
        
            }
            else if (strcmp(op, "<") == 0) // <
            {
                do{
                  check_tree(n -> izquierda); 
                  l_expr = expr_float_value(n -> sig -> izquierda); 
                  r_expr = expr_float_value(n -> sig -> derecha);
               }while (l_expr < r_expr);
            }
            else if (strcmp(op, "<=") == 0) // <
            {
               do{
                  check_tree(n -> izquierda); 
                  l_expr = expr_float_value(n -> sig -> izquierda); 
                  r_expr = expr_float_value(n -> sig -> derecha);
               }while (l_expr <= r_expr);
            }
            else if (strcmp(op, ">=") == 0) // <
            {
                do{
                  check_tree(n -> izquierda); 
                  l_expr = expr_float_value(n -> sig -> izquierda); 
                  r_expr = expr_float_value(n -> sig -> derecha);
               }while (l_expr >= r_expr);
            }
         }
      }



      // FOR 
      if (n -> node_type == FOR)
      {
         char * op = n -> sig -> name; // =, > or <
         if (expr_value_type(n -> sig) == 'i') // Int type
         {
            int l_expr = expr_int_value(n -> sig -> izquierda); // izquierda expr
            int r_expr = expr_int_value(n -> sig -> derecha); // derecha expr
            if (strcmp(op, "=") == 0) // =
            {
               do{
                  check_tree(n -> izquierda); 
                  l_expr = expr_int_value(n -> sig -> izquierda); 
                  r_expr = expr_int_value(n -> sig -> derecha);
               }while (l_expr == r_expr);
            }
            else if (strcmp(op, ">") == 0) // >
            {

                do{
                  check_tree(n -> izquierda); 
                  l_expr = expr_int_value(n -> sig -> izquierda); 
                  r_expr = expr_int_value(n -> sig -> derecha);
               }while (l_expr > r_expr);
        
            }
            else if (strcmp(op, "<") == 0) // <
            {
                do{
                  check_tree(n -> izquierda); 
                  l_expr = expr_int_value(n -> sig -> izquierda); 
                  r_expr = expr_int_value(n -> sig -> derecha);
               }while (l_expr < r_expr);
            }
            else if (strcmp(op, "<=") == 0) // <
            {
                do{
                  check_tree(n -> izquierda); 
                  l_expr = expr_int_value(n -> sig -> izquierda); 
                  r_expr = expr_int_value(n -> sig -> derecha);
               }while (l_expr <= r_expr);
            }
            else if (strcmp(op, ">=") == 0) // <
            {
                do{
                  check_tree(n -> izquierda); 
                  l_expr = expr_int_value(n -> sig -> izquierda); 
                  r_expr = expr_int_value(n -> sig -> derecha);
               }while (l_expr >= r_expr);
            }
         }
         else // Float type
         {
            float l_expr = expr_float_value(n -> sig -> izquierda); // izquierda expr
            float r_expr = expr_float_value(n -> sig -> derecha); // derecha expr
            if (strcmp(op, "=") == 0) // =
            {
                do{
                  check_tree(n -> izquierda); 
                  l_expr = expr_float_value(n -> sig -> izquierda); 
                  r_expr = expr_float_value(n -> sig -> derecha);
               }while (l_expr == r_expr);
            }
            else if (strcmp(op, ">") == 0) // >
            {

                do{
                  check_tree(n -> izquierda); 
                  l_expr = expr_float_value(n -> sig -> izquierda); 
                  r_expr = expr_float_value(n -> sig -> derecha);
               }while (l_expr > r_expr);
        
            }
            else if (strcmp(op, "<") == 0) // <
            {
                do{
                  check_tree(n -> izquierda); 
                  l_expr = expr_float_value(n -> sig -> izquierda); 
                  r_expr = expr_float_value(n -> sig -> derecha);
               }while (l_expr < r_expr);
            }
            else if (strcmp(op, "<=") == 0) // <
            {
               do{
                  check_tree(n -> izquierda); 
                  l_expr = expr_float_value(n -> sig -> izquierda); 
                  r_expr = expr_float_value(n -> sig -> derecha);
               }while (l_expr <= r_expr);
            }
            else if (strcmp(op, ">=") == 0) // <
            {
                do{
                  check_tree(n -> izquierda); 
                  l_expr = expr_float_value(n -> sig -> izquierda); 
                  r_expr = expr_float_value(n -> sig -> derecha);
               }while (l_expr >= r_expr);
            }
         }
      }




      // READ
      if (n -> node_type == READ)
      {
         SYM *t = buscar_simbolo(n -> izquierda -> name); // Get variable from the symbol table
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
   else if (root -> node_type == VAR) { return buscar_simbolo(root -> name) -> int_value; } // Variable
   else if (root -> node_type == CALL) { return buscar_simbolo(root -> name) -> int_value; } // Variable
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
   else if (root -> node_type == VAR) { return buscar_simbolo(root -> name) -> float_value; } // Variable
   else if (root -> node_type == CALL) { return buscar_simbolo(root -> name) -> float_value; } // Variable

}


// Return value type of expr
char expr_value_type(ASR * root)
{
   if (root == NULL) return '0';
   if (root -> node_type == VAR) { return buscar_simbolo(root -> name) -> value_type; } // Look at the symbol table for the symbol's value type
   else { return root -> value_type; }
}










