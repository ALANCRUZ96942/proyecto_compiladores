/* A Bison parser, made by GNU Bison 3.7.5.  */

/* Bison implementation for Yacc-like parsers in C

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

/* C LALR(1) parser skeleton written by Richard Stallman, by
   simplifying the original so-called "semantic" parser.  */

/* DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
   especially those whose name start with YY_ or yy_.  They are
   private implementation details that can be changed or removed.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output, and Bison version.  */
#define YYBISON 30705

/* Bison version string.  */
#define YYBISON_VERSION "3.7.5"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* First part of user prologue.  */
#line 3 "reconocedor.y"


#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define N 5000 //elementos en las tablas hash

int amb = 0; //variable de ambiente 1
int amb2 = 0; //variable de ambiente 2
int retorno = 0;  //variable global de ambiente

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





extern int yylex();
extern FILE *yyin;
extern int line;
int yyerror(char const * s);

ASR * new_tree_node(int, unsigned char [], char, int, float, ASR *, ASR *, ASR *,SYM*);
ASR * search_node_tree(ASR *,unsigned char []);

char revision_tipos(ASR *);


void tabla_simb();
void tabla_simbf();
void tabla_simbf_par();
unsigned int hash(unsigned char []);

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
void print_table();


//inicializacion tabla y lista de simbolos
ASR *tree = NULL; // arbol del programa
ASR * tree_fun = NULL;  //arbol de funciones

ASR *list = NULL; // lista de simbolos
ASR *list_fun = NULL; // lista de id de funciones








SYM *table[N]; // tabla hash de simbolos globales
SYM *tablef[N]; // tabla hash de funciones


SYM *tablefpar[N]; // tabla hash de funciones parametros

void igualar_params(ASR*,ASR*);


#line 180 "reconocedor.tab.c"

# ifndef YY_CAST
#  ifdef __cplusplus
#   define YY_CAST(Type, Val) static_cast<Type> (Val)
#   define YY_REINTERPRET_CAST(Type, Val) reinterpret_cast<Type> (Val)
#  else
#   define YY_CAST(Type, Val) ((Type) (Val))
#   define YY_REINTERPRET_CAST(Type, Val) ((Type) (Val))
#  endif
# endif
# ifndef YY_NULLPTR
#  if defined __cplusplus
#   if 201103L <= __cplusplus
#    define YY_NULLPTR nullptr
#   else
#    define YY_NULLPTR 0
#   endif
#  else
#   define YY_NULLPTR ((void*)0)
#  endif
# endif

#include "reconocedor.tab.h"
/* Symbol kind.  */
enum yysymbol_kind_t
{
  YYSYMBOL_YYEMPTY = -2,
  YYSYMBOL_YYEOF = 0,                      /* "end of file"  */
  YYSYMBOL_YYerror = 1,                    /* error  */
  YYSYMBOL_YYUNDEF = 2,                    /* "invalid token"  */
  YYSYMBOL_END = 3,                        /* END  */
  YYSYMBOL_PROGRAM = 4,                    /* PROGRAM  */
  YYSYMBOL_BEGINI = 5,                     /* BEGINI  */
  YYSYMBOL_IF = 6,                         /* IF  */
  YYSYMBOL_ENDIF = 7,                      /* ENDIF  */
  YYSYMBOL_ELSE = 8,                       /* ELSE  */
  YYSYMBOL_FOR = 9,                        /* FOR  */
  YYSYMBOL_STEP = 10,                      /* STEP  */
  YYSYMBOL_DO = 11,                        /* DO  */
  YYSYMBOL_WHILE = 12,                     /* WHILE  */
  YYSYMBOL_READ = 13,                      /* READ  */
  YYSYMBOL_PRINT = 14,                     /* PRINT  */
  YYSYMBOL_SUMA = 15,                      /* SUMA  */
  YYSYMBOL_RESTA = 16,                     /* RESTA  */
  YYSYMBOL_MULTI = 17,                     /* MULTI  */
  YYSYMBOL_DIVIDE = 18,                    /* DIVIDE  */
  YYSYMBOL_PARENI = 19,                    /* PARENI  */
  YYSYMBOL_PAREND = 20,                    /* PAREND  */
  YYSYMBOL_EQUAL = 21,                     /* EQUAL  */
  YYSYMBOL_MENORQ = 22,                    /* MENORQ  */
  YYSYMBOL_MAYORQ = 23,                    /* MAYORQ  */
  YYSYMBOL_MENORIQ = 24,                   /* MENORIQ  */
  YYSYMBOL_MAYORIQ = 25,                   /* MAYORIQ  */
  YYSYMBOL_PCOMA = 26,                     /* PCOMA  */
  YYSYMBOL_DOSPUNTOS = 27,                 /* DOSPUNTOS  */
  YYSYMBOL_COMA = 28,                      /* COMA  */
  YYSYMBOL_OTRO = 29,                      /* OTRO  */
  YYSYMBOL_INT = 30,                       /* INT  */
  YYSYMBOL_FLOAT = 31,                     /* FLOAT  */
  YYSYMBOL_CONS = 32,                      /* CONS  */
  YYSYMBOL_VAR = 33,                       /* VAR  */
  YYSYMBOL_PYC = 34,                       /* PYC  */
  YYSYMBOL_REPEAT = 35,                    /* REPEAT  */
  YYSYMBOL_UNTIL = 36,                     /* UNTIL  */
  YYSYMBOL_ASSIGN = 37,                    /* ASSIGN  */
  YYSYMBOL_THEN = 38,                      /* THEN  */
  YYSYMBOL_FUN = 39,                       /* FUN  */
  YYSYMBOL_CALL = 40,                      /* CALL  */
  YYSYMBOL_RETRN = 41,                     /* RETRN  */
  YYSYMBOL_PARS = 42,                      /* PARS  */
  YYSYMBOL_EXEC = 43,                      /* EXEC  */
  YYSYMBOL_NINT = 44,                      /* NINT  */
  YYSYMBOL_NFLOAT = 45,                    /* NFLOAT  */
  YYSYMBOL_IDF = 46,                       /* IDF  */
  YYSYMBOL_YYACCEPT = 47,                  /* $accept  */
  YYSYMBOL_prog = 48,                      /* prog  */
  YYSYMBOL_opt_decls = 49,                 /* opt_decls  */
  YYSYMBOL_decl_lst = 50,                  /* decl_lst  */
  YYSYMBOL_decl = 51,                      /* decl  */
  YYSYMBOL_type = 52,                      /* type  */
  YYSYMBOL_opt_fun_decls = 53,             /* opt_fun_decls  */
  YYSYMBOL_fun_decls = 54,                 /* fun_decls  */
  YYSYMBOL_fun_decl = 55,                  /* fun_decl  */
  YYSYMBOL_oparams = 56,                   /* oparams  */
  YYSYMBOL_params = 57,                    /* params  */
  YYSYMBOL_param = 58,                     /* param  */
  YYSYMBOL_stmt = 59,                      /* stmt  */
  YYSYMBOL_opt_stmts = 60,                 /* opt_stmts  */
  YYSYMBOL_stmt_lst = 61,                  /* stmt_lst  */
  YYSYMBOL_expr = 62,                      /* expr  */
  YYSYMBOL_term = 63,                      /* term  */
  YYSYMBOL_factor = 64,                    /* factor  */
  YYSYMBOL_opt_exprs = 65,                 /* opt_exprs  */
  YYSYMBOL_expr_lst = 66,                  /* expr_lst  */
  YYSYMBOL_expresion = 67                  /* expresion  */
};
typedef enum yysymbol_kind_t yysymbol_kind_t;




#ifdef short
# undef short
#endif

/* On compilers that do not define __PTRDIFF_MAX__ etc., make sure
   <limits.h> and (if available) <stdint.h> are included
   so that the code can choose integer types of a good width.  */

#ifndef __PTRDIFF_MAX__
# include <limits.h> /* INFRINGES ON USER NAME SPACE */
# if defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stdint.h> /* INFRINGES ON USER NAME SPACE */
#  define YY_STDINT_H
# endif
#endif

/* Narrow types that promote to a signed type and that can represent a
   signed or unsigned integer of at least N bits.  In tables they can
   save space and decrease cache pressure.  Promoting to a signed type
   helps avoid bugs in integer arithmetic.  */

