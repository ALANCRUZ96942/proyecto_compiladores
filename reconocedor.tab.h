/* A Bison parser, made by GNU Bison 3.7.5.  */

/* Bison interface for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015, 2018-2021 Free Software Foundation,
   Inc.

   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <http://www.gnu.org/licenses/>.  */

/* As a special exception, you may create a larger work that contains
   part or all of the Bison parser skeleton and distribute that work
   under terms of your choice, so long as that work isn't itself a
   parser generator using the skeleton or a modified version thereof
   as a parser skeleton.  Alternatively, if you modify or redistribute
   the parser skeleton itself, you may (at your option) remove this
   special exception, which will cause the skeleton and the resulting
   Bison output files to be licensed under the GNU General Public
   License without this special exception.

   This special exception was added by the Free Software Foundation in
   version 2.2 of Bison.  */

/* DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
   especially those whose name start with YY_ or yy_.  They are
   private implementation details that can be changed or removed.  */

#ifndef YY_YY_RECONOCEDOR_TAB_H_INCLUDED
# define YY_YY_RECONOCEDOR_TAB_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token kinds.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    YYEMPTY = -2,
    YYEOF = 0,                     /* "end of file"  */
    YYerror = 256,                 /* error  */
    YYUNDEF = 257,                 /* "invalid token"  */
    END = 258,                     /* END  */
    PROGRAM = 259,                 /* PROGRAM  */
    BEGINI = 260,                  /* BEGINI  */
    IF = 261,                      /* IF  */
    ENDIF = 262,                   /* ENDIF  */
    ELSE = 263,                    /* ELSE  */
    FOR = 264,                     /* FOR  */
    STEP = 265,                    /* STEP  */
    DO = 266,                      /* DO  */
    WHILE = 267,                   /* WHILE  */
    READ = 268,                    /* READ  */
    PRINT = 269,                   /* PRINT  */
    SUMA = 270,                    /* SUMA  */
    RESTA = 271,                   /* RESTA  */
    MULTI = 272,                   /* MULTI  */
    DIVIDE = 273,                  /* DIVIDE  */
    PARENI = 274,                  /* PARENI  */
    PAREND = 275,                  /* PAREND  */
    EQUAL = 276,                   /* EQUAL  */
    MENORQ = 277,                  /* MENORQ  */
    MAYORQ = 278,                  /* MAYORQ  */
    MENORIQ = 279,                 /* MENORIQ  */
    MAYORIQ = 280,                 /* MAYORIQ  */
    PCOMA = 281,                   /* PCOMA  */
    DOSPUNTOS = 282,               /* DOSPUNTOS  */
    COMA = 283,                    /* COMA  */
    OTRO = 284,                    /* OTRO  */
    INT = 285,                     /* INT  */
    FLOAT = 286,                   /* FLOAT  */
    CONS = 287,                    /* CONS  */
    VAR = 288,                     /* VAR  */
    PYC = 289,                     /* PYC  */
    REPEAT = 290,                  /* REPEAT  */
    UNTIL = 291,                   /* UNTIL  */
    ASSIGN = 292,                  /* ASSIGN  */
    THEN = 293,                    /* THEN  */
    FUN = 294,                     /* FUN  */
    CALL = 295,                    /* CALL  */
    RETRN = 296,                   /* RETRN  */
    NINT = 297,                    /* NINT  */
    NFLOAT = 298,                  /* NFLOAT  */
    IDF = 299                      /* IDF  */
  };
  typedef enum yytokentype yytoken_kind_t;
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 135 "reconocedor.y"

   struct asr * yynodo;
   struct lst * yylista;
   unsigned char yyid[50];
   int yyint;
   float yyfloat;
   char yytipo;

#line 117 "reconocedor.tab.h"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_RECONOCEDOR_TAB_H_INCLUDED  */
