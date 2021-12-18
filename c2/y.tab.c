/* A Bison parser, made by GNU Bison 2.3.  */

/* Skeleton implementation for Bison's Yacc-like parsers in C

   Copyright (C) 1984, 1989, 1990, 2000, 2001, 2002, 2003, 2004, 2005, 2006
   Free Software Foundation, Inc.

   This program is free software; you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation; either version 2, or (at your option)
   any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program; if not, write to the Free Software
   Foundation, Inc., 51 Franklin Street, Fifth Floor,
   Boston, MA 02110-1301, USA.  */

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

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output.  */
#define YYBISON 1

/* Bison version.  */
#define YYBISON_VERSION "2.3"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Using locations.  */
#define YYLSP_NEEDED 0



/* Tokens.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
   /* Put the tokens into the symbol table, so that GDB and other debuggers
      know about them.  */
   enum yytokentype {
     TOK_IDENTIFICADOR = 258,
     TOK_CONSTANTE_ENTERA = 259,
     TOK_CONSTANTE_REAL = 260,
     TOK_MAIN = 261,
     TOK_INT = 262,
     TOK_BOOLEAN = 263,
     TOK_ARRAY = 264,
     TOK_FUNCTION = 265,
     TOK_IF = 266,
     TOK_ELSE = 267,
     TOK_WHILE = 268,
     TOK_SCANF = 269,
     TOK_PRINTF = 270,
     TOK_RETURN = 271,
     TOK_PUNTOYCOMA = 272,
     TOK_COMA = 273,
     TOK_PARENTESISIZQUIERDO = 274,
     TOK_PARENTESISDERECHO = 275,
     TOK_CORCHETEIZQUIERDO = 276,
     TOK_CORCHETEDERECHO = 277,
     TOK_LLAVEIZQUIERDA = 278,
     TOK_LLAVEDERECHA = 279,
     TOK_ASIGNACION = 280,
     TOK_MAS = 281,
     TOK_MENOS = 282,
     TOK_DIVISION = 283,
     TOK_ASTERISCO = 284,
     TOK_AND = 285,
     TOK_OR = 286,
     TOK_NOT = 287,
     TOK_IGUAL = 288,
     TOK_DISTINTO = 289,
     TOK_MENORIGUAL = 290,
     TOK_MAYORIGUAL = 291,
     TOK_MENOR = 292,
     TOK_MAYOR = 293,
     TOK_TRUE = 294,
     TOK_FALSE = 295,
     TOK_ERROR = 296
   };
#endif
/* Tokens.  */
#define TOK_IDENTIFICADOR 258
#define TOK_CONSTANTE_ENTERA 259
#define TOK_CONSTANTE_REAL 260
#define TOK_MAIN 261
#define TOK_INT 262
#define TOK_BOOLEAN 263
#define TOK_ARRAY 264
#define TOK_FUNCTION 265
#define TOK_IF 266
#define TOK_ELSE 267
#define TOK_WHILE 268
#define TOK_SCANF 269
#define TOK_PRINTF 270
#define TOK_RETURN 271
#define TOK_PUNTOYCOMA 272
#define TOK_COMA 273
#define TOK_PARENTESISIZQUIERDO 274
#define TOK_PARENTESISDERECHO 275
#define TOK_CORCHETEIZQUIERDO 276
#define TOK_CORCHETEDERECHO 277
#define TOK_LLAVEIZQUIERDA 278
#define TOK_LLAVEDERECHA 279
#define TOK_ASIGNACION 280
#define TOK_MAS 281
#define TOK_MENOS 282
#define TOK_DIVISION 283
#define TOK_ASTERISCO 284
#define TOK_AND 285
#define TOK_OR 286
#define TOK_NOT 287
#define TOK_IGUAL 288
#define TOK_DISTINTO 289
#define TOK_MENORIGUAL 290
#define TOK_MAYORIGUAL 291
#define TOK_MENOR 292
#define TOK_MAYOR 293
#define TOK_TRUE 294
#define TOK_FALSE 295
#define TOK_ERROR 296




/* Copy the first part of user declarations.  */
#line 1 "alfa.y"

#include <stdio.h>
#include "symbols_table/symbols_table.h"
#include "code_generation/generacion.h"
#include "alfa.h"
#include "y.tab.h"

extern FILE * yyout;
extern int yline;
extern int ycol;
extern int err_morf;
extern int yyleng;

int yylex();
void yyerror(const char *s);
void semantic_error(char * message);


/** GLOBAL VARIABLES **/
symbols_table *table;

int tipo_actual; /* INT or BOOLEAN */
int clase_actual; /* ESCALAR or VECTOR */
int tamanio_vector_actual = 1;
int funcion_retorno = 0;
int funcion_tipo;
int num_total_parametros = 0;
int num_total_var_locales = 0;
int etiqueta = 0;
int dentro_fun = 0; /* 1 si estamos dentro de la llamada de una funcion */
int pos_parametro = 0; /* solo para elementos de tipo parametro */ 
int pos_var_local = 0; /* solo para variables locales */
int num_arg_funcion = 0;




/* Enabling traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 0
#endif

/* Enabling the token table.  */
#ifndef YYTOKEN_TABLE
# define YYTOKEN_TABLE 0
#endif

#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
#line 39 "alfa.y"
{
    tipo_atributos atributos;
}
/* Line 193 of yacc.c.  */
#line 219 "y.tab.c"
	YYSTYPE;
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
# define YYSTYPE_IS_TRIVIAL 1
#endif



/* Copy the second part of user declarations.  */


/* Line 216 of yacc.c.  */
#line 232 "y.tab.c"

#ifdef short
# undef short
#endif

#ifdef YYTYPE_UINT8
typedef YYTYPE_UINT8 yytype_uint8;
#else
typedef unsigned char yytype_uint8;
#endif

#ifdef YYTYPE_INT8
typedef YYTYPE_INT8 yytype_int8;
#elif (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
typedef signed char yytype_int8;
#else
typedef short int yytype_int8;
#endif

#ifdef YYTYPE_UINT16
typedef YYTYPE_UINT16 yytype_uint16;
#else
typedef unsigned short int yytype_uint16;
#endif

#ifdef YYTYPE_INT16
typedef YYTYPE_INT16 yytype_int16;
#else
typedef short int yytype_int16;
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif ! defined YYSIZE_T && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned int
# endif
#endif

#define YYSIZE_MAXIMUM ((YYSIZE_T) -1)

#ifndef YY_
# if defined YYENABLE_NLS && YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* INFRINGES ON USER NAME SPACE */
#   define YY_(msgid) dgettext ("bison-runtime", msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(msgid) msgid
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(e) ((void) (e))
#else
# define YYUSE(e) /* empty */
#endif

/* Identity function, used to suppress warnings about constant conditions.  */
#ifndef lint
# define YYID(n) (n)
#else
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static int
YYID (int i)
#else
static int
YYID (i)
    int i;
#endif
{
  return i;
}
#endif