#ifdef __INT_LEAST8_MAX__
typedef __INT_LEAST8_TYPE__ yytype_int8;
#elif defined YY_STDINT_H
typedef int_least8_t yytype_int8;
#else
typedef signed char yytype_int8;
#endif

#ifdef __INT_LEAST16_MAX__
typedef __INT_LEAST16_TYPE__ yytype_int16;
#elif defined YY_STDINT_H
typedef int_least16_t yytype_int16;
#else
typedef short yytype_int16;
#endif

/* Work around bug in HP-UX 11.23, which defines these macros
   incorrectly for preprocessor constants.  This workaround can likely
   be removed in 2023, as HPE has promised support for HP-UX 11.23
   (aka HP-UX 11i v2) only through the end of 2022; see Table 2 of
   <https://h20195.www2.hpe.com/V2/getpdf.aspx/4AA4-7673ENW.pdf>.  */
#ifdef __hpux
# undef UINT_LEAST8_MAX
# undef UINT_LEAST16_MAX
# define UINT_LEAST8_MAX 255
# define UINT_LEAST16_MAX 65535
#endif

#if defined __UINT_LEAST8_MAX__ && __UINT_LEAST8_MAX__ <= __INT_MAX__
typedef __UINT_LEAST8_TYPE__ yytype_uint8;
#elif (!defined __UINT_LEAST8_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST8_MAX <= INT_MAX)
typedef uint_least8_t yytype_uint8;
#elif !defined __UINT_LEAST8_MAX__ && UCHAR_MAX <= INT_MAX
typedef unsigned char yytype_uint8;
#else
typedef short yytype_uint8;
#endif

#if defined __UINT_LEAST16_MAX__ && __UINT_LEAST16_MAX__ <= __INT_MAX__
typedef __UINT_LEAST16_TYPE__ yytype_uint16;
#elif (!defined __UINT_LEAST16_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST16_MAX <= INT_MAX)
typedef uint_least16_t yytype_uint16;
#elif !defined __UINT_LEAST16_MAX__ && USHRT_MAX <= INT_MAX
typedef unsigned short yytype_uint16;
#else
typedef int yytype_uint16;
#endif

#ifndef YYPTRDIFF_T
# if defined __PTRDIFF_TYPE__ && defined __PTRDIFF_MAX__
#  define YYPTRDIFF_T __PTRDIFF_TYPE__
#  define YYPTRDIFF_MAXIMUM __PTRDIFF_MAX__
# elif defined PTRDIFF_MAX
#  ifndef ptrdiff_t
#   include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  endif
#  define YYPTRDIFF_T ptrdiff_t
#  define YYPTRDIFF_MAXIMUM PTRDIFF_MAX
# else
#  define YYPTRDIFF_T long
#  define YYPTRDIFF_MAXIMUM LONG_MAX
# endif
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned
# endif
#endif

#define YYSIZE_MAXIMUM                                  \
  YY_CAST (YYPTRDIFF_T,                                 \
           (YYPTRDIFF_MAXIMUM < YY_CAST (YYSIZE_T, -1)  \
            ? YYPTRDIFF_MAXIMUM                         \
            : YY_CAST (YYSIZE_T, -1)))

#define YYSIZEOF(X) YY_CAST (YYPTRDIFF_T, sizeof (X))


/* Stored state numbers (used for stacks). */
typedef yytype_int8 yy_state_t;

/* State numbers in computations.  */
typedef int yy_state_fast_t;

#ifndef YY_
# if defined YYENABLE_NLS && YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* INFRINGES ON USER NAME SPACE */
#   define YY_(Msgid) dgettext ("bison-runtime", Msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(Msgid) Msgid
# endif
#endif


#ifndef YY_ATTRIBUTE_PURE
# if defined __GNUC__ && 2 < __GNUC__ + (96 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_PURE __attribute__ ((__pure__))
# else
#  define YY_ATTRIBUTE_PURE
# endif
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# if defined __GNUC__ && 2 < __GNUC__ + (7 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_UNUSED __attribute__ ((__unused__))
# else
#  define YY_ATTRIBUTE_UNUSED
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YY_USE(E) ((void) (E))
#else
# define YY_USE(E) /* empty */
#endif

#if defined __GNUC__ && ! defined __ICC && 407 <= __GNUC__ * 100 + __GNUC_MINOR__
/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                            \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")              \
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# define YY_IGNORE_MAYBE_UNINITIALIZED_END      \
    _Pragma ("GCC diagnostic pop")
#else
# define YY_INITIAL_VALUE(Value) Value
#endif
#ifndef YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_END
#endif
#ifndef YY_INITIAL_VALUE
# define YY_INITIAL_VALUE(Value) /* Nothing. */
#endif

#if defined __cplusplus && defined __GNUC__ && ! defined __ICC && 6 <= __GNUC__
# define YY_IGNORE_USELESS_CAST_BEGIN                          \
    _Pragma ("GCC diagnostic push")                            \
    _Pragma ("GCC diagnostic ignored \"-Wuseless-cast\"")
# define YY_IGNORE_USELESS_CAST_END            \
    _Pragma ("GCC diagnostic pop")
#endif
#ifndef YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_END
#endif


#define YY_ASSERT(E) ((void) (0 && (E)))

#if !defined yyoverflow

/* The parser invokes alloca or malloc; define the necessary symbols.  */

# ifdef YYSTACK_USE_ALLOCA
#  if YYSTACK_USE_ALLOCA
#   ifdef __GNUC__
#    define YYSTACK_ALLOC __builtin_alloca
#   elif defined __BUILTIN_VA_ARG_INCR
#    include <alloca.h> /* INFRINGES ON USER NAME SPACE */
#   elif defined _AIX
#    define YYSTACK_ALLOC __alloca
#   elif defined _MSC_VER
#    include <malloc.h> /* INFRINGES ON USER NAME SPACE */
#    define alloca _alloca
#   else
#    define YYSTACK_ALLOC alloca
#    if ! defined _ALLOCA_H && ! defined EXIT_SUCCESS
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
      /* Use EXIT_SUCCESS as a witness for stdlib.h.  */
#     ifndef EXIT_SUCCESS
#      define EXIT_SUCCESS 0
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's 'empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (0)
#  ifndef YYSTACK_ALLOC_MAXIMUM
    /* The OS might guarantee only one guard page at the bottom of the stack,
       and a page size can be as small as 4096 bytes.  So we cannot safely
       invoke alloca (N) if N exceeds 4096.  Use a slightly smaller number
       to allow for a few compiler-allocated temporary stack slots.  */
