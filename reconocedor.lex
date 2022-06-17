%{

#include<stdlib.h>
#include<math.h>
#include "reconocedor.tab.h"
int line = 1;
%}

LETRA [A-Za-z]
DIGITO [0-9]
INT (-?[1-9][0-9]{0,4})|0 
FLOAT (-?[0-9]{0,8}+"."+[0-9]{0,8})
ID [_$a-zA-Z][_$a-zA-Z0-9]
%%


"end"                        {return END; /* Se encontr� la palabra end */}
"program"                    {return PROGRAM; /* Se encontr� la palabra program */}
"begin"                      {return BEGINI; /* Se encontr� la palabra begin */}
"int"                        {yylval.yytipo = 'i'; return INT; /* Se encontr� la palabra int */}
"float"                      {yylval.yytipo = 'f'; return FLOAT; /* Se encontr� la palabra float */}
"var"                        {return VAR; /* Se encontr� la palabra var */}
"if"                         {return IF; /* Se encontr� la palabra if */}

"then"                       {return THEN;}
"endif"                      {return ENDIF; /* Se encontr� la palabra endif */}
"else"                       {return ELSE; /* Se encontr� la palabra else */}
"for"                      {return FOR; /* Se encontr� la palabra for */}
"step"                      {return STEP; /* Se encontr� la palabra step */}
"do"                      {return DO; /* Se encontr� la palabra step */}
"while"                      {return WHILE; /* Se encontr� la palabra while */}

"repeat"                      {return   REPEAT; /* Se encontr� la palabra repeat */}

"until"                      {return UNTIL; /* Se encontr� la palabra until */}
"read"                       {return READ; /* Se encontr� la palabra read */}
"print"                      {return PRINT; /* Se encontr� la palabra print */}

"fun"                      {return FUN; /* Se encontr� la palabra fun */}


[_$a-zA-Z][_$a-zA-Z0-9]*     {strcpy(yylval.yyid, yytext); return IDF; /* Se encontr� un identificador */}
{FLOAT}             {yylval.yyfloat = atof(yytext); return NFLOAT; /* Se encontr� un flotante */}
{INT}                  {yylval.yyint = atoi(yytext); return NINT; /* Se encontr� un entero */}
"+"                          {return SUMA; /* Se encontr� un s�mbolo de suma */}
"-"                          {return RESTA; /* Se encontr� un s�mbolo de resta */}
"*"                          {return MULTI; /* Se encontr� un s�mbolo de multiplicaci�n */}
"/"                          {return DIVIDE; /* Se encontr� un s�mbolo de divisi�n */}
"("                          {return PARENI; /* Se encontr� un "(" */}
")"                          {return PAREND; /* Se encontr� un ")" */}
"="                          {return EQUAL; /* Se encontr� un "=" */}
"<"                          {return MENORQ; /* Se encontr� un "<" */}
">"                          {return MAYORQ; /* Se encontr� un ">" */}
"<="                          {return MENORIQ; /* Se encontr� un "<" */}
">="                          {return MAYORIQ; /* Se encontr� un ">" */}
";"                          {return PCOMA; /* Se encontr� un ";" */}
":"                          {return DOSPUNTOS; /* Se encontr� un ":" */}
"<-"                           {return ASSIGN;}

[ \t]                        {/* Ignora  espacio o tabulacion */}
[\n]                         {line++; /* para la funcion error*/}
%%