#if ! defined yyoverflow || YYERROR_VERBOSE

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
#    if ! defined _ALLOCA_H && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#     ifndef _STDLIB_H
#      define _STDLIB_H 1
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's `empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (YYID (0))
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
#  if (defined __cplusplus && ! defined _STDLIB_H \
       && ! ((defined YYMALLOC || defined malloc) \
	     && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef _STDLIB_H
#    define _STDLIB_H 1
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
void free (void *); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
# endif
#endif /* ! defined yyoverflow || YYERROR_VERBOSE */


#if (! defined yyoverflow \
     && (! defined __cplusplus \
	 || (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yytype_int16 yyss;
  YYSTYPE yyvs;
  };

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (sizeof (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (sizeof (yytype_int16) + sizeof (YYSTYPE)) \
      + YYSTACK_GAP_MAXIMUM)

/* Copy COUNT objects from FROM to TO.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(To, From, Count) \
      __builtin_memcpy (To, From, (Count) * sizeof (*(From)))
#  else
#   define YYCOPY(To, From, Count)		\
      do					\
	{					\
	  YYSIZE_T yyi;				\
	  for (yyi = 0; yyi < (Count); yyi++)	\
	    (To)[yyi] = (From)[yyi];		\
	}					\
      while (YYID (0))
#  endif
# endif

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack)					\
    do									\
      {									\
	YYSIZE_T yynewbytes;						\
	YYCOPY (&yyptr->Stack, Stack, yysize);				\
	Stack = &yyptr->Stack;						\
	yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
	yyptr += yynewbytes / sizeof (*yyptr);				\
      }									\
    while (YYID (0))

#endif

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  3
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   156

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  42
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  40
/* YYNRULES -- Number of rules.  */
#define YYNRULES  78
/* YYNRULES -- Number of states.  */
#define YYNSTATES  147

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   296

#define YYTRANSLATE(YYX)						\
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[YYLEX] -- Bison symbol number corresponding to YYLEX.  */
static const yytype_uint8 yytranslate[] =
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
      35,    36,    37,    38,    39,    40,    41
};

#if YYDEBUG
/* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
   YYRHS.  */
static const yytype_uint8 yyprhs[] =
{
       0,     0,     3,    13,    14,    15,    16,    18,    21,    25,
      27,    29,    31,    33,    35,    41,    43,    47,    50,    51,
      55,    62,    66,    69,    70,    74,    75,    78,    80,    82,
      83,    85,    88,    91,    93,    95,    97,    99,   101,   103,
     105,   109,   113,   118,   126,   138,   146,   149,   152,   155,
     159,   163,   167,   171,   174,   178,   182,   185,   187,   189,
     193,   197,   199,   204,   207,   208,   212,   213,   217,   221,
     225,   228,   232,   236,   238,   240,   242,   244,   246
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int8 yyrhs[] =
{
      43,     0,    -1,    44,     6,    23,    47,    45,    54,    46,
      63,    24,    -1,    -1,    -1,    -1,    48,    -1,    48,    47,
      -1,    49,    53,    17,    -1,    50,    -1,    52,    -1,    51,
      -1,     7,    -1,     8,    -1,     9,    51,    21,     4,    22,
      -1,    81,    -1,    81,    18,    53,    -1,    55,    54,    -1,
      -1,    56,    63,    24,    -1,    57,    19,    58,    20,    23,
      62,    -1,    10,    51,     3,    -1,    60,    59,    -1,    -1,
      17,    60,    59,    -1,    -1,    51,    61,    -1,     3,    -1,
      47,    -1,    -1,    64,    -1,    64,    63,    -1,    65,    17,
      -1,    66,    -1,    67,    -1,    71,    -1,    72,    -1,    73,
      -1,    69,    -1,    70,    -1,     3,    25,    74,    -1,    68,
      25,    74,    -1,    81,    21,    74,    22,    -1,    11,    19,
      74,    20,    23,    63,    24,    -1,    11,    19,    74,    20,
      23,    63,    24,    12,    23,    63,    24,    -1,    13,    19,
      74,    20,    23,    63,    24,    -1,    14,    81,    -1,    15,
      74,    -1,    16,    74,    -1,    74,    26,    74,    -1,    74,
      27,    74,    -1,    74,    28,    74,    -1,    74,    29,    74,
      -1,    27,    74,    -1,    74,    30,    74,    -1,    74,    31,
      74,    -1,    32,    74,    -1,    81,    -1,    78,    -1,    19,
      74,    20,    -1,    19,    77,    20,    -1,    68,    -1,    81,
      19,    75,    20,    -1,    74,    76,    -1,    -1,    18,    74,
      76,    -1,    -1,    74,    33,    74,    -1,    74,    34,    74,
      -1,    74,    35,    74,    -1,    74,    36,    -1,    74,    37,
      74,    -1,    74,    38,    74,    -1,    79,    -1,    80,    -1,
      39,    -1,    40,    -1,     4,    -1,     3,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,   110,   110,   125,   133,   144,   148,   151,   155,   159,
     163,   168,   172,   176,   181,   192,   195,   199,   202,   206,
     229,   244,   264,   267,   271,   274,   278,   284,   298,   301,
     305,   308,   312,   315,   319,   322,   325,   328,   332,   335,
     339,   367,   387,   391,   394,   398,   402,   406,   410,   414,
     417,   420,   423,   426,   429,   432,   435,   438,   442,   445,
     448,   451,   454,   458,   461,   465,   468,   472,   475,   478,
     481,   484,   487,   491,   494,   498,   501,   505,   509
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || YYTOKEN_TABLE
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "TOK_IDENTIFICADOR",
  "TOK_CONSTANTE_ENTERA", "TOK_CONSTANTE_REAL", "TOK_MAIN", "TOK_INT",
  "TOK_BOOLEAN", "TOK_ARRAY", "TOK_FUNCTION", "TOK_IF", "TOK_ELSE",
  "TOK_WHILE", "TOK_SCANF", "TOK_PRINTF", "TOK_RETURN", "TOK_PUNTOYCOMA",
  "TOK_COMA", "TOK_PARENTESISIZQUIERDO", "TOK_PARENTESISDERECHO",
  "TOK_CORCHETEIZQUIERDO", "TOK_CORCHETEDERECHO", "TOK_LLAVEIZQUIERDA",
  "TOK_LLAVEDERECHA", "TOK_ASIGNACION", "TOK_MAS", "TOK_MENOS",
  "TOK_DIVISION", "TOK_ASTERISCO", "TOK_AND", "TOK_OR", "TOK_NOT",
  "TOK_IGUAL", "TOK_DISTINTO", "TOK_MENORIGUAL", "TOK_MAYORIGUAL",
  "TOK_MENOR", "TOK_MAYOR", "TOK_TRUE", "TOK_FALSE", "TOK_ERROR",
  "$accept", "programa", "inicioTabla", "write_before_main",
  "write_inicio_main", "declaraciones", "declaracion", "clase",
  "clase_escalar", "tipo", "clase_vector", "identificadores", "funciones",
  "funcion", "fn_declaration", "fn_name", "parametros_funcion",
  "resto_parametros_funcion", "parametro_funcion", "idpf",
  "declaraciones_funcion", "sentencias", "sentencia", "sentencia_simple",
  "bloque", "asignacion", "elemento_vector", "condicional", "bucle",
  "lectura", "escritura", "retorno_funcion", "exp", "lista_expresiones",
  "resto_lista_expresiones", "comparacion", "constante",
  "constante_logica", "constante_entera", "identificador", 0
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[YYLEX-NUM] -- Internal token number corresponding to
   token YYLEX-NUM.  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    42,    43,    44,    45,    46,    47,    47,    48,    49,
      49,    50,    51,    51,    52,    53,    53,    54,    54,    55,
      56,    57,    58,    58,    59,    59,    60,    61,    62,    62,
      63,    63,    64,    64,    65,    65,    65,    65,    66,    66,
      67,    67,    68,    69,    69,    70,    71,    72,    73,    74,
      74,    74,    74,    74,    74,    74,    74,    74,    74,    74,
      74,    74,    74,    75,    75,    76,    76,    77,    77,    77,
      77,    77,    77,    78,    78,    79,    79,    80,    81
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     9,     0,     0,     0,     1,     2,     3,     1,
       1,     1,     1,     1,     5,     1,     3,     2,     0,     3,
       6,     3,     2,     0,     3,     0,     2,     1,     1,     0,
       1,     2,     2,     1,     1,     1,     1,     1,     1,     1,
       3,     3,     4,     7,    11,     7,     2,     2,     2,     3,
       3,     3,     3,     2,     3,     3,     2,     1,     1,     3,
       3,     1,     4,     2,     0,     3,     0,     3,     3,     3,
       2,     3,     3,     1,     1,     1,     1,     1,     1
};

/* YYDEFACT[STATE-NAME] -- Default rule to reduce with in state
   STATE-NUM when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       3,     0,     0,     1,     0,     0,    12,    13,     0,     4,
       6,     0,     9,    11,    10,     0,    18,     7,    78,     0,
      15,     0,     0,     5,    18,     0,     0,     8,     0,     0,
       0,     0,    17,    78,     0,     0,     0,     0,     0,     0,
      30,     0,    33,    34,     0,    38,    39,    35,    36,    37,
       0,    23,    16,    14,    21,     0,     0,     0,     0,    46,
      77,     0,     0,     0,    75,    76,    61,    47,    58,    73,
      74,    57,    48,    19,    31,    32,     0,     0,     0,     0,
      25,     2,    40,     0,     0,     0,     0,    53,    56,     0,
       0,     0,     0,     0,     0,    64,    41,     0,    27,    26,
       0,     0,    22,     0,     0,    59,     0,     0,     0,    70,
       0,     0,    60,    49,    50,    51,    52,    54,    55,    66,
       0,    42,    29,    25,     0,     0,    67,    68,    69,    71,
      72,     0,    63,    62,    28,    20,    24,     0,     0,    66,
      43,    45,    65,     0,     0,     0,    44
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     1,     2,    16,    31,     9,    10,    11,    12,    13,
      14,    19,    23,    24,    25,    26,    79,   102,    80,    99,
     135,    39,    40,    41,    42,    43,    66,    45,    46,    47,
      48,    49,    67,   120,   132,    86,    68,    69,    70,    71
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -30
static const yytype_int8 yypact[] =
{
     -30,     3,     0,   -30,   -10,     1,   -30,   -30,    14,   -30,
       1,    12,   -30,   -30,   -30,    13,     8,   -30,   -30,    44,
      53,    72,    14,   -30,     8,    59,    58,   -30,    12,    56,
      76,    59,   -30,    61,    68,    69,    12,    20,    20,    73,
      59,    82,   -30,   -30,    77,   -30,   -30,   -30,   -30,   -30,
      83,    14,   -30,   -30,   -30,    79,    20,    20,    20,   -30,
     -30,    20,    20,    20,   -30,   -30,   -30,    80,   -30,   -30,
     -30,    19,    80,   -30,   -30,   -30,    20,    20,   109,    97,
     102,   -30,    80,    63,   120,   101,    98,    -2,   -30,    20,
      20,    20,    20,    20,    20,    20,    80,    27,   -30,   -30,
      99,    14,   -30,   100,   103,   -30,    20,    20,    20,   -30,
      20,    20,   -30,    -2,    -2,   -30,   -30,   -30,    -2,    15,
     104,   -30,     1,   102,    59,    59,    80,    80,    80,    80,
      80,    20,   -30,   -30,   -30,   -30,   -30,   117,   118,    15,
     113,   -30,   -30,   121,    59,   119,   -30
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
     -30,   -30,   -30,   -30,   -30,    -6,   -30,   -30,   -30,    -3,
     -30,   124,   129,   -30,   -30,   -30,   -30,    22,    54,   -30,
     -30,   -29,   -30,   -30,   -30,   -30,   -24,   -30,   -30,   -30,
     -30,   -30,   -26,   -30,    17,   -30,   -30,   -30,   -30,   -11
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -1
static const yytype_uint8 yytable[] =
{
      20,    44,    55,     3,    17,    15,     4,    44,     6,     7,
       8,    74,    72,     5,    50,    18,    44,    20,    22,    30,
      50,     6,     7,    18,    60,    59,    91,    92,    93,    50,
      82,    83,    84,   131,    21,    85,    87,    88,    95,    61,
      77,    89,    90,    91,    92,    93,    94,    62,    78,   121,
      96,    97,    63,    89,    90,    91,    92,    93,    94,    64,
      65,    27,    33,   113,   114,   115,   116,   117,   118,   119,
      34,    28,    35,    36,    37,    38,    29,    51,    53,    54,
     126,   127,   128,   103,   129,   130,    56,    57,    58,    89,
      90,    91,    92,    93,    94,   137,   138,    73,    78,    75,
      44,    44,    76,    81,    77,   139,    89,    90,    91,    92,
      93,    94,    98,    50,    50,   145,   134,   100,   112,   101,
      44,   105,   122,   124,   133,   143,   125,    89,    90,    91,
      92,    93,    94,    50,   106,   107,   108,   109,   110,   111,
     104,   140,   141,   146,   144,   136,    89,    90,    91,    92,
      93,    94,    52,    32,     0,   123,   142
};

static const yytype_int16 yycheck[] =
{
      11,    25,    31,     0,    10,     8,     6,    31,     7,     8,
       9,    40,    38,    23,    25,     3,    40,    28,    10,    22,
      31,     7,     8,     3,     4,    36,    28,    29,    30,    40,
      56,    57,    58,    18,    21,    61,    62,    63,    19,    19,
      21,    26,    27,    28,    29,    30,    31,    27,    51,    22,
      76,    77,    32,    26,    27,    28,    29,    30,    31,    39,
      40,    17,     3,    89,    90,    91,    92,    93,    94,    95,
      11,    18,    13,    14,    15,    16,     4,    19,    22,     3,
     106,   107,   108,    20,   110,   111,    25,    19,    19,    26,
      27,    28,    29,    30,    31,   124,   125,    24,   101,    17,
     124,   125,    25,    24,    21,   131,    26,    27,    28,    29,
      30,    31,     3,   124,   125,   144,   122,    20,    20,    17,
     144,    20,    23,    23,    20,    12,    23,    26,    27,    28,
      29,    30,    31,   144,    33,    34,    35,    36,    37,    38,
      20,    24,    24,    24,    23,   123,    26,    27,    28,    29,
      30,    31,    28,    24,    -1,   101,   139
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    43,    44,     0,     6,    23,     7,     8,     9,    47,
      48,    49,    50,    51,    52,    51,    45,    47,     3,    53,
      81,    21,    10,    54,    55,    56,    57,    17,    18,     4,
      51,    46,    54,     3,    11,    13,    14,    15,    16,    63,
      64,    65,    66,    67,    68,    69,    70,    71,    72,    73,
      81,    19,    53,    22,     3,    63,    25,    19,    19,    81,
       4,    19,    27,    32,    39,    40,    68,    74,    78,    79,
      80,    81,    74,    24,    63,    17,    25,    21,    51,    58,
      60,    24,    74,    74,    74,    74,    77,    74,    74,    26,
      27,    28,    29,    30,    31,    19,    74,    74,     3,    61,
      20,    17,    59,    20,    20,    20,    33,    34,    35,    36,
      37,    38,    20,    74,    74,    74,    74,    74,    74,    74,
      75,    22,    23,    60,    23,    23,    74,    74,    74,    74,
      74,    18,    76,    20,    47,    62,    59,    63,    63,    74,
      24,    24,    76,    12,    23,    63,    24
};

#define yyerrok		(yyerrstatus = 0)
#define yyclearin	(yychar = YYEMPTY)
#define YYEMPTY		(-2)
#define YYEOF		0

#define YYACCEPT	goto yyacceptlab
#define YYABORT		goto yyabortlab
#define YYERROR		goto yyerrorlab


/* Like YYERROR except do call yyerror.  This remains here temporarily
   to ease the transition to the new meaning of YYERROR, for GCC.
   Once GCC version 2 has supplanted version 1, this can go.  */

#define YYFAIL		goto yyerrlab

#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)					\
do								\
  if (yychar == YYEMPTY && yylen == 1)				\
    {								\
      yychar = (Token);						\
      yylval = (Value);						\
      yytoken = YYTRANSLATE (yychar);				\
      YYPOPSTACK (1);						\
      goto yybackup;						\
    }								\
  else								\
    {								\
      yyerror (YY_("syntax error: cannot back up")); \
      YYERROR;							\
    }								\
while (YYID (0))


#define YYTERROR	1
#define YYERRCODE	256


/* YYLLOC_DEFAULT -- Set CURRENT to span from RHS[1] to RHS[N].
   If N is 0, then set CURRENT to the empty location which ends
   the previous symbol: RHS[0] (always defined).  */

#define YYRHSLOC(Rhs, K) ((Rhs)[K])
#ifndef YYLLOC_DEFAULT
# define YYLLOC_DEFAULT(Current, Rhs, N)				\
    do									\
      if (YYID (N))                                                    \
	{								\
	  (Current).first_line   = YYRHSLOC (Rhs, 1).first_line;	\
	  (Current).first_column = YYRHSLOC (Rhs, 1).first_column;	\
	  (Current).last_line    = YYRHSLOC (Rhs, N).last_line;		\
	  (Current).last_column  = YYRHSLOC (Rhs, N).last_column;	\
	}								\
      else								\
	{								\
	  (Current).first_line   = (Current).last_line   =		\
	    YYRHSLOC (Rhs, 0).last_line;				\
	  (Current).first_column = (Current).last_column =		\
	    YYRHSLOC (Rhs, 0).last_column;				\
	}								\
    while (YYID (0))
#endif


/* YY_LOCATION_PRINT -- Print the location on the stream.
   This macro was not mandated originally: define only if we know
   we won't break user code: when these are the locations we know.  */

#ifndef YY_LOCATION_PRINT
# if defined YYLTYPE_IS_TRIVIAL && YYLTYPE_IS_TRIVIAL
#  define YY_LOCATION_PRINT(File, Loc)			\
     fprintf (File, "%d.%d-%d.%d",			\
	      (Loc).first_line, (Loc).first_column,	\
	      (Loc).last_line,  (Loc).last_column)
# else
#  define YY_LOCATION_PRINT(File, Loc) ((void) 0)
# endif
#endif


/* YYLEX -- calling `yylex' with the right arguments.  */

#ifdef YYLEX_PARAM
# define YYLEX yylex (YYLEX_PARAM)
#else
# define YYLEX yylex ()
#endif

/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)			\
do {						\
  if (yydebug)					\
    YYFPRINTF Args;				\
} while (YYID (0))

# define YY_SYMBOL_PRINT(Title, Type, Value, Location)			  \
do {									  \
  if (yydebug)								  \
    {									  \
      YYFPRINTF (stderr, "%s ", Title);					  \
      yy_symbol_print (stderr,						  \
		  Type, Value); \
      YYFPRINTF (stderr, "\n");						  \
    }									  \
} while (YYID (0))


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

/*ARGSUSED*/
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
#else
static void
yy_symbol_value_print (yyoutput, yytype, yyvaluep)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
#endif
{
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyoutput, yytoknum[yytype], *yyvaluep);
# else
  YYUSE (yyoutput);
# endif
  switch (yytype)
    {
      default:
	break;
    }
}


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
#else
static void
yy_symbol_print (yyoutput, yytype, yyvaluep)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
#endif
{
  if (yytype < YYNTOKENS)
    YYFPRINTF (yyoutput, "token %s (", yytname[yytype]);
  else
    YYFPRINTF (yyoutput, "nterm %s (", yytname[yytype]);

  yy_symbol_value_print (yyoutput, yytype, yyvaluep);
  YYFPRINTF (yyoutput, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_stack_print (yytype_int16 *bottom, yytype_int16 *top)
#else
static void
yy_stack_print (bottom, top)
    yytype_int16 *bottom;
    yytype_int16 *top;
#endif
{
  YYFPRINTF (stderr, "Stack now");
  for (; bottom <= top; ++bottom)
    YYFPRINTF (stderr, " %d", *bottom);
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)				\
do {								\
  if (yydebug)							\
    yy_stack_print ((Bottom), (Top));				\
} while (YYID (0))


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_reduce_print (YYSTYPE *yyvsp, int yyrule)
#else
static void
yy_reduce_print (yyvsp, yyrule)
    YYSTYPE *yyvsp;
    int yyrule;
#endif
{
  int yynrhs = yyr2[yyrule];
  int yyi;
  unsigned long int yylno = yyrline[yyrule];
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %lu):\n",
	     yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      fprintf (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr, yyrhs[yyprhs[yyrule] + yyi],
		       &(yyvsp[(yyi + 1) - (yynrhs)])
		       		       );
      fprintf (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)		\
do {					\
  if (yydebug)				\
    yy_reduce_print (yyvsp, Rule); \
} while (YYID (0))

/* Nonzero means print parse trace.  It is left uninitialized so that
   multiple parsers can coexist.  */
int yydebug;
#else /* !YYDEBUG */
# define YYDPRINTF(Args)
# define YY_SYMBOL_PRINT(Title, Type, Value, Location)
# define YY_STACK_PRINT(Bottom, Top)
# define YY_REDUCE_PRINT(Rule)
#endif /* !YYDEBUG */


/* YYINITDEPTH -- initial size of the parser's stacks.  */
#ifndef	YYINITDEPTH
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



#if YYERROR_VERBOSE

# ifndef yystrlen
#  if defined __GLIBC__ && defined _STRING_H
#   define yystrlen strlen
#  else
/* Return the length of YYSTR.  */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static YYSIZE_T
yystrlen (const char *yystr)
#else
static YYSIZE_T
yystrlen (yystr)
    const char *yystr;
#endif
{
  YYSIZE_T yylen;
  for (yylen = 0; yystr[yylen]; yylen++)
    continue;
  return yylen;
}
#  endif
# endif

# ifndef yystpcpy
#  if defined __GLIBC__ && defined _STRING_H && defined _GNU_SOURCE
#   define yystpcpy stpcpy
#  else
/* Copy YYSRC to YYDEST, returning the address of the terminating '\0' in
   YYDEST.  */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static char *
yystpcpy (char *yydest, const char *yysrc)
#else
static char *
yystpcpy (yydest, yysrc)
    char *yydest;
    const char *yysrc;
#endif
{
  char *yyd = yydest;
  const char *yys = yysrc;

  while ((*yyd++ = *yys++) != '\0')
    continue;

  return yyd - 1;
}
#  endif
# endif

# ifndef yytnamerr
/* Copy to YYRES the contents of YYSTR after stripping away unnecessary
   quotes and backslashes, so that it's suitable for yyerror.  The
   heuristic is that double-quoting is unnecessary unless the string
   contains an apostrophe, a comma, or backslash (other than
   backslash-backslash).  YYSTR is taken from yytname.  If YYRES is
   null, do not copy; instead, return the length of what the result
   would have been.  */
static YYSIZE_T
yytnamerr (char *yyres, const char *yystr)
{
  if (*yystr == '"')
    {
      YYSIZE_T yyn = 0;
      char const *yyp = yystr;

      for (;;)
	switch (*++yyp)
	  {
	  case '\'':
	  case ',':
	    goto do_not_strip_quotes;

	  case '\\':
	    if (*++yyp != '\\')
	      goto do_not_strip_quotes;
	    /* Fall through.  */
	  default:
	    if (yyres)
	      yyres[yyn] = *yyp;
	    yyn++;
	    break;

	  case '"':
	    if (yyres)
	      yyres[yyn] = '\0';
	    return yyn;
	  }
    do_not_strip_quotes: ;
    }

  if (! yyres)
    return yystrlen (yystr);

  return yystpcpy (yyres, yystr) - yyres;
}
# endif

/* Copy into YYRESULT an error message about the unexpected token
   YYCHAR while in state YYSTATE.  Return the number of bytes copied,
   including the terminating null byte.  If YYRESULT is null, do not
   copy anything; just return the number of bytes that would be
   copied.  As a special case, return 0 if an ordinary "syntax error"
   message will do.  Return YYSIZE_MAXIMUM if overflow occurs during
   size calculation.  */
static YYSIZE_T
yysyntax_error (char *yyresult, int yystate, int yychar)
{
  int yyn = yypact[yystate];

  if (! (YYPACT_NINF < yyn && yyn <= YYLAST))
    return 0;
  else
    {
      int yytype = YYTRANSLATE (yychar);
      YYSIZE_T yysize0 = yytnamerr (0, yytname[yytype]);
      YYSIZE_T yysize = yysize0;
      YYSIZE_T yysize1;
      int yysize_overflow = 0;
      enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
      char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
      int yyx;

# if 0
      /* This is so xgettext sees the translatable formats that are
	 constructed on the fly.  */
      YY_("syntax error, unexpected %s");
      YY_("syntax error, unexpected %s, expecting %s");
      YY_("syntax error, unexpected %s, expecting %s or %s");
      YY_("syntax error, unexpected %s, expecting %s or %s or %s");
      YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s");
# endif
      char *yyfmt;
      char const *yyf;
      static char const yyunexpected[] = "syntax error, unexpected %s";
      static char const yyexpecting[] = ", expecting %s";
      static char const yyor[] = " or %s";
      char yyformat[sizeof yyunexpected
		    + sizeof yyexpecting - 1
		    + ((YYERROR_VERBOSE_ARGS_MAXIMUM - 2)
		       * (sizeof yyor - 1))];
      char const *yyprefix = yyexpecting;

      /* Start YYX at -YYN if negative to avoid negative indexes in
	 YYCHECK.  */
      int yyxbegin = yyn < 0 ? -yyn : 0;

      /* Stay within bounds of both yycheck and yytname.  */
      int yychecklim = YYLAST - yyn + 1;
      int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
      int yycount = 1;

      yyarg[0] = yytname[yytype];
      yyfmt = yystpcpy (yyformat, yyunexpected);

      for (yyx = yyxbegin; yyx < yyxend; ++yyx)
	if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR)
	  {
	    if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
	      {
		yycount = 1;
		yysize = yysize0;
		yyformat[sizeof yyunexpected - 1] = '\0';
		break;
	      }
	    yyarg[yycount++] = yytname[yyx];
	    yysize1 = yysize + yytnamerr (0, yytname[yyx]);
	    yysize_overflow |= (yysize1 < yysize);
	    yysize = yysize1;
	    yyfmt = yystpcpy (yyfmt, yyprefix);
	    yyprefix = yyor;
	  }

      yyf = YY_(yyformat);
      yysize1 = yysize + yystrlen (yyf);
      yysize_overflow |= (yysize1 < yysize);
      yysize = yysize1;

      if (yysize_overflow)
	return YYSIZE_MAXIMUM;

      if (yyresult)
	{
	  /* Avoid sprintf, as that infringes on the user's name space.
	     Don't have undefined behavior even if the translation
	     produced a string with the wrong number of "%s"s.  */
	  char *yyp = yyresult;
	  int yyi = 0;
	  while ((*yyp = *yyf) != '\0')
	    {
	      if (*yyp == '%' && yyf[1] == 's' && yyi < yycount)
		{
		  yyp += yytnamerr (yyp, yyarg[yyi++]);
		  yyf += 2;
		}
	      else
		{
		  yyp++;
		  yyf++;
		}
	    }
	}
      return yysize;
    }
}
#endif /* YYERROR_VERBOSE */


/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

/*ARGSUSED*/
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep)
#else
static void
yydestruct (yymsg, yytype, yyvaluep)
    const char *yymsg;
    int yytype;
    YYSTYPE *yyvaluep;
#endif
{
  YYUSE (yyvaluep);

  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  switch (yytype)
    {

      default:
	break;
    }
}


/* Prevent warnings from -Wmissing-prototypes.  */

#ifdef YYPARSE_PARAM
#if defined __STDC__ || defined __cplusplus
int yyparse (void *YYPARSE_PARAM);
#else
int yyparse ();
#endif
#else /* ! YYPARSE_PARAM */
#if defined __STDC__ || defined __cplusplus
int yyparse (void);
#else
int yyparse ();
#endif
#endif /* ! YYPARSE_PARAM */



/* The look-ahead symbol.  */
int yychar;

/* The semantic value of the look-ahead symbol.  */
YYSTYPE yylval;

/* Number of syntax errors so far.  */
int yynerrs;



/*----------.
| yyparse.  |
`----------*/

#ifdef YYPARSE_PARAM
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
int
yyparse (void *YYPARSE_PARAM)
#else
int
yyparse (YYPARSE_PARAM)
    void *YYPARSE_PARAM;
#endif
#else /* ! YYPARSE_PARAM */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
int
yyparse (void)
#else
int
yyparse ()

#endif
#endif
{
  
  int yystate;
  int yyn;
  int yyresult;
  /* Number of tokens to shift before error messages enabled.  */
  int yyerrstatus;
  /* Look-ahead token as an internal (translated) token number.  */
  int yytoken = 0;
#if YYERROR_VERBOSE
  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYSIZE_T yymsg_alloc = sizeof yymsgbuf;
#endif

  /* Three stacks and their tools:
     `yyss': related to states,
     `yyvs': related to semantic values,
     `yyls': related to locations.

     Refer to the stacks thru separate pointers, to allow yyoverflow
     to reallocate them elsewhere.  */

  /* The state stack.  */
  yytype_int16 yyssa[YYINITDEPTH];
  yytype_int16 *yyss = yyssa;
  yytype_int16 *yyssp;

  /* The semantic value stack.  */
  YYSTYPE yyvsa[YYINITDEPTH];
  YYSTYPE *yyvs = yyvsa;
  YYSTYPE *yyvsp;



#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  YYSIZE_T yystacksize = YYINITDEPTH;

  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;


  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY;		/* Cause a token to be read.  */

  /* Initialize stack pointers.
     Waste one element of value and location stack
     so that they stay on the same level as the state stack.
     The wasted elements are never initialized.  */

  yyssp = yyss;
  yyvsp = yyvs;

  goto yysetstate;

/*------------------------------------------------------------.
| yynewstate -- Push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
 yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;

 yysetstate:
  *yyssp = yystate;

  if (yyss + yystacksize - 1 <= yyssp)
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYSIZE_T yysize = yyssp - yyss + 1;

#ifdef yyoverflow
      {
	/* Give user a chance to reallocate the stack.  Use copies of
	   these so that the &'s don't force the real ones into
	   memory.  */
	YYSTYPE *yyvs1 = yyvs;
	yytype_int16 *yyss1 = yyss;


	/* Each stack pointer address is followed by the size of the
	   data in use in that stack, in bytes.  This used to be a
	   conditional around just the two extra args, but that might
	   be undefined if yyoverflow is a macro.  */
	yyoverflow (YY_("memory exhausted"),
		    &yyss1, yysize * sizeof (*yyssp),
		    &yyvs1, yysize * sizeof (*yyvsp),

		    &yystacksize);

	yyss = yyss1;
	yyvs = yyvs1;
      }
#else /* no yyoverflow */
# ifndef YYSTACK_RELOCATE
      goto yyexhaustedlab;
# else
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
	goto yyexhaustedlab;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
	yystacksize = YYMAXDEPTH;

      {
	yytype_int16 *yyss1 = yyss;
	union yyalloc *yyptr =
	  (union yyalloc *) YYSTACK_ALLOC (YYSTACK_BYTES (yystacksize));
	if (! yyptr)
	  goto yyexhaustedlab;
	YYSTACK_RELOCATE (yyss);
	YYSTACK_RELOCATE (yyvs);

#  undef YYSTACK_RELOCATE
	if (yyss1 != yyssa)
	  YYSTACK_FREE (yyss1);
      }
# endif
#endif /* no yyoverflow */

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;


      YYDPRINTF ((stderr, "Stack size increased to %lu\n",
		  (unsigned long int) yystacksize));

      if (yyss + yystacksize - 1 <= yyssp)
	YYABORT;
    }

  YYDPRINTF ((stderr, "Entering state %d\n", yystate));

  goto yybackup;