#   define YYSTACK_ALLOC_MAXIMUM 4032 /* reasonable circa 2006 */
#  endif
# else
#  define YYSTACK_ALLOC YYMALLOC
#  define YYSTACK_FREE YYFREE
#  ifndef YYSTACK_ALLOC_MAXIMUM
#   define YYSTACK_ALLOC_MAXIMUM YYSIZE_MAXIMUM
#  endif
#  if (defined __cplusplus && ! defined EXIT_SUCCESS \
       && ! ((defined YYMALLOC || defined malloc) \
             && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef EXIT_SUCCESS
#    define EXIT_SUCCESS 0
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined EXIT_SUCCESS
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined EXIT_SUCCESS
void free (void *); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
# endif
#endif /* !defined yyoverflow */

#if (! defined yyoverflow \
     && (! defined __cplusplus \
         || (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yy_state_t yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (YYSIZEOF (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (YYSIZEOF (yy_state_t) + YYSIZEOF (YYSTYPE)) \
      + YYSTACK_GAP_MAXIMUM)

# define YYCOPY_NEEDED 1

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack_alloc, Stack)                           \
    do                                                                  \
      {                                                                 \
        YYPTRDIFF_T yynewbytes;                                         \
        YYCOPY (&yyptr->Stack_alloc, Stack, yysize);                    \
        Stack = &yyptr->Stack_alloc;                                    \
        yynewbytes = yystacksize * YYSIZEOF (*Stack) + YYSTACK_GAP_MAXIMUM; \
        yyptr += yynewbytes / YYSIZEOF (*yyptr);                        \
      }                                                                 \
    while (0)

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, YY_CAST (YYSIZE_T, (Count)) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYPTRDIFF_T yyi;                      \
          for (yyi = 0; yyi < (Count); yyi++)   \
            (Dst)[yyi] = (Src)[yyi];            \
        }                                       \
      while (0)
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  4
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   113

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  47
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  21
/* YYNRULES -- Number of rules.  */
#define YYNRULES  54
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  119

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   301


/* YYTRANSLATE(TOKEN-NUM) -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, with out-of-bounds checking.  */
#define YYTRANSLATE(YYX)                                \
  (0 <= (YYX) && (YYX) <= YYMAXUTOK                     \
   ? YY_CAST (yysymbol_kind_t, yytranslate[YYX])        \
   : YYSYMBOL_YYUNDEF)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex.  */
static const yytype_int8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     1,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,   132,   132,   136,   137,   140,   141,   144,   170,   171,
     177,   178,   181,   182,   187,   200,   212,   213,   217,   218,
     220,   236,   255,   256,   257,   258,   260,   280,   281,   282,
     283,   287,   288,   291,   292,   295,   296,   297,   300,   301,
     302,   305,   306,   307,   308,   309,   314,   315,   318,   319,
     321,   322,   323,   324,   325
};
#endif

/** Accessing symbol of state STATE.  */
#define YY_ACCESSING_SYMBOL(State) YY_CAST (yysymbol_kind_t, yystos[State])

#if YYDEBUG || 0
/* The user-facing name of the symbol whose (internal) number is
   YYSYMBOL.  No bounds checking.  */
static const char *yysymbol_name (yysymbol_kind_t yysymbol) YY_ATTRIBUTE_UNUSED;

/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "\"end of file\"", "error", "\"invalid token\"", "END", "PROGRAM",
  "BEGINI", "IF", "ENDIF", "ELSE", "FOR", "STEP", "DO", "WHILE", "READ",
  "PRINT", "SUMA", "RESTA", "MULTI", "DIVIDE", "PARENI", "PAREND", "EQUAL",
  "MENORQ", "MAYORQ", "MENORIQ", "MAYORIQ", "PCOMA", "DOSPUNTOS", "COMA",
  "OTRO", "INT", "FLOAT", "CONS", "VAR", "PYC", "REPEAT", "UNTIL",
  "ASSIGN", "THEN", "FUN", "CALL", "RETRN", "PARS", "EXEC", "NINT",
  "NFLOAT", "IDF", "$accept", "prog", "opt_decls", "decl_lst", "decl",
  "type", "opt_fun_decls", "fun_decls", "fun_decl", "oparams", "params",
  "param", "stmt", "opt_stmts", "stmt_lst", "expr", "term", "factor",
  "opt_exprs", "expr_lst", "expresion", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#ifdef YYPRINT
/* YYTOKNUM[NUM] -- (External) token number corresponding to the
   (internal) symbol number NUM (which must be that of a token).  */
static const yytype_int16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298,   299,   300,   301
};
#endif

#define YYPACT_NINF (-54)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-1)

#define yytable_value_is_error(Yyn) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int8 yypact[] =
{
       2,   -42,    10,    -9,   -54,   -18,     5,   -54,    13,    26,
      18,    62,     5,   -54,    -9,   -13,    49,    17,   -54,   -54,
     -54,   -54,   -54,    24,    17,   -12,    25,    53,    27,   -12,
      17,   -12,    38,    50,    74,   -54,    51,    59,   -54,    54,
      78,   -12,   -54,   -54,    65,    75,    23,   -54,    47,    55,
     -12,   -54,    41,    58,    41,   -12,    17,   -54,   -13,    60,
      24,   -54,    22,   -12,   -12,   -12,   -12,   -12,   -12,   -12,
     -12,   -12,   -12,    17,   -12,    66,    76,    41,   -54,   -54,
     -13,   -54,   -54,    -3,    81,   -54,    23,    23,    41,    41,
      41,    41,    41,   -54,   -54,    94,     0,    17,   -12,   -25,
     -12,   -54,    17,   -12,   -54,    83,   -54,    99,   -54,   -54,
       4,   -54,    17,   -12,   102,    44,   -54,    17,   -54
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       0,     0,     0,     3,     1,     0,    10,     4,     6,     0,
       0,     0,    11,    13,     0,     0,     0,    31,    12,     5,
       8,     9,     7,    16,    31,     0,     0,     0,     0,     0,
       0,     0,     0,    33,     0,    32,     0,     0,    17,    19,
       0,     0,    43,    44,    42,     0,    37,    40,     0,     0,
       0,    27,    28,     0,    29,     0,     0,     2,     0,     0,
       0,    30,     0,    46,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    21,    34,    20,
       0,    18,    41,    49,     0,    47,    35,    36,    52,    50,
      51,    53,    54,    38,    39,    22,     0,     0,     0,     3,
       0,    45,     0,     0,    24,     0,    15,     0,    48,    23,
       0,    25,    31,     0,     0,     0,    14,     0,    26
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
     -54,   -54,     7,    93,   -54,   -53,   -54,   -54,    96,   -54,
      52,   -54,   -28,   -24,    57,   -20,     1,   -10,   -54,     9,
     -47
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
       0,     2,     6,     7,     8,    22,    11,    12,    13,    37,
      38,    39,    33,    34,    35,    45,    46,    47,    84,    85,
      48
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int8 yytable[] =
{
      40,   106,    53,    75,     3,    79,     1,    41,     5,    52,
       4,    54,    64,    65,   113,    64,    65,    20,    21,    64,
      65,    62,    24,    25,     5,   100,    26,    99,     9,    27,
      28,    29,    42,    43,    44,    77,   103,    64,    65,    14,
      71,    72,    82,    83,    10,    95,    88,    89,    90,    91,
      92,   105,    30,    15,    96,   117,    64,    65,    31,    64,
      65,    93,    94,    32,    16,    86,    87,    17,    23,   104,
      36,    49,    50,    51,   109,    55,    56,    57,    58,    59,
      83,    61,    60,   110,    63,    73,    97,    80,   114,   118,
      64,    65,    74,   115,    76,    98,    66,    67,    68,    69,
      70,   101,   102,   111,   112,   116,   107,    19,    18,   108,
       0,     0,    81,    78
};

static const yytype_int8 yycheck[] =
{
      24,    26,    30,    50,    46,    58,     4,    19,    33,    29,
       0,    31,    15,    16,    10,    15,    16,    30,    31,    15,
      16,    41,     5,     6,    33,    28,     9,    80,    46,    12,
      13,    14,    44,    45,    46,    55,    36,    15,    16,    26,
      17,    18,    20,    63,    39,    73,    66,    67,    68,    69,
      70,    98,    35,    27,    74,    11,    15,    16,    41,    15,
      16,    71,    72,    46,    46,    64,    65,     5,    19,    97,
      46,    46,    19,    46,   102,    37,    26,     3,    27,    20,
     100,     3,    28,   103,    19,    38,    20,    27,   112,   117,
      15,    16,    37,   113,    36,    19,    21,    22,    23,    24,
      25,    20,     8,    20,     5,     3,    99,    14,    12,   100,
      -1,    -1,    60,    56
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,     4,    48,    46,     0,    33,    49,    50,    51,    46,
      39,    53,    54,    55,    26,    27,    46,     5,    55,    50,
      30,    31,    52,    19,     5,     6,     9,    12,    13,    14,
      35,    41,    46,    59,    60,    61,    46,    56,    57,    58,
      60,    19,    44,    45,    46,    62,    63,    64,    67,    46,
      19,    46,    62,    59,    62,    37,    26,     3,    27,    20,
      28,     3,    62,    19,    15,    16,    21,    22,    23,    24,
      25,    17,    18,    38,    37,    67,    36,    62,    61,    52,
      27,    57,    20,    62,    65,    66,    63,    63,    62,    62,
      62,    62,    62,    64,    64,    59,    62,    20,    19,    52,
      28,    20,     8,    36,    59,    67,    26,    49,    66,    59,
      62,    20,     5,    10,    60,    62,     3,    11,    59
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_int8 yyr1[] =
{
       0,    47,    48,    49,    49,    50,    50,    51,    52,    52,
      53,    53,    54,    54,    55,    55,    56,    56,    57,    57,
      58,    59,    59,    59,    59,    59,    59,    59,    59,    59,
      59,    60,    60,    61,    61,    62,    62,    62,    63,    63,
      63,    64,    64,    64,    64,    64,    65,    65,    66,    66,
      67,    67,    67,    67,    67
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     7,     0,     1,     3,     1,     4,     1,     1,
       0,     1,     2,     1,    11,     8,     0,     1,     3,     1,
       3,     3,     4,     6,     5,     6,    10,     2,     2,     2,
       3,     0,     1,     1,     3,     3,     3,     1,     3,     3,
       1,     3,     1,     1,     1,     4,     0,     1,     3,     1,
       3,     3,     3,     3,     3
};


enum { YYENOMEM = -2 };

#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab


#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                    \
  do                                                              \
    if (yychar == YYEMPTY)                                        \
      {                                                           \
        yychar = (Token);                                         \
        yylval = (Value);                                         \
        YYPOPSTACK (yylen);                                       \
        yystate = *yyssp;                                         \
        goto yybackup;                                            \
      }                                                           \
    else                                                          \
      {                                                           \
        yyerror (YY_("syntax error: cannot back up")); \
        YYERROR;                                                  \
      }                                                           \
  while (0)

/* Backward compatibility with an undocumented macro.
   Use YYerror or YYUNDEF. */
#define YYERRCODE YYUNDEF


/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)                        \
do {                                            \
  if (yydebug)                                  \
    YYFPRINTF Args;                             \
} while (0)

/* This macro is provided for backward compatibility. */
# ifndef YY_LOCATION_PRINT
#  define YY_LOCATION_PRINT(File, Loc) ((void) 0)
# endif


# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Kind, Value); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*-----------------------------------.
| Print this symbol's value on YYO.  |
`-----------------------------------*/

static void
yy_symbol_value_print (FILE *yyo,
                       yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep)
{
  FILE *yyoutput = yyo;
  YY_USE (yyoutput);
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yykind < YYNTOKENS)
    YYPRINT (yyo, yytoknum[yykind], *yyvaluep);
# endif
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YY_USE (yykind);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/*---------------------------.
| Print this symbol on YYO.  |
`---------------------------*/

static void
yy_symbol_print (FILE *yyo,
                 yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyo, "%s %s (",
             yykind < YYNTOKENS ? "token" : "nterm", yysymbol_name (yykind));

  yy_symbol_value_print (yyo, yykind, yyvaluep);
  YYFPRINTF (yyo, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

static void
yy_stack_print (yy_state_t *yybottom, yy_state_t *yytop)
{
  YYFPRINTF (stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
    {
      int yybot = *yybottom;
      YYFPRINTF (stderr, " %d", yybot);
    }
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)                            \
do {                                                            \
  if (yydebug)                                                  \
    yy_stack_print ((Bottom), (Top));                           \
} while (0)


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

static void
yy_reduce_print (yy_state_t *yyssp, YYSTYPE *yyvsp,
                 int yyrule)
{
  int yylno = yyrline[yyrule];
  int yynrhs = yyr2[yyrule];
  int yyi;
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %d):\n",
             yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr,
                       YY_ACCESSING_SYMBOL (+yyssp[yyi + 1 - yynrhs]),
                       &yyvsp[(yyi + 1) - (yynrhs)]);
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)          \
do {                                    \
  if (yydebug)                          \
    yy_reduce_print (yyssp, yyvsp, Rule); \
} while (0)

/* Nonzero means print parse trace.  It is left uninitialized so that
   multiple parsers can coexist.  */
int yydebug;
#else /* !YYDEBUG */
# define YYDPRINTF(Args) ((void) 0)
# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)
# define YY_STACK_PRINT(Bottom, Top)
# define YY_REDUCE_PRINT(Rule)
#endif /* !YYDEBUG */


/* YYINITDEPTH -- initial size of the parser's stacks.  */
#ifndef YYINITDEPTH
# define YYINITDEPTH 200
#endif

/* YYMAXDEPTH -- maximum size the stacks can grow to (effective only
   if the built-in stack extension method is used).

   Do not make this value too large; the results are undefined if
   YYSTACK_ALLOC_MAXIMUM < YYSTACK_BYTES (YYMAXDEPTH)
   evaluated with infinite-precision integer arithmetic.  */

#ifndef YYMAXDEPTH
# define YYMAXDEPTH 10000
#endif






/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
yydestruct (const char *yymsg,
            yysymbol_kind_t yykind, YYSTYPE *yyvaluep)
{
  YY_USE (yyvaluep);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yykind, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YY_USE (yykind);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/* Lookahead token kind.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval;
/* Number of syntax errors so far.  */
int yynerrs;




/*----------.
| yyparse.  |
`----------*/

int
yyparse (void)
{
    yy_state_fast_t yystate = 0;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus = 0;

    /* Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* Their size.  */
    YYPTRDIFF_T yystacksize = YYINITDEPTH;

    /* The state stack: array, bottom, top.  */
    yy_state_t yyssa[YYINITDEPTH];
    yy_state_t *yyss = yyssa;
    yy_state_t *yyssp = yyss;

    /* The semantic value stack: array, bottom, top.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs = yyvsa;
    YYSTYPE *yyvsp = yyvs;

  int yyn;
  /* The return value of yyparse.  */
  int yyresult;
  /* Lookahead symbol kind.  */
  yysymbol_kind_t yytoken = YYSYMBOL_YYEMPTY;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;



#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yychar = YYEMPTY; /* Cause a token to be read.  */
  goto yysetstate;


/*------------------------------------------------------------.
| yynewstate -- push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;


/*--------------------------------------------------------------------.
| yysetstate -- set current state (the top of the stack) to yystate.  |
`--------------------------------------------------------------------*/
yysetstate:
  YYDPRINTF ((stderr, "Entering state %d\n", yystate));
  YY_ASSERT (0 <= yystate && yystate < YYNSTATES);
  YY_IGNORE_USELESS_CAST_BEGIN
  *yyssp = YY_CAST (yy_state_t, yystate);
  YY_IGNORE_USELESS_CAST_END
  YY_STACK_PRINT (yyss, yyssp);

  if (yyss + yystacksize - 1 <= yyssp)
#if !defined yyoverflow && !defined YYSTACK_RELOCATE
    goto yyexhaustedlab;
#else
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYPTRDIFF_T yysize = yyssp - yyss + 1;

# if defined yyoverflow
      {
        /* Give user a chance to reallocate the stack.  Use copies of
           these so that the &'s don't force the real ones into
           memory.  */
        yy_state_t *yyss1 = yyss;
        YYSTYPE *yyvs1 = yyvs;

        /* Each stack pointer address is followed by the size of the
           data in use in that stack, in bytes.  This used to be a
           conditional around just the two extra args, but that might
           be undefined if yyoverflow is a macro.  */
        yyoverflow (YY_("memory exhausted"),
                    &yyss1, yysize * YYSIZEOF (*yyssp),
                    &yyvs1, yysize * YYSIZEOF (*yyvsp),
                    &yystacksize);
        yyss = yyss1;
        yyvs = yyvs1;
      }
# else /* defined YYSTACK_RELOCATE */
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
        goto yyexhaustedlab;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
        yystacksize = YYMAXDEPTH;

      {
        yy_state_t *yyss1 = yyss;
        union yyalloc *yyptr =
          YY_CAST (union yyalloc *,
                   YYSTACK_ALLOC (YY_CAST (YYSIZE_T, YYSTACK_BYTES (yystacksize))));
        if (! yyptr)
          goto yyexhaustedlab;
        YYSTACK_RELOCATE (yyss_alloc, yyss);
        YYSTACK_RELOCATE (yyvs_alloc, yyvs);
#  undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;

      YY_IGNORE_USELESS_CAST_BEGIN
      YYDPRINTF ((stderr, "Stack size increased to %ld\n",
                  YY_CAST (long, yystacksize)));
      YY_IGNORE_USELESS_CAST_END

      if (yyss + yystacksize - 1 <= yyssp)
        YYABORT;
    }
#endif /* !defined yyoverflow && !defined YYSTACK_RELOCATE */

  if (yystate == YYFINAL)
    YYACCEPT;

  goto yybackup;


/*-----------.
| yybackup.  |
`-----------*/
yybackup:
  /* Do appropriate processing given the current state.  Read a
     lookahead token if we need one and don't already have one.  */

  /* First try to decide what to do without reference to lookahead token.  */
  yyn = yypact[yystate];
  if (yypact_value_is_default (yyn))
    goto yydefault;

  /* Not known => get a lookahead token if don't already have one.  */

  /* YYCHAR is either empty, or end-of-input, or a valid lookahead.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token\n"));
      yychar = yylex ();
    }

  if (yychar <= YYEOF)
    {
      yychar = YYEOF;
      yytoken = YYSYMBOL_YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
    }
  else if (yychar == YYerror)
    {
      /* The scanner already issued an error message, process directly
         to error recovery.  But do not keep the error token as
         lookahead, it is too special and may lead us to an endless
         loop in error recovery. */
      yychar = YYUNDEF;
      yytoken = YYSYMBOL_YYerror;
      goto yyerrlab1;
    }
  else
    {
      yytoken = YYTRANSLATE (yychar);
      YY_SYMBOL_PRINT ("Next token is", yytoken, &yylval, &yylloc);
    }

  /* If the proper action on seeing token YYTOKEN is to reduce or to
     detect an error, take that action.  */
  yyn += yytoken;
  if (yyn < 0 || YYLAST < yyn || yycheck[yyn] != yytoken)
    goto yydefault;
  yyn = yytable[yyn];
  if (yyn <= 0)
    {
      if (yytable_value_is_error (yyn))
        goto yyerrlab;
      yyn = -yyn;
      goto yyreduce;
    }

  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  /* Shift the lookahead token.  */
  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);
  yystate = yyn;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

  /* Discard the shifted token.  */
  yychar = YYEMPTY;
  goto yynewstate;


/*-----------------------------------------------------------.
| yydefault -- do the default action for the current state.  |
`-----------------------------------------------------------*/
yydefault:
  yyn = yydefact[yystate];
  if (yyn == 0)
    goto yyerrlab;
  goto yyreduce;


/*-----------------------------.
| yyreduce -- do a reduction.  |
`-----------------------------*/
yyreduce:
  /* yyn is the number of a rule to reduce with.  */
  yylen = yyr2[yyn];

  /* If YYLEN is nonzero, implement the default value of the action:
     '$$ = $1'.

     Otherwise, the following line sets YYVAL to garbage.
     This behavior is undocumented and Bison
     users should not rely upon it.  Assigning to YYVAL
     unconditionally makes the parser a bit smaller, and it avoids a
     GCC warning that YYVAL may be used uninitialized.  */
  yyval = yyvsp[1-yylen];


  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
  case 2: /* prog: PROGRAM IDF opt_decls opt_fun_decls BEGINI opt_stmts END  */
#line 132 "reconocedor.y"
                                                                { list = (yyvsp[-4].yynodo); tree = (yyvsp[-1].yynodo); tree_fun = (yyvsp[-3].yynodo);  }
#line 1318 "reconocedor.tab.c"
    break;

  case 3: /* opt_decls: %empty  */
#line 136 "reconocedor.y"
                           { (yyval.yynodo) = NULL; amb2++; }
#line 1324 "reconocedor.tab.c"
    break;

  case 4: /* opt_decls: decl_lst  */
#line 137 "reconocedor.y"
                                                               { (yyval.yynodo) = (yyvsp[0].yynodo); amb2++;}
#line 1330 "reconocedor.tab.c"
    break;

  case 5: /* decl_lst: decl PCOMA decl_lst  */
#line 140 "reconocedor.y"
                                                               { (yyvsp[-2].yynodo) -> sig = (yyvsp[0].yynodo), (yyval.yynodo) = (yyvsp[-2].yynodo); }
#line 1336 "reconocedor.tab.c"
    break;

  case 6: /* decl_lst: decl  */
#line 141 "reconocedor.y"
                                                               { (yyval.yynodo) = (yyvsp[0].yynodo); }
#line 1342 "reconocedor.tab.c"
    break;

  case 7: /* decl: VAR IDF DOSPUNTOS type  */
#line 144 "reconocedor.y"
                                  {

   if (amb2 == 0){
      SYM *n2 = nuevo_nodo_tabla((yyvsp[-2].yyid), (yyvsp[0].yytipo)); 
      if (buscar_simbolo((yyvsp[-2].yyid)) != NULL){ 
         yyerror("Esta variable ya existe"); 
      } 
      insert_table_node(n2); 
      
      (yyval.yynodo) = new_tree_node(VAR, (yyvsp[-2].yyid), (yyvsp[0].yytipo), 0, 0.0, NULL, NULL, NULL,n2);
   }else{
      


      SYM *n2 = nuevo_nodo_tabla_fpar((yyvsp[-2].yyid), (yyvsp[0].yytipo)); 
      if (buscar_simbolo_fpar((yyvsp[-2].yyid)) != NULL){ 
         yyerror("Esta variable ya existe"); 
      } 
      insert_table_node_fpar(n2); 
      
      (yyval.yynodo) = new_tree_node(VAR, (yyvsp[-2].yyid), (yyvsp[0].yytipo), 0, 0.0, NULL, NULL, NULL,n2);
   }


}
#line 1372 "reconocedor.tab.c"
    break;

  case 8: /* type: INT  */
#line 170 "reconocedor.y"
                                                           { (yyval.yytipo) = 'i'; }
#line 1378 "reconocedor.tab.c"
    break;

  case 9: /* type: FLOAT  */
#line 171 "reconocedor.y"
                                                           { (yyval.yytipo) = 'f'; }
#line 1384 "reconocedor.tab.c"
    break;

  case 10: /* opt_fun_decls: %empty  */
#line 177 "reconocedor.y"
               { (yyval.yynodo) = NULL; amb++;}
#line 1390 "reconocedor.tab.c"
    break;

  case 11: /* opt_fun_decls: fun_decls  */
#line 178 "reconocedor.y"
                            { (yyval.yynodo) = (yyvsp[0].yynodo); amb++;}
#line 1396 "reconocedor.tab.c"
    break;

  case 12: /* fun_decls: fun_decls fun_decl  */
#line 181 "reconocedor.y"
                                        { (yyvsp[-1].yynodo) -> sig = (yyvsp[0].yynodo), (yyval.yynodo) = (yyvsp[-1].yynodo); }
#line 1402 "reconocedor.tab.c"
    break;

  case 13: /* fun_decls: fun_decl  */
#line 182 "reconocedor.y"
                                     { (yyval.yynodo) = (yyvsp[0].yynodo); }
#line 1408 "reconocedor.tab.c"
    break;

  case 14: /* fun_decl: FUN IDF PARENI oparams PAREND DOSPUNTOS type opt_decls BEGINI opt_stmts END  */
#line 187 "reconocedor.y"
                                                                                        {

   SYM *n2 = nuevo_nodo_tabla_f((yyvsp[-9].yyid), (yyvsp[-4].yytipo)); 
   if (buscar_simbolo_f((yyvsp[-9].yyid)) != NULL){
       yyerror("Esta funcion ya existe"); 
   } 

   insert_table_node_f(n2); 


  (yyval.yynodo) = new_tree_node(FUN, (yyvsp[-9].yyid), (yyvsp[-4].yytipo), 0, 0.0, (yyvsp[-7].yynodo) ,
  new_tree_node(EXEC, (yyvsp[-9].yyid), (yyvsp[-4].yytipo), 0, 0.0, (yyvsp[-3].yynodo) ,(yyvsp[-1].yynodo),NULL,n2),NULL,n2); }
#line 1425 "reconocedor.tab.c"
    break;

  case 15: /* fun_decl: FUN IDF PARENI oparams PAREND DOSPUNTOS type PCOMA  */
#line 200 "reconocedor.y"
                                                      {
         
   SYM *n2 = nuevo_nodo_tabla_f((yyvsp[-6].yyid), (yyvsp[-1].yytipo)); 
   if (buscar_simbolo_f((yyvsp[-6].yyid)) != NULL){
       yyerror("Esta variable ya existe"); 
   } 

   insert_table_node_f(n2); 
    (yyval.yynodo) = new_tree_node(FUN, (yyvsp[-6].yyid), (yyvsp[-1].yytipo), 0, 0.0, (yyvsp[-4].yynodo) ,NULL, NULL,n2);

   }
#line 1441 "reconocedor.tab.c"
    break;

  case 16: /* oparams: %empty  */
#line 212 "reconocedor.y"
         {(yyval.yynodo) = NULL;}
#line 1447 "reconocedor.tab.c"
    break;

  case 17: /* oparams: params  */
#line 213 "reconocedor.y"
            {(yyval.yynodo) = (yyvsp[0].yynodo);}
#line 1453 "reconocedor.tab.c"
    break;

  case 18: /* params: param COMA params  */
#line 217 "reconocedor.y"
                           { (yyvsp[-2].yynodo) -> sig = (yyvsp[0].yynodo), (yyval.yynodo) = (yyvsp[-2].yynodo); }
#line 1459 "reconocedor.tab.c"
    break;

  case 19: /* params: param  */
#line 218 "reconocedor.y"
               {(yyval.yynodo) = (yyvsp[0].yynodo);}
#line 1465 "reconocedor.tab.c"
    break;

  case 20: /* param: IDF DOSPUNTOS type  */
#line 220 "reconocedor.y"
                          {

      SYM *n4 = nuevo_nodo_tabla_fpar((yyvsp[-2].yyid), (yyvsp[0].yytipo)); 
      if (buscar_simbolo_fpar((yyvsp[-2].yyid)) != NULL){ 
         yyerror("Esta variable ya existe"); 
      } 
      insert_table_node_fpar(n4); 


      (yyval.yynodo) = new_tree_node(PARS, (yyvsp[-2].yyid), (yyvsp[0].yytipo), 0, 0.0, NULL ,NULL, NULL,n4);

}
#line 1482 "reconocedor.tab.c"
    break;

  case 21: /* stmt: IDF ASSIGN expr  */
#line 238 "reconocedor.y"
      { 
      
      SYM * n = NULL;
         if (amb == 0){
         n = buscar_simbolo_fpar((yyvsp[-2].yyid)); 
         
      }else{
            n = buscar_simbolo((yyvsp[-2].yyid)); 
      }
      
      if (n == NULL) { 
         yyerror("Variable no declarada"); 
      } if (n -> value_type != revision_tipos((yyvsp[0].yynodo))) { 
         yyerror("Tipos incompatibles"); 
      } 
      (yyval.yynodo) = new_tree_node(PYC, ";", '0', 0, 0.0, new_tree_node(ASSIGN, "assign", '0', 0, 0.0, new_tree_node(VAR, (yyvsp[-2].yyid), '0', 0, 0.0, NULL, NULL, NULL,n), (yyvsp[0].yynodo), NULL,NULL), NULL, NULL,NULL); }
#line 1503 "reconocedor.tab.c"
    break;

  case 22: /* stmt: IF expresion THEN stmt  */
#line 255 "reconocedor.y"
                                                                   { (yyval.yynodo) = new_tree_node(PYC, ";", '0', 0, 0.0, new_tree_node(IF, "if", '0', 0, 0.0, (yyvsp[-2].yynodo), (yyvsp[0].yynodo), NULL,NULL), NULL, NULL,NULL); }
#line 1509 "reconocedor.tab.c"
    break;

  case 23: /* stmt: IF expresion THEN stmt ELSE stmt  */
#line 256 "reconocedor.y"
                                                                   { (yyval.yynodo) = new_tree_node(PYC, ";", '0', 0, 0.0, new_tree_node(IF, "if", '0', 0, 0.0, (yyvsp[-4].yynodo), (yyvsp[-2].yynodo), (yyvsp[0].yynodo),NULL), NULL, NULL,NULL); }
#line 1515 "reconocedor.tab.c"
    break;

  case 24: /* stmt: WHILE PARENI expresion PAREND stmt  */
#line 257 "reconocedor.y"
                                                                   { (yyval.yynodo) = new_tree_node(PYC, ";", '0', 0, 0.0, new_tree_node(WHILE, "while", '0', 0, 0.0, (yyvsp[-2].yynodo),(yyvsp[0].yynodo),NULL,NULL), NULL, NULL,NULL); }
#line 1521 "reconocedor.tab.c"
    break;

  case 25: /* stmt: REPEAT stmt UNTIL PARENI expresion PAREND  */
#line 258 "reconocedor.y"
                                                                   { (yyval.yynodo) = new_tree_node(PYC, ";", '0', 0, 0.0, new_tree_node(REPEAT, "repeat", '0', 0, 0.0,  (yyvsp[-1].yynodo), (yyvsp[-4].yynodo),NULL ,NULL), NULL, NULL,NULL); }
#line 1527 "reconocedor.tab.c"
    break;

  case 26: /* stmt: FOR IDF ASSIGN expr UNTIL expr STEP expr DO stmt  */
#line 262 "reconocedor.y"
           { SYM * n = NULL;
         
           if (amb == 0){n = buscar_simbolo_fpar((yyvsp[-8].yyid)); }else{n = buscar_simbolo((yyvsp[-8].yyid)); }
           if (n == NULL) { 
           yyerror("Variable no declarada"); 
           } 
           if (n -> value_type != revision_tipos((yyvsp[-6].yynodo)) || n -> value_type != revision_tipos((yyvsp[-4].yynodo)) || n -> value_type != revision_tipos((yyvsp[-2].yynodo))) {
            yyerror("Tipos incompatibles"); 
           } 

            (yyval.yynodo) = new_tree_node(PYC, ";", '0', 0, 0.0, 
            new_tree_node(FOR, "for", '0', 0, 0.0,
            
            new_tree_node(PYC, ";", '0', 0, 0.0, new_tree_node(ASSIGN, "assign", '0', 0, 0.0, new_tree_node(VAR, (yyvsp[-8].yyid), '0', 0, 0.0, NULL, NULL, NULL,n), (yyvsp[-6].yynodo), (yyvsp[-4].yynodo),NULL), NULL, NULL,NULL),(yyvsp[-2].yynodo),(yyvsp[0].yynodo),NULL),NULL,NULL,NULL);
           
           }
#line 1548 "reconocedor.tab.c"
    break;

  case 27: /* stmt: READ IDF  */
#line 280 "reconocedor.y"
                                                           {   SYM * n = NULL;          if (amb == 0){n = buscar_simbolo_fpar((yyvsp[0].yyid)); }else{n = buscar_simbolo((yyvsp[0].yyid)); }if (n == NULL) { yyerror("Variable no declarada"); } (yyval.yynodo) = new_tree_node(PYC, ";", '0', 0, 0.0, new_tree_node(READ, "read", '0', 0, 0.0, new_tree_node(VAR, (yyvsp[0].yyid), '0', 0, 0.0, NULL, NULL, NULL,n), NULL, NULL,NULL), NULL, NULL,NULL); }
#line 1554 "reconocedor.tab.c"
    break;

  case 28: /* stmt: PRINT expr  */
#line 281 "reconocedor.y"
                                                           { (yyval.yynodo) = new_tree_node(PYC, ";", '0', 0, 0.0, new_tree_node(PRINT, "print", '0', 0, 0.0, (yyvsp[0].yynodo), NULL, NULL,NULL), NULL, NULL,NULL); }
#line 1560 "reconocedor.tab.c"
    break;

  case 29: /* stmt: RETRN expr  */
#line 282 "reconocedor.y"
                                                           { char c = expr_value_type((yyvsp[0].yynodo)); (yyval.yynodo) = new_tree_node(RETRN, "return", c, 0, 0.0, (yyvsp[0].yynodo), NULL, NULL,NULL); }
#line 1566 "reconocedor.tab.c"
    break;

  case 30: /* stmt: BEGINI opt_stmts END  */
#line 283 "reconocedor.y"
                                                           { (yyval.yynodo) = (yyvsp[-1].yynodo); }
#line 1572 "reconocedor.tab.c"
    break;

  case 31: /* opt_stmts: %empty  */
#line 287 "reconocedor.y"
                                    { (yyval.yynodo) = NULL; }
#line 1578 "reconocedor.tab.c"
    break;

  case 32: /* opt_stmts: stmt_lst  */
#line 288 "reconocedor.y"
                                                               { (yyval.yynodo) = (yyvsp[0].yynodo); }
#line 1584 "reconocedor.tab.c"
    break;

  case 33: /* stmt_lst: stmt  */
#line 291 "reconocedor.y"
                                                               { (yyval.yynodo) = (yyvsp[0].yynodo); }
#line 1590 "reconocedor.tab.c"
    break;

  case 34: /* stmt_lst: stmt PCOMA stmt_lst  */
#line 292 "reconocedor.y"
                                                               { (yyvsp[-2].yynodo) -> sig = (yyvsp[0].yynodo), (yyval.yynodo) = (yyvsp[-2].yynodo); }
#line 1596 "reconocedor.tab.c"
    break;

  case 35: /* expr: expr SUMA term  */
#line 295 "reconocedor.y"
                                                               { char c1 = revision_tipos((yyvsp[-2].yynodo)); if (c1 != revision_tipos((yyvsp[0].yynodo))) { yyerror("Tipos incompatibles"); } (yyval.yynodo) = new_tree_node(SUMA, "+", c1, 0, 0.0, (yyvsp[-2].yynodo), (yyvsp[0].yynodo), NULL,NULL); }
#line 1602 "reconocedor.tab.c"
    break;

  case 36: /* expr: expr RESTA term  */
#line 296 "reconocedor.y"
                                                               { char c1 = revision_tipos((yyvsp[-2].yynodo)); if (c1 != revision_tipos((yyvsp[0].yynodo))) { yyerror("Tipos incompatibles"); } (yyval.yynodo) = new_tree_node(RESTA, "-", c1, 0, 0.0, (yyvsp[-2].yynodo), (yyvsp[0].yynodo), NULL,NULL); }
#line 1608 "reconocedor.tab.c"
    break;

  case 37: /* expr: term  */
#line 297 "reconocedor.y"
            {(yyval.yynodo) = (yyvsp[0].yynodo);}
#line 1614 "reconocedor.tab.c"
    break;

  case 38: /* term: term MULTI factor  */
#line 300 "reconocedor.y"
                                                               { char c1 = revision_tipos((yyvsp[-2].yynodo)); if (c1 != revision_tipos((yyvsp[0].yynodo))) { yyerror("Tipos incompatibles"); } (yyval.yynodo) = new_tree_node(MULTI, "*", c1, 0, 0.0, (yyvsp[-2].yynodo), (yyvsp[0].yynodo), NULL,NULL); }
#line 1620 "reconocedor.tab.c"
    break;

  case 39: /* term: term DIVIDE factor  */
#line 301 "reconocedor.y"
                                                               { char c1 = revision_tipos((yyvsp[-2].yynodo)); if (c1 != revision_tipos((yyvsp[0].yynodo))) { yyerror("Tipos incompatibles"); } (yyval.yynodo) = new_tree_node(DIVIDE, "/", c1, 0, 0.0, (yyvsp[-2].yynodo), (yyvsp[0].yynodo), NULL,NULL); }
#line 1626 "reconocedor.tab.c"
    break;

  case 40: /* term: factor  */
#line 302 "reconocedor.y"
                    {(yyval.yynodo) = (yyvsp[0].yynodo);}
#line 1632 "reconocedor.tab.c"
    break;

  case 41: /* factor: PARENI expr PAREND  */
#line 305 "reconocedor.y"
                                                               { (yyval.yynodo) = (yyvsp[-1].yynodo); }
#line 1638 "reconocedor.tab.c"
    break;

  case 42: /* factor: IDF  */
#line 306 "reconocedor.y"
                                                           {  SYM * n = NULL; if (amb == 0){n = buscar_simbolo_fpar((yyvsp[0].yyid)); }else{n = buscar_simbolo((yyvsp[0].yyid)); }  if (n == NULL) { yyerror("Variable no declarada."); } (yyval.yynodo) = new_tree_node(VAR, (yyvsp[0].yyid), '0', 0, 0.0, NULL, NULL, NULL,n); }
#line 1644 "reconocedor.tab.c"
    break;

  case 43: /* factor: NINT  */
#line 307 "reconocedor.y"
                                                               { (yyval.yynodo) = new_tree_node(CONS, "int", 'i', (yyvsp[0].yyint), 0, NULL, NULL, NULL, NULL); }
#line 1650 "reconocedor.tab.c"
    break;

  case 44: /* factor: NFLOAT  */
#line 308 "reconocedor.y"
                                                                 { (yyval.yynodo) = new_tree_node(CONS, "float", 'f', 0, (yyvsp[0].yyfloat), NULL, NULL, NULL, NULL); }
#line 1656 "reconocedor.tab.c"
    break;

  case 45: /* factor: IDF PARENI opt_exprs PAREND  */
#line 309 "reconocedor.y"
                                                              {  SYM * n = buscar_simbolo_f((yyvsp[-3].yyid)); if (n == NULL) { yyerror("funci??n no declarada."); } 
         (yyval.yynodo) = new_tree_node(CALL, (yyvsp[-3].yyid), '0', 0, 0.0, (yyvsp[-1].yynodo),NULL, NULL,n); }
#line 1663 "reconocedor.tab.c"
    break;

  case 46: /* opt_exprs: %empty  */
#line 314 "reconocedor.y"
           {(yyval.yynodo) = NULL;}
#line 1669 "reconocedor.tab.c"
    break;

  case 47: /* opt_exprs: expr_lst  */
#line 315 "reconocedor.y"
           {(yyval.yynodo) = (yyvsp[0].yynodo);}
#line 1675 "reconocedor.tab.c"
    break;

  case 48: /* expr_lst: expr COMA expr_lst  */
#line 318 "reconocedor.y"
                             {(yyvsp[-2].yynodo) -> sig = (yyvsp[0].yynodo), (yyval.yynodo) = (yyvsp[-2].yynodo);}
#line 1681 "reconocedor.tab.c"
    break;

  case 49: /* expr_lst: expr  */
#line 319 "reconocedor.y"
                {(yyval.yynodo) = (yyvsp[0].yynodo);}
#line 1687 "reconocedor.tab.c"
    break;

  case 50: /* expresion: expr MENORQ expr  */
#line 321 "reconocedor.y"
                                                                { char c1 = revision_tipos((yyvsp[-2].yynodo)); if (c1 != revision_tipos((yyvsp[0].yynodo))) { yyerror("Tipos incompatibles"); } (yyval.yynodo) = new_tree_node(MENORQ, "<", c1, 0, 0.0, (yyvsp[-2].yynodo), (yyvsp[0].yynodo), NULL,NULL); }
#line 1693 "reconocedor.tab.c"
    break;

  case 51: /* expresion: expr MAYORQ expr  */
#line 322 "reconocedor.y"
                                                                { char c1 = revision_tipos((yyvsp[-2].yynodo)); if (c1 != revision_tipos((yyvsp[0].yynodo))) { yyerror("Tipos incompatibles"); } (yyval.yynodo) = new_tree_node(MAYORQ, ">", c1, 0, 0.0, (yyvsp[-2].yynodo), (yyvsp[0].yynodo), NULL,NULL); }
#line 1699 "reconocedor.tab.c"
    break;

  case 52: /* expresion: expr EQUAL expr  */
#line 323 "reconocedor.y"
                                                               { char c1 = revision_tipos((yyvsp[-2].yynodo)); if (c1 != revision_tipos((yyvsp[0].yynodo))) { yyerror("Tipos incompatibles"); } (yyval.yynodo) = new_tree_node(EQUAL, "=", c1, 0, 0.0, (yyvsp[-2].yynodo), (yyvsp[0].yynodo), NULL,NULL); }
#line 1705 "reconocedor.tab.c"
    break;

  case 53: /* expresion: expr MENORIQ expr  */
#line 324 "reconocedor.y"
                                                                 { char c1 = revision_tipos((yyvsp[-2].yynodo)); if (c1 != revision_tipos((yyvsp[0].yynodo))) { yyerror("Tipos incompatibles"); } (yyval.yynodo) = new_tree_node(MENORIQ, "<=", c1, 0, 0.0, (yyvsp[-2].yynodo), (yyvsp[0].yynodo), NULL,NULL); }
#line 1711 "reconocedor.tab.c"
    break;

  case 54: /* expresion: expr MAYORIQ expr  */
#line 325 "reconocedor.y"
                                                                 { char c1 = revision_tipos((yyvsp[-2].yynodo)); if (c1 != revision_tipos((yyvsp[0].yynodo))) { yyerror("Tipos incompatibles"); } (yyval.yynodo) = new_tree_node(MAYORIQ, ">=", c1, 0, 0.0, (yyvsp[-2].yynodo), (yyvsp[0].yynodo), NULL,NULL); }
#line 1717 "reconocedor.tab.c"
    break;


#line 1721 "reconocedor.tab.c"

      default: break;
    }
  /* User semantic actions sometimes alter yychar, and that requires
     that yytoken be updated with the new translation.  We take the
     approach of translating immediately before every use of yytoken.
     One alternative is translating here after every semantic action,
     but that translation would be missed if the semantic action invokes
     YYABORT, YYACCEPT, or YYERROR immediately after altering yychar or
     if it invokes YYBACKUP.  In the case of YYABORT or YYACCEPT, an
     incorrect destructor might then be invoked immediately.  In the
     case of YYERROR or YYBACKUP, subsequent parser actions might lead
     to an incorrect destructor call or verbose syntax error message
     before the lookahead is translated.  */
  YY_SYMBOL_PRINT ("-> $$ =", YY_CAST (yysymbol_kind_t, yyr1[yyn]), &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;

  *++yyvsp = yyval;

  /* Now 'shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */
  {
    const int yylhs = yyr1[yyn] - YYNTOKENS;
    const int yyi = yypgoto[yylhs] + *yyssp;
    yystate = (0 <= yyi && yyi <= YYLAST && yycheck[yyi] == *yyssp
               ? yytable[yyi]
               : yydefgoto[yylhs]);
  }

  goto yynewstate;


/*--------------------------------------.
| yyerrlab -- here on detecting error.  |
`--------------------------------------*/
yyerrlab:
  /* Make sure we have latest lookahead translation.  See comments at
     user semantic actions for why this is necessary.  */
  yytoken = yychar == YYEMPTY ? YYSYMBOL_YYEMPTY : YYTRANSLATE (yychar);
  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
      yyerror (YY_("syntax error"));
    }

  if (yyerrstatus == 3)
    {
      /* If just tried and failed to reuse lookahead token after an
         error, discard it.  */

      if (yychar <= YYEOF)
        {
          /* Return failure if at end of input.  */
          if (yychar == YYEOF)
            YYABORT;
        }
      else
        {
          yydestruct ("Error: discarding",
                      yytoken, &yylval);
          yychar = YYEMPTY;
        }
    }

  /* Else will try to reuse lookahead token after shifting the error
     token.  */
  goto yyerrlab1;