/*-----------.
| yybackup.  |
`-----------*/
yybackup:

  /* Do appropriate processing given the current state.  Read a
     look-ahead token if we need one and don't already have one.  */

  /* First try to decide what to do without reference to look-ahead token.  */
  yyn = yypact[yystate];
  if (yyn == YYPACT_NINF)
    goto yydefault;

  /* Not known => get a look-ahead token if don't already have one.  */

  /* YYCHAR is either YYEMPTY or YYEOF or a valid look-ahead symbol.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token: "));
      yychar = YYLEX;
    }

  if (yychar <= YYEOF)
    {
      yychar = yytoken = YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
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
      if (yyn == 0 || yyn == YYTABLE_NINF)
	goto yyerrlab;
      yyn = -yyn;
      goto yyreduce;
    }

  if (yyn == YYFINAL)
    YYACCEPT;

  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  /* Shift the look-ahead token.  */
  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);

  /* Discard the shifted token unless it is eof.  */
  if (yychar != YYEOF)
    yychar = YYEMPTY;

  yystate = yyn;
  *++yyvsp = yylval;

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
| yyreduce -- Do a reduction.  |
`-----------------------------*/
yyreduce:
  /* yyn is the number of a rule to reduce with.  */
  yylen = yyr2[yyn];

  /* If YYLEN is nonzero, implement the default value of the action:
     `$$ = $1'.

     Otherwise, the following line sets YYVAL to garbage.
     This behavior is undocumented and Bison
     users should not rely upon it.  Assigning to YYVAL
     unconditionally makes the parser a bit smaller, and it avoids a
     GCC warning that YYVAL may be used uninitialized.  */
  yyval = yyvsp[1-yylen];


  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
        case 2:
#line 110 "alfa.y"
    {
    fprintf(yyout,";R1:\t<programa> ::= main { <declaraciones> <funciones> <sentencias> }\n");
    escribir_fin(yyout);
    delete_table(table);

    /*
    tipo_atributos t;
    t.tipo = BOOLEAN;
    fprintf(yyout,"Tipo: %d\n", t.tipo);
    fprintf(yyout,"MAX_TAMANIO_VECTOR: %d\n", MAX_TAMANIO_VECTOR);
    symbol * s = new_symbol("simbolooo", 99, ERROR, ERROR, ERROR, ERROR, ERROR, ERROR, ERROR, ERROR);
    print_symbol(yyout, s);
    */
}
    break;

  case 3:
#line 125 "alfa.y"
    {
    table = create_table();
    if (table == NULL) {
        printf("ERRROR: Error when creating the table.\n");
        return ERROR;
    }
}
    break;

  case 4:
#line 133 "alfa.y"
    {
    escribir_subseccion_data(yyout);
    escribir_cabecera_bss(yyout);
    /* ESCRITURA VARIABLES EN TABLA DE SIMBOLOS
    declarar_variable(salida, "x", ENTERO, 1);
    declarar_variable(salida, "y", ENTERO, 1);
    declarar_variable(salida, "z", ENTERO, 1);
    */
    escribir_segmento_codigo(yyout);
}
    break;

  case 5:
#line 144 "alfa.y"
    {
    escribir_inicio_main(yyout);
}
    break;

  case 6:
#line 148 "alfa.y"
    {
    fprintf(yyout, ";R2:\t<declaraciones> ::= <declaracion>\n");
}
    break;

  case 7:
#line 151 "alfa.y"
    {
    fprintf(yyout, ";R3:\t<declaraciones> ::= <declaracion> <declaraciones>\n");
}
    break;

  case 8:
#line 155 "alfa.y"
    {
    fprintf(yyout, ";R4:\t<declaracion> ::= <clase> <identificadores> ;\n");
}
    break;

  case 9:
#line 159 "alfa.y"
    {
    fprintf(yyout, ";R5:\t<clase> ::= <clase_escalar>\n");
    clase_actual = ESCALAR;
}
    break;

  case 10:
#line 163 "alfa.y"
    {
    fprintf(yyout, ";R7:\t<clase> ::= <clase_vector>\n");
    clase_actual = VECTOR;
}
    break;

  case 11:
#line 168 "alfa.y"
    {
    fprintf(yyout, ";R9:\t<clase_escalar> ::= <tipo>\n");
}
    break;

  case 12:
#line 172 "alfa.y"
    {
    fprintf(yyout, ";R10:\t<tipo> ::= int\n");
    tipo_actual = INT;
}
    break;

  case 13:
#line 176 "alfa.y"
    {
    fprintf(yyout, ";R11:\t<tipo> ::= boolean\n");
    tipo_actual = BOOLEAN;
}
    break;

  case 14:
#line 181 "alfa.y"
    {
    fprintf(yyout, ";R15:\t<clase_vector> ::= array <tipo> [ <constante_entera> ]\n");
    tamanio_vector_actual = (yyvsp[(4) - (5)].atributos).valor_entero;
    if ((tamanio_vector_actual < 1 ) || (tamanio_vector_actual > MAX_TAMANIO_VECTOR)) {
        char err[MAX_ERROR];
        sprintf(err, "El tamanyo del vector %s excede los limites permitidos (1,64).\n", (yyvsp[(1) - (5)].atributos).lexema);
        semantic_error(err);
        return ERROR;
    }
}
    break;

  case 15:
#line 192 "alfa.y"
    {
    fprintf(yyout, ";R18:\t<identificadores> ::= <identificador>\n");
}
    break;

  case 16:
#line 195 "alfa.y"
    {
    fprintf(yyout, ";R19:\t<identificadores> ::= <identificador> , <identificadores>\n");
}
    break;

  case 17:
#line 199 "alfa.y"
    {
    fprintf(yyout, ";R20:\t<funciones> ::= <funcion> <funciones>\n");
}
    break;

  case 18:
#line 202 "alfa.y"
    {
    fprintf(yyout, ";R21:\t<funciones> ::= \n");
}
    break;

  case 19:
#line 206 "alfa.y"
    {
    fprintf(yyout, ";R22:\t<funcion> ::= function <tipo> <identificador> ( <parametros_funcion> ) { <declaraciones_funcion> <sentencias> }\n");
    if (funcion_retorno < 1){
        char err[MAX_ERROR];
        sprintf(err, "Funcion %s sin sentencia de retorno.\n", (yyvsp[(1) - (3)].atributos).lexema);
        semantic_error(err);
        return ERROR;
    }
    close_scope(table);
    symbol *sym;
    sym = search_local_global(table, (yyvsp[(1) - (3)].atributos).lexema);
    if (sym == NULL){
        printf("****Error en la tabla de simbolos.\n");
        delete_table(table);
        return ERROR;
    }
    sym->num_params = num_total_parametros;
    sym->type = funcion_tipo;
    num_total_parametros = 0;
    num_total_var_locales = 0;
    pos_parametro = 0;
}
    break;

  case 20:
#line 229 "alfa.y"
    {
    symbol *sym;
    sym = search_local_global(table, (yyvsp[(1) - (6)].atributos).lexema);
    if (sym == NULL){
        printf("****Error en la tabla de simbolos.\n");
        delete_table(table);
        return ERROR;
    }
    sym->num_params = num_total_parametros;
    sym->num_locals = num_total_var_locales;
    sym->type = funcion_tipo;
    strcpy((yyval.atributos).lexema, (yyvsp[(1) - (6)].atributos).lexema);
    declararFuncion(yyout, (yyvsp[(1) - (6)].atributos).lexema, num_total_var_locales);
}
    break;

  case 21:
#line 244 "alfa.y"
    {
    /* la funcion no existe, por lo que la insertamos en la tabla */
    if (search_local_global(table, (yyvsp[(3) - (3)].atributos).lexema) == NULL){
        strcpy((yyval.atributos).lexema, (yyvsp[(3) - (3)].atributos).lexema);
        declare_function(table, (yyvsp[(3) - (3)].atributos).lexema, (yyvsp[(3) - (3)].atributos).valor_entero, FUNCION, 0, tipo_actual, 0, 0,0,0,0);
        tamanio_vector_actual = 1;
        num_total_var_locales = 0;
        pos_parametro = 0;
        num_total_parametros = 0;
        funcion_retorno = 0;
        funcion_tipo = tipo_actual;
    }
    /* la funcion ya existe, error */
    else{
        semantic_error("Declaracion duplicada.\n");
        return ERROR;
    }

}
    break;

  case 22:
#line 264 "alfa.y"
    {
    fprintf(yyout, ";R23:\t<parametros_funcion> ::= <parametro_funcion> <resto_parametros_funcion>\n");
}
    break;

  case 23:
#line 267 "alfa.y"
    {
    fprintf(yyout, ";R24:\t<parametros_funcion> ::= \n");
}
    break;

  case 24:
#line 271 "alfa.y"
    {
    fprintf(yyout, ";R25:\t<resto_parametros_funcion> ::= ; <parametro_funcion> <resto_parametros_funcion>\n");
}
    break;

  case 25:
#line 274 "alfa.y"
    {
    fprintf(yyout, ";R26:\t<resto_parametros_funcion> ::= \n");
}
    break;

  case 26:
#line 278 "alfa.y"
    {
    fprintf(yyout, ";R27:\t<parametro_funcion> ::= <tipo> <identificador>\n");
    num_total_parametros++;
    pos_parametro++;
}
    break;

  case 27:
#line 284 "alfa.y"
    {
    if (search_current_scope(table, (yyvsp[(1) - (1)].atributos).lexema) == NULL){
        if (declare_local(table, (yyvsp[(1) - (1)].atributos).lexema, (yyvsp[(1) - (1)].atributos).valor_entero, PARAMETRO, clase_actual, tipo_actual, 0,0,0,0,pos_parametro) == ERROR){
            printf("****Error en la tabla de simbolos.\n");
            delete_table(table);
            return ERROR;
        }
    }
    else{
        semantic_error("Declaracion duplicada.\n");
        return ERROR;
    }
}
    break;

  case 28:
#line 298 "alfa.y"
    {
    fprintf(yyout, ";R28:\t<declaraciones_funcion> ::= <declaraciones>\n");
}
    break;

  case 29:
#line 301 "alfa.y"
    {  
    fprintf(yyout, ";R29:\t<declaraciones_funcion> ::= \n");
}
    break;

  case 30:
#line 305 "alfa.y"
    {
    fprintf(yyout, ";R30:\t<sentencias> ::= <sentencia>\n");
}
    break;

  case 31:
#line 308 "alfa.y"
    {
    fprintf(yyout, ";R31:\t<sentencias> ::= <sentencia> <sentencias>\n");
}
    break;

  case 32:
#line 312 "alfa.y"
    {
    fprintf(yyout, ";R32:\t<sentencia> ::= <sentencia_simple> ;\n");
}
    break;

  case 33:
#line 315 "alfa.y"
    {
    fprintf(yyout, ";R33:\t<sentencia> ::= <bloque>\n");
}
    break;

  case 34:
#line 319 "alfa.y"
    {
    fprintf(yyout, ";R34:\t<sentencia_simple> ::= <asignacion>\n");
}
    break;

  case 35:
#line 322 "alfa.y"
    {
    fprintf(yyout, ";R35:\t<sentencia_simple> ::= <lectura>\n");
}
    break;

  case 36:
#line 325 "alfa.y"
    {
    fprintf(yyout, ";R36:\t<sentencia_simple> ::= <escritura>\n");
}
    break;

  case 37:
#line 328 "alfa.y"
    {
    fprintf(yyout, ";R38:\t<sentencia_simple> ::= <retorno_funcion>\n");
}
    break;

  case 38:
#line 332 "alfa.y"
    {
    fprintf(yyout, ";R40:\t<bloque> ::= <condicional>\n");
}
    break;

  case 39:
#line 335 "alfa.y"
    {
    fprintf(yyout, ";R41:\t<bloque> ::= <bucle>\n");
}
    break;

  case 40:
#line 339 "alfa.y"
    {
    fprintf(yyout, ";R43:\t<asignacion> ::= <identificador> = <exp>\n");
    symbol *sym;
    if ((sym = search_local_global(table, (yyvsp[(1) - (3)].atributos).lexema)) == NULL){
        char err[MAX_ERROR];
        sprintf(err, "Acceso a variable no declarada (%s).\n", (yyvsp[(1) - (3)].atributos).lexema);
        semantic_error(err);
        return ERROR;
    }
    if (sym->classs == VECTOR){
        semantic_error("Asignacion incompatible.\n");
        return ERROR;
    }
    if (sym->category == FUNCION){
        semantic_error("Asignacion incompatible.\n");
        return ERROR;
    }
    if (sym->type != (yyvsp[(3) - (3)].atributos).tipo){
        semantic_error("Asignacion incompatible.\n");
        return ERROR;
    }
    if (actual_scope(table) == GLOBAL){
        asignar(yyout, (yyvsp[(1) - (3)].atributos).lexema, (yyvsp[(3) - (3)].atributos).es_direccion);
    }else{
        escribirVariableLocal(yyout, sym->pos_local);
        asignarDestinoEnPila(yyout, (yyvsp[(3) - (3)].atributos).es_direccion);
    }
}
    break;

  case 41:
#line 367 "alfa.y"
    {
    fprintf(yyout, ";R44:\t<asignacion> ::= <elemento_vector> = <exp>\n");
    symbol *sym;
    if ((sym = search_local_global(table, (yyvsp[(1) - (3)].atributos).lexema)) == NULL){
        char err[MAX_ERROR];
        sprintf(err, "Acceso a variable no declarada (%s).\n", (yyvsp[(1) - (3)].atributos).lexema);
        semantic_error(err);
        return ERROR;
    }
    if ((yyvsp[(1) - (3)].atributos).tipo != (yyvsp[(3) - (3)].atributos).tipo){
        semantic_error("Asignacion incompatible.\n");
        return ERROR;
    }
    char aux[MAX_TAMANIO_VECTOR];
    sprintf(aux, "%d", (yyvsp[(1) - (3)].atributos).valor_entero);
    escribir_operando(yyout, aux, 0);
    escribir_elemento_vector(yyout, sym->id, sym->size, (yyvsp[(3) - (3)].atributos).es_direccion);
    asignarDestinoEnPila(yyout, (yyvsp[(3) - (3)].atributos).es_direccion);
}
    break;

  case 42:
#line 387 "alfa.y"
    {
    fprintf(yyout, ";R48:\t<elemento_vector> ::= <identificador> [ <exp> ]\n");
}
    break;

  case 43:
#line 391 "alfa.y"
    {
    fprintf(yyout, ";R50:\t<condicional> ::= if (<exp>) {<sentencias>}\n");
}
    break;

  case 44:
#line 394 "alfa.y"
    {
    fprintf(yyout, ";R51:\t<condicional> ::= if (<exp>) {<sentencias>} else {<sentencias>}\n");
}
    break;

  case 45:
#line 398 "alfa.y"
    {
    fprintf(yyout, ";R52:\t<bucle> ::= while (<exp>) {<sentencias>}\n");
}
    break;

  case 46:
#line 402 "alfa.y"
    {
    fprintf(yyout, ";R54:\t<lectura> ::= scanf <identificador>\n");
}
    break;

  case 47:
#line 406 "alfa.y"
    {
    fprintf(yyout, ";R56:\t<escritura> ::= printf <exp>\n");
}
    break;

  case 48:
#line 410 "alfa.y"
    {
    fprintf(yyout, ";R61:\t<retorno_funcion> ::= return <exp>\n");
}
    break;

  case 49:
#line 414 "alfa.y"
    {
    fprintf(yyout, ";R72:\t<exp> ::= <exp> + <exp>\n");
}
    break;

  case 50:
#line 417 "alfa.y"
    {
    fprintf(yyout, ";R73:\t<exp> ::= <exp> - <exp>\n");
}
    break;

  case 51:
#line 420 "alfa.y"
    {
    fprintf(yyout, ";R74:\t<exp> ::= <exp> / <exp>\n");
}
    break;

  case 52:
#line 423 "alfa.y"
    {
    fprintf(yyout, ";R75:\t<exp> ::= <exp> * <exp>\n");
}
    break;

  case 53:
#line 426 "alfa.y"
    {
    fprintf(yyout, ";R76:\t<exp> ::= - <exp>\n");
}
    break;

  case 54:
#line 429 "alfa.y"
    {
    fprintf(yyout, ";R77:\t<exp> ::= <exp> && <exp>\n");
}
    break;

  case 55:
#line 432 "alfa.y"
    {
    fprintf(yyout, ";R78:\t<exp> ::= <exp> || <exp>\n");
}
    break;

  case 56:
#line 435 "alfa.y"
    {
    fprintf(yyout, ";R79:\t<exp> ::= ! <exp>\n");
}
    break;

  case 57:
#line 438 "alfa.y"
    {
    fprintf(yyout, ";R80:\t<exp> ::= <identificador>\n");
    (yyval.atributos).valor_entero = (yyvsp[(1) - (1)].atributos).valor_entero;
}
    break;

  case 58:
#line 442 "alfa.y"
    {
    fprintf(yyout, ";R81:\t<exp> ::= <constante>\n");
}
    break;

  case 59:
#line 445 "alfa.y"
    {
    fprintf(yyout, ";R82:\t<exp> ::= ( <exp> )\n");
}
    break;

  case 60:
#line 448 "alfa.y"
    {
    fprintf(yyout, ";R83:\t<exp> ::= ( <comparacion> )\n");
}
    break;

  case 61:
#line 451 "alfa.y"
    {
    fprintf(yyout, ";R85:\t<exp> ::= <elemento_vector>\n");
}
    break;

  case 62:
#line 454 "alfa.y"
    {
    fprintf(yyout, ";R88:\t<exp> ::= <identificador>( <lista_expresiones> )\n");
}
    break;

  case 63:
#line 458 "alfa.y"
    {
    fprintf(yyout, ";R89:\t<lista_expresiones> ::= <exp> <resto_lista_expresiones>\n");
}
    break;

  case 64:
#line 461 "alfa.y"
    {
    fprintf(yyout, ";R90:\t<lista_expresiones> ::=\n");
}
    break;

  case 65:
#line 465 "alfa.y"
    {
    fprintf(yyout, ";R91:\t<resto_lista_expresiones> ::= , <exp> <resto_lista_expresiones>\n");
}
    break;

  case 66:
#line 468 "alfa.y"
    { 
    fprintf(yyout, ";R92:\t<resto_lista_expresiones> ::=\n");
}
    break;

  case 67:
#line 472 "alfa.y"
    {
    fprintf(yyout, ";R93:\t<comparacion> ::= <exp> == <exp>\n");
}
    break;

  case 68:
#line 475 "alfa.y"
    {
    fprintf(yyout, ";R94:\t<comparacion> ::= <exp> != <exp>\n");
}
    break;

  case 69:
#line 478 "alfa.y"
    {
    fprintf(yyout, ";R95:\t<comparacion> ::= <exp> <= <exp>\n");
}
    break;

  case 70:
#line 481 "alfa.y"
    {
    fprintf(yyout, ";R96:\t<comparacion> ::= <exp> >= <exp>\n");
}
    break;

  case 71:
#line 484 "alfa.y"
    {
    fprintf(yyout, ";R97:\t<comparacion> ::= <exp> < <exp>\n");
}
    break;

  case 72:
#line 487 "alfa.y"
    {
    fprintf(yyout, ";R98:\t<comparacion> ::= <exp> > <exp>\n");
}
    break;

  case 73:
#line 491 "alfa.y"
    {
    fprintf(yyout, ";R99:\t<constante> ::= <constante_logica>\n");
}
    break;

  case 74:
#line 494 "alfa.y"
    {
    fprintf(yyout, ";R100:\t<constante> ::= <constante_entera>\n");
}
    break;

  case 75:
#line 498 "alfa.y"
    {
    fprintf(yyout, ";R102:\t<constante_logica> ::= true\n");
}
    break;

  case 76:
#line 501 "alfa.y"
    {
    fprintf(yyout, ";R103:\t<constante_logica> ::= false\n");
}
    break;

  case 77:
#line 505 "alfa.y"
    {
    fprintf(yyout, ";R104:\t<contante_entera> ::= TOK_CONSTANTE_ENTERA\n");
}
    break;

  case 78:
#line 509 "alfa.y"
    {
    fprintf(yyout, ";R108:\t<identificador> ::= TOK_IDENTIFICADOR\n");
    symbol * s = search_current_scope(table, (yyvsp[(1) - (1)].atributos).lexema);
    if (s != NULL) {
        semantic_error("Declaracion duplicada.");
        return ERROR;
    } 

    if(actual_scope(table) == GLOBAL) {
        declare_global(table, (yyvsp[(1) - (1)].atributos).lexema, (yyvsp[(1) - (1)].atributos).valor_entero, VARIABLE, clase_actual, tipo_actual, ERROR, ERROR, pos_var_local, ERROR, ERROR);
    } else { // local scope
        declare_local(table, (yyvsp[(1) - (1)].atributos).lexema, (yyvsp[(1) - (1)].atributos).valor_entero, VARIABLE, clase_actual, tipo_actual, ERROR, ERROR, pos_var_local, ERROR, ERROR);
    }
}
    break;


/* Line 1267 of yacc.c.  */
#line 2250 "y.tab.c"
      default: break;
    }
  YY_SYMBOL_PRINT ("-> $$ =", yyr1[yyn], &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);

  *++yyvsp = yyval;


  /* Now `shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */

  yyn = yyr1[yyn];

  yystate = yypgoto[yyn - YYNTOKENS] + *yyssp;
  if (0 <= yystate && yystate <= YYLAST && yycheck[yystate] == *yyssp)
    yystate = yytable[yystate];
  else
    yystate = yydefgoto[yyn - YYNTOKENS];

  goto yynewstate;


/*------------------------------------.
| yyerrlab -- here on detecting error |
`------------------------------------*/
yyerrlab:
  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
#if ! YYERROR_VERBOSE
      yyerror (YY_("syntax error"));
#else
      {
	YYSIZE_T yysize = yysyntax_error (0, yystate, yychar);
	if (yymsg_alloc < yysize && yymsg_alloc < YYSTACK_ALLOC_MAXIMUM)
	  {
	    YYSIZE_T yyalloc = 2 * yysize;
	    if (! (yysize <= yyalloc && yyalloc <= YYSTACK_ALLOC_MAXIMUM))
	      yyalloc = YYSTACK_ALLOC_MAXIMUM;
	    if (yymsg != yymsgbuf)
	      YYSTACK_FREE (yymsg);
	    yymsg = (char *) YYSTACK_ALLOC (yyalloc);
	    if (yymsg)
	      yymsg_alloc = yyalloc;
	    else
	      {
		yymsg = yymsgbuf;
		yymsg_alloc = sizeof yymsgbuf;
	      }
	  }

	if (0 < yysize && yysize <= yymsg_alloc)
	  {
	    (void) yysyntax_error (yymsg, yystate, yychar);
	    yyerror (yymsg);
	  }
	else
	  {
	    yyerror (YY_("syntax error"));
	    if (yysize != 0)
	      goto yyexhaustedlab;
	  }
      }
#endif
    }



  if (yyerrstatus == 3)
    {
      /* If just tried and failed to reuse look-ahead token after an
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

  /* Else will try to reuse look-ahead token after shifting the error
     token.  */
  goto yyerrlab1;


/*---------------------------------------------------.
| yyerrorlab -- error raised explicitly by YYERROR.  |
`---------------------------------------------------*/
yyerrorlab:

  /* Pacify compilers like GCC when the user code never invokes
     YYERROR and the label yyerrorlab therefore never appears in user
     code.  */
  if (/*CONSTCOND*/ 0)
     goto yyerrorlab;

  /* Do not reclaim the symbols of the rule which action triggered
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
  yyerrstatus = 3;	/* Each real token shifted decrements this.  */

  for (;;)
    {
      yyn = yypact[yystate];
      if (yyn != YYPACT_NINF)
	{
	  yyn += YYTERROR;
	  if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYTERROR)
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
		  yystos[yystate], yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  if (yyn == YYFINAL)
    YYACCEPT;

  *++yyvsp = yylval;


  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", yystos[yyn], yyvsp, yylsp);

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

#ifndef yyoverflow
/*-------------------------------------------------.
| yyexhaustedlab -- memory exhaustion comes here.  |
`-------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  /* Fall through.  */
#endif

yyreturn:
  if (yychar != YYEOF && yychar != YYEMPTY)
     yydestruct ("Cleanup: discarding lookahead",
		 yytoken, &yylval);
  /* Do not reclaim the symbols of the rule which action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
		  yystos[*yyssp], yyvsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif
#if YYERROR_VERBOSE
  if (yymsg != yymsgbuf)
    YYSTACK_FREE (yymsg);
#endif
  /* Make sure YYID is used.  */
  return YYID (yyresult);
}


#line 524 "alfa.y"


void yyerror(const char *s){

    if(!err_morf){
        printf("****Error sintactico en [lin %d, col %d]\n", yline, ycol);
        delete_table(table);
        return;
    }

    err_morf = 0;
    delete_table(table);
    return;
}

void semantic_error(char * message) {
    printf("****Error semantico en lin %d: %s\n", yline, message);
    delete_table(table);
}