/*---------------------------------------------------.
| yyerrorlab -- error raised explicitly by YYERROR.  |
`---------------------------------------------------*/
yyerrorlab:
  /* Pacify compilers when the user code never invokes YYERROR and the
     label yyerrorlab therefore never appears in user code.  */
  if (0)
    YYERROR;

  /* Do not reclaim the symbols of the rule whose action triggered
     this YYERROR.  */
  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);
  yystate = *yyssp;
  goto yyerrlab1;


/*-------------------------------------------------------------.
| yyerrlab1 -- common code for both syntax error and YYERROR.  |
`-------------------------------------------------------------*/
yyerrlab1:
  yyerrstatus = 3;      /* Each real token shifted decrements this.  */

  /* Pop stack until we find a state that shifts the error token.  */
  for (;;)
    {
      yyn = yypact[yystate];
      if (!yypact_value_is_default (yyn))
        {
          yyn += YYSYMBOL_YYerror;
          if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYSYMBOL_YYerror)
            {
              yyn = yytable[yyn];
              if (0 < yyn)
                break;
            }
        }

      /* Pop the current state because it cannot handle the error token.  */
      if (yyssp == yyss)
        YYABORT;


      yydestruct ("Error: popping",
                  YY_ACCESSING_SYMBOL (yystate), yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END


  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", YY_ACCESSING_SYMBOL (yyn), yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturn;


/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturn;


#if !defined yyoverflow
/*-------------------------------------------------.
| yyexhaustedlab -- memory exhaustion comes here.  |
`-------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  goto yyreturn;
#endif


/*-------------------------------------------------------.
| yyreturn -- parsing is finished, clean up and return.  |
`-------------------------------------------------------*/
yyreturn:
  if (yychar != YYEMPTY)
    {
      /* Make sure we have latest lookahead translation.  See comments at
         user semantic actions for why this is necessary.  */
      yytoken = YYTRANSLATE (yychar);
      yydestruct ("Cleanup: discarding lookahead",
                  yytoken, &yylval);
    }
  /* Do not reclaim the symbols of the rule whose action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
                  YY_ACCESSING_SYMBOL (+*yyssp), yyvsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif

  return yyresult;
}

#line 328 "reconocedor.y"


int yyerror(char const * s)
{
   fprintf(stderr, "Error en la linea %i: %s\n", line, s);
   exit(1);
}

void main(int argc, char *argv[])
{
   yyin = fopen(argv[1], "r");

//limpieza de tablas
   tabla_simb();
   
   tabla_simbf();
   
   tabla_simbf_par();
   yyparse();
  //ejecutar arbol
   check_tree(tree);
  // imprimir_sym(); imprimir tabla de simbolos
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
      } // llamada a funci??nrevision_tipos(AS

   else if (n -> node_type == VAR) { 
      return n -> simb -> value_type;
      
   }
      else if (n -> node_type == PARS) { 
      return n -> simb -> value_type;
      
   } // parametro de funcion
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


void igualar_params(ASR* in_par,ASR* params_final){

ASR * in = in_par;
ASR * out = params_final;

   while((out != NULL)  ){
        if(in != NULL ){
              if(revision_tipos(out) == 'i'){
                  if(revision_tipos(in) == 'i'){
                    out  -> simb -> int_value = expr_int_value(in);
                  }  
                  else{
                  yyerror("Tipos incompatibles"); }
            }
          else{
          if(revision_tipos(in) == 'f'){
            out  -> simb -> float_value = expr_float_value(in);
          }
               else{
                      yyerror("Tipos incompatibles"); }
              
          }
                out = out -> sig; in = in -> sig;
        }else{
        
           yyerror("Faltan parametros en la funci??n");
        
        }

     

   }

}






//Execute tree nodes actions

void check_tree(ASR * root)
{
   ASR *parent = root; // ; node

   // NULL
   if (parent == NULL ) { return; }

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
   
         //ejecucion de funci??n

   if (parent -> node_type == EXEC)
      {     
            
            check_tree(parent -> derecha);
      }

      //retornar
   
   if (parent -> node_type == RETRN)
      {     

         if (expr_value_type(parent -> izquierda) == 'i'){

                retorno = expr_int_value(parent -> izquierda);
                return;
          }
          else{
                retorno = expr_float_value(parent -> izquierda);
                return;
          }
      }

   check_tree(parent -> sig);
}

//valor entero de expr
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
      

      
      
     ASR * aux =  search_node_tree(tree_fun, root -> simb -> name);
     igualar_params(root -> izquierda,aux -> izquierda);
     check_tree(aux -> derecha);

 
     return retorno;
     
  
}
}

// valor flotante de expr

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
      
      ASR * aux =  search_node_tree(tree_fun, root -> simb -> name);
     igualar_params(root -> izquierda,aux -> izquierda);
     check_tree(aux -> derecha);
     return retorno;
  
   }

}


// value type de expresion
char expr_value_type(ASR * root)
{
   if (root == NULL) return '0';
   if (root -> node_type == VAR) {  return root -> simb -> value_type;}
   if (root -> node_type == PARS) {  return root -> simb -> value_type;}
   if (root -> node_type == CONS) {  return root -> simb -> value_type;}
   else { return root -> value_type; }
}










