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
     TOK_MAIN = 260,
     TOK_INT = 261,
     TOK_BOOLEAN = 262,
     TOK_ARRAY = 263,
     TOK_FUNCTION = 264,
     TOK_IF = 265,
     TOK_ELSE = 266,
     TOK_WHILE = 267,
     TOK_SCANF = 268,
     TOK_PRINTF = 269,
     TOK_RETURN = 270,
     TOK_PUNTOYCOMA = 271,
     TOK_COMA = 272,
     TOK_PARENTESISIZQUIERDO = 273,
     TOK_PARENTESISDERECHO = 274,
     TOK_CORCHETEIZQUIERDO = 275,
     TOK_CORCHETEDERECHO = 276,
     TOK_LLAVEIZQUIERDA = 277,
     TOK_LLAVEDERECHA = 278,
     TOK_ASIGNACION = 279,
     TOK_MAS = 280,
     TOK_MENOS = 281,
     TOK_DIVISION = 282,
     TOK_ASTERISCO = 283,
     TOK_AND = 284,
     TOK_OR = 285,
     TOK_NOT = 286,
     TOK_IGUAL = 287,
     TOK_DISTINTO = 288,
     TOK_MENORIGUAL = 289,
     TOK_MAYORIGUAL = 290,
     TOK_MENOR = 291,
     TOK_MAYOR = 292,
     TOK_TRUE = 293,
     TOK_FALSE = 294,
     TOK_ERROR = 295
   };
#endif
/* Tokens.  */
#define TOK_IDENTIFICADOR 258
#define TOK_CONSTANTE_ENTERA 259
#define TOK_MAIN 260
#define TOK_INT 261
#define TOK_BOOLEAN 262
#define TOK_ARRAY 263
#define TOK_FUNCTION 264
#define TOK_IF 265
#define TOK_ELSE 266
#define TOK_WHILE 267
#define TOK_SCANF 268
#define TOK_PRINTF 269
#define TOK_RETURN 270
#define TOK_PUNTOYCOMA 271
#define TOK_COMA 272
#define TOK_PARENTESISIZQUIERDO 273
#define TOK_PARENTESISDERECHO 274
#define TOK_CORCHETEIZQUIERDO 275
#define TOK_CORCHETEDERECHO 276
#define TOK_LLAVEIZQUIERDA 277
#define TOK_LLAVEDERECHA 278
#define TOK_ASIGNACION 279
#define TOK_MAS 280
#define TOK_MENOS 281
#define TOK_DIVISION 282
#define TOK_ASTERISCO 283
#define TOK_AND 284
#define TOK_OR 285
#define TOK_NOT 286
#define TOK_IGUAL 287
#define TOK_DISTINTO 288
#define TOK_MENORIGUAL 289
#define TOK_MAYORIGUAL 290
#define TOK_MENOR 291
#define TOK_MAYOR 292
#define TOK_TRUE 293
#define TOK_FALSE 294
#define TOK_ERROR 295




/* Copy the first part of user declarations.  */
#line 1 "alfa.y"

#include <stdio.h>
#include "generacion.h"
#include "symbols_table.h"
#include "alfa.h"
#include "y.tab.h"

extern FILE * yyout;
extern int yline;
extern int ycol;
extern int err_morf;
extern int yyleng;

int yylex();
void yyerror(const char *s);

symbols_table *table = NULL;

/** GLOBAL VARIABLES **/
int tipo_actual; /* INT or BOOLEAN */
int clase_actual; /* ESCALAR or VECTOR */
int tamanio_vector_actual;
int pos_variable_local_actual; /* para propagar la posicion de una variable local en declaraciones correspondientes a variables locales */




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
#line 28 "alfa.y"
{
    tipo_atributos atributos;
}
/* Line 193 of yacc.c.  */
#line 207 "alfa.tab.c"
	YYSTYPE;
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
# define YYSTYPE_IS_TRIVIAL 1
#endif



/* Copy the second part of user declarations.  */


/* Line 216 of yacc.c.  */
#line 220 "alfa.tab.c"

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
#define YYLAST   166

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  41
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  38
/* YYNRULES -- Number of rules.  */
#define YYNRULES  76
/* YYNRULES -- Number of states.  */
#define YYNSTATES  144

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   295

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
      35,    36,    37,    38,    39,    40
};

#if YYDEBUG
/* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
   YYRHS.  */
static const yytype_uint8 yyprhs[] =
{
       0,     0,     3,    11,    12,    14,    17,    21,    23,    25,
      27,    29,    31,    37,    39,    43,    46,    47,    51,    58,
      62,    65,    66,    70,    71,    74,    76,    77,    79,    82,
      85,    87,    89,    91,    93,    95,    97,    99,   103,   107,
     112,   120,   132,   140,   143,   146,   149,   153,   157,   161,
     165,   168,   172,   176,   179,   181,   183,   187,   191,   193,
     198,   201,   202,   206,   207,   211,   215,   219,   222,   226,
     230,   232,   234,   236,   238,   240,   242
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int8 yyrhs[] =
{
      42,     0,    -1,    43,     5,    22,    44,    51,    59,    23,
      -1,    -1,    45,    -1,    45,    44,    -1,    46,    50,    16,
      -1,    47,    -1,    49,    -1,    48,    -1,     6,    -1,     7,
      -1,     8,    48,    20,    76,    21,    -1,    77,    -1,    77,
      17,    50,    -1,    52,    51,    -1,    -1,    53,    59,    23,
      -1,    54,    18,    55,    19,    22,    58,    -1,     9,    48,
       3,    -1,    57,    56,    -1,    -1,    16,    57,    56,    -1,
      -1,    48,    78,    -1,    44,    -1,    -1,    60,    -1,    60,
      59,    -1,    61,    16,    -1,    62,    -1,    63,    -1,    67,
      -1,    68,    -1,    69,    -1,    65,    -1,    66,    -1,    77,
      24,    70,    -1,    64,    24,    70,    -1,    77,    20,    70,
      21,    -1,    10,    18,    70,    19,    22,    59,    23,    -1,
      10,    18,    70,    19,    22,    59,    23,    11,    22,    59,
      23,    -1,    12,    18,    70,    19,    22,    59,    23,    -1,
      13,    77,    -1,    14,    70,    -1,    15,    70,    -1,    70,
      25,    70,    -1,    70,    26,    70,    -1,    70,    27,    70,
      -1,    70,    28,    70,    -1,    26,    70,    -1,    70,    29,
      70,    -1,    70,    30,    70,    -1,    31,    70,    -1,    77,
      -1,    74,    -1,    18,    70,    19,    -1,    18,    73,    19,
      -1,    64,    -1,    77,    18,    71,    19,    -1,    70,    72,
      -1,    -1,    17,    70,    72,    -1,    -1,    70,    32,    70,
      -1,    70,    33,    70,    -1,    70,    34,    70,    -1,    70,
      35,    -1,    70,    36,    70,    -1,    70,    37,    70,    -1,
      75,    -1,    76,    -1,    38,    -1,    39,    -1,     4,    -1,
       3,    -1,     3,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,    90,    90,    94,   102,   104,   107,   110,   114,   119,
     122,   126,   131,   140,   142,   145,   148,   150,   156,   161,
     166,   169,   171,   174,   176,   179,   182,   184,   186,   189,
     191,   194,   196,   198,   200,   203,   205,   208,   210,   213,
     216,   218,   221,   224,   227,   230,   233,   235,   237,   239,
     241,   243,   245,   247,   249,   251,   253,   255,   257,   259,
     262,   265,   267,   270,   272,   274,   276,   278,   280,   282,
     285,   287,   290,   292,   295,   298,   312
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || YYTOKEN_TABLE
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "TOK_IDENTIFICADOR",
  "TOK_CONSTANTE_ENTERA", "TOK_MAIN", "TOK_INT", "TOK_BOOLEAN",
  "TOK_ARRAY", "TOK_FUNCTION", "TOK_IF", "TOK_ELSE", "TOK_WHILE",
  "TOK_SCANF", "TOK_PRINTF", "TOK_RETURN", "TOK_PUNTOYCOMA", "TOK_COMA",
  "TOK_PARENTESISIZQUIERDO", "TOK_PARENTESISDERECHO",
  "TOK_CORCHETEIZQUIERDO", "TOK_CORCHETEDERECHO", "TOK_LLAVEIZQUIERDA",
  "TOK_LLAVEDERECHA", "TOK_ASIGNACION", "TOK_MAS", "TOK_MENOS",
  "TOK_DIVISION", "TOK_ASTERISCO", "TOK_AND", "TOK_OR", "TOK_NOT",
  "TOK_IGUAL", "TOK_DISTINTO", "TOK_MENORIGUAL", "TOK_MAYORIGUAL",
  "TOK_MENOR", "TOK_MAYOR", "TOK_TRUE", "TOK_FALSE", "TOK_ERROR",
  "$accept", "programa", "inicioTabla", "declaraciones", "declaracion",
  "clase", "clase_escalar", "tipo", "clase_vector", "identificadores",
  "funciones", "funcion", "fn_declaration", "fn_name",
  "parametros_funcion", "resto_parametros_funcion", "parametro_funcion",
  "declaraciones_funcion", "sentencias", "sentencia", "sentencia_simple",
  "bloque", "asignacion", "elemento_vector", "condicional", "bucle",
  "lectura", "escritura", "retorno_funcion", "exp", "lista_expresiones",
  "resto_lista_expresiones", "comparacion", "constante",
  "constante_logica", "constante_entera", "identificador", "idpf", 0
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
     295
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    41,    42,    43,    44,    44,    45,    46,    46,    47,
      48,    48,    49,    50,    50,    51,    51,    52,    53,    54,
      55,    55,    56,    56,    57,    58,    58,    59,    59,    60,
      60,    61,    61,    61,    61,    62,    62,    63,    63,    64,
      65,    65,    66,    67,    68,    69,    70,    70,    70,    70,
      70,    70,    70,    70,    70,    70,    70,    70,    70,    70,
      71,    71,    72,    72,    73,    73,    73,    73,    73,    73,
      74,    74,    75,    75,    76,    77,    78
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     7,     0,     1,     2,     3,     1,     1,     1,
       1,     1,     5,     1,     3,     2,     0,     3,     6,     3,
       2,     0,     3,     0,     2,     1,     0,     1,     2,     2,
       1,     1,     1,     1,     1,     1,     1,     3,     3,     4,
       7,    11,     7,     2,     2,     2,     3,     3,     3,     3,
       2,     3,     3,     2,     1,     1,     3,     3,     1,     4,
       2,     0,     3,     0,     3,     3,     3,     2,     3,     3,
       1,     1,     1,     1,     1,     1,     1
};

/* YYDEFACT[STATE-NAME] -- Default rule to reduce with in state
   STATE-NUM when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       3,     0,     0,     1,     0,     0,    10,    11,     0,    16,
       4,     0,     7,     9,     8,     0,     0,     0,    16,     0,
       0,     5,    75,     0,    13,     0,     0,     0,     0,     0,
       0,     0,     0,    27,     0,    30,    31,     0,    35,    36,
      32,    33,    34,     0,    15,     0,    21,     6,     0,    74,
       0,    19,     0,     0,    43,     0,     0,     0,    72,    73,
      58,    44,    55,    70,    71,    54,    45,     2,    28,    29,
       0,     0,     0,    17,     0,     0,    23,    14,    12,     0,
       0,     0,     0,    50,    53,     0,     0,     0,     0,     0,
       0,    61,    38,     0,    37,    76,    24,     0,     0,    20,
       0,     0,    56,     0,     0,     0,    67,     0,     0,    57,
      46,    47,    48,    49,    51,    52,    63,     0,    39,    26,
      23,     0,     0,    64,    65,    66,    68,    69,     0,    60,
      59,    25,    18,    22,     0,     0,    63,    40,    42,    62,
       0,     0,     0,    41
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     1,     2,     9,    10,    11,    12,    13,    14,    23,
      17,    18,    19,    20,    75,    99,    76,   132,    32,    33,
      34,    35,    36,    60,    38,    39,    40,    41,    42,    61,
     117,   129,    82,    62,    63,    64,    65,    96
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -30
static const yytype_int16 yypact[] =
{
     -30,     9,    15,   -30,     3,     5,   -30,   -30,    29,     7,
       5,    44,   -30,   -30,   -30,    28,    29,    77,     7,    77,
      33,   -30,   -30,    36,    37,    49,    52,    45,    53,    44,
      46,    46,    50,    77,    65,   -30,   -30,    58,   -30,   -30,
     -30,   -30,   -30,   -10,   -30,    60,    29,   -30,    44,   -30,
      67,   -30,    46,    46,   -30,    46,    46,    46,   -30,   -30,
     -30,    40,   -30,   -30,   -30,    26,    40,   -30,   -30,   -30,
      46,    46,    46,   -30,    83,    74,    78,   -30,   -30,    90,
     126,   107,    76,    11,   -30,    46,    46,    46,    46,    46,
      46,    46,    40,   136,    40,   -30,   -30,    79,    29,   -30,
      80,    81,   -30,    46,    46,    46,   -30,    46,    46,   -30,
      11,    11,   -30,   -30,   -30,    11,     4,    85,   -30,     5,
      78,    77,    77,    40,    40,    40,    40,    40,    46,   -30,
     -30,   -30,   -30,   -30,    73,    75,     4,    89,   -30,   -30,
      92,    77,    98,   -30
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
     -30,   -30,   -30,    -6,   -30,   -30,   -30,    -1,   -30,    64,
     104,   -30,   -30,   -30,   -30,     8,    25,   -30,   -14,   -30,
     -30,   -30,   -30,   -16,   -30,   -30,   -30,   -30,   -30,   -29,
     -30,   -12,   -30,   -30,   -30,   106,   -11,   -30
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -1
static const yytype_uint8 yytable[] =
{
      24,    37,    66,    37,    21,    45,    43,    15,    43,     3,
      71,     6,     7,     8,    72,    26,    16,    37,    54,    68,
       4,   128,    43,    79,    80,     5,    81,    83,    84,    85,
      86,    87,    88,    89,    90,     6,     7,    24,    87,    88,
      89,    92,    93,    94,    91,    74,    71,    22,    25,    22,
      49,    46,    47,    49,    48,    51,   110,   111,   112,   113,
     114,   115,   116,    52,    55,    85,    86,    87,    88,    89,
      90,    53,    56,    67,   123,   124,   125,    57,   126,   127,
      22,    69,    70,    73,    58,    59,    95,    27,    78,    28,
      29,    30,    31,    97,    98,   109,   137,    74,   138,   136,
     140,   119,   121,   122,   130,    37,    37,   134,   135,   100,
      43,    43,    77,   131,   141,    85,    86,    87,    88,    89,
      90,   143,    44,   120,   139,    37,   102,   142,   133,     0,
      43,    50,    85,    86,    87,    88,    89,    90,     0,   103,
     104,   105,   106,   107,   108,   101,     0,     0,     0,     0,
       0,    85,    86,    87,    88,    89,    90,   118,     0,     0,
       0,    85,    86,    87,    88,    89,    90
};

static const yytype_int16 yycheck[] =
{
      11,    17,    31,    19,    10,    19,    17,     8,    19,     0,
      20,     6,     7,     8,    24,    16,     9,    33,    29,    33,
       5,    17,    33,    52,    53,    22,    55,    56,    57,    25,
      26,    27,    28,    29,    30,     6,     7,    48,    27,    28,
      29,    70,    71,    72,    18,    46,    20,     3,    20,     3,
       4,    18,    16,     4,    17,     3,    85,    86,    87,    88,
      89,    90,    91,    18,    18,    25,    26,    27,    28,    29,
      30,    18,    26,    23,   103,   104,   105,    31,   107,   108,
       3,    16,    24,    23,    38,    39,     3,    10,    21,    12,
      13,    14,    15,    19,    16,    19,    23,    98,    23,   128,
      11,    22,    22,    22,    19,   121,   122,   121,   122,    19,
     121,   122,    48,   119,    22,    25,    26,    27,    28,    29,
      30,    23,    18,    98,   136,   141,    19,   141,   120,    -1,
     141,    25,    25,    26,    27,    28,    29,    30,    -1,    32,
      33,    34,    35,    36,    37,    19,    -1,    -1,    -1,    -1,
      -1,    25,    26,    27,    28,    29,    30,    21,    -1,    -1,
      -1,    25,    26,    27,    28,    29,    30
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    42,    43,     0,     5,    22,     6,     7,     8,    44,
      45,    46,    47,    48,    49,    48,     9,    51,    52,    53,
      54,    44,     3,    50,    77,    20,    48,    10,    12,    13,
      14,    15,    59,    60,    61,    62,    63,    64,    65,    66,
      67,    68,    69,    77,    51,    59,    18,    16,    17,     4,
      76,     3,    18,    18,    77,    18,    26,    31,    38,    39,
      64,    70,    74,    75,    76,    77,    70,    23,    59,    16,
      24,    20,    24,    23,    48,    55,    57,    50,    21,    70,
      70,    70,    73,    70,    70,    25,    26,    27,    28,    29,
      30,    18,    70,    70,    70,     3,    78,    19,    16,    56,
      19,    19,    19,    32,    33,    34,    35,    36,    37,    19,
      70,    70,    70,    70,    70,    70,    70,    71,    21,    22,
      57,    22,    22,    70,    70,    70,    70,    70,    17,    72,
      19,    44,    58,    56,    59,    59,    70,    23,    23,    72,
      11,    22,    59,    23
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
#line 91 "alfa.y"
    {fprintf(yyout,";R1:\t<programa> ::= main { <declaraciones> <funciones> <sentencias> }\n");;}
    break;

  case 3:
#line 94 "alfa.y"
    {
    table = create_table();
    if (table == NULL) {
        fprintf(stderr, "ERRROR: Error when creating the table.\n");
        return ERROR;
    }
;}
    break;

  case 4:
#line 103 "alfa.y"
    {fprintf(yyout, ";R2:\t<declaraciones> ::= <declaracion>\n");;}
    break;

  case 5:
#line 105 "alfa.y"
    {fprintf(yyout, ";R3:\t<declaraciones> ::= <declaracion> <declaraciones>\n");;}
    break;

  case 6:
#line 108 "alfa.y"
    {fprintf(yyout, ";R4:\t<declaracion> ::= <clase> <identificadores> ;\n");;}
    break;

  case 7:
#line 111 "alfa.y"
    {
                                clase_actual = ESCALAR;
                                fprintf(yyout, ";R5:\t<clase> ::= <clase_escalar>\n");;}
    break;

  case 8:
#line 115 "alfa.y"
    {
                                clase_actual = VECTOR;
                                fprintf(yyout, ";R7:\t<clase> ::= <clase_vector>\n");;}
    break;

  case 9:
#line 120 "alfa.y"
    {fprintf(yyout, ";R9:\t<clase_escalar> ::= <tipo>\n");;}
    break;

  case 10:
#line 123 "alfa.y"
    {
                                tipo_actual = INT;
                                fprintf(yyout, ";R10:\t<tipo> ::= int\n");;}
    break;

  case 11:
#line 127 "alfa.y"
    {
                                tipo_actual = BOOLEAN;
                                fprintf(yyout, ";R11:\t<tipo> ::= boolean\n");;}
    break;

  case 12:
#line 132 "alfa.y"
    {
                                tamanio_vector_actual = (yyvsp[(4) - (5)].atributos).valor_entero;
                                if ((tamanio_vector_actual < 1) || (tamanio_vector_actual > MAX_TAMANIO_VECTOR)){
                                    fprintf(yyout, "****Error semantico en lin %d: El tamanyo del vector <nombre_vector> excede los limites permitidos (1,64)\n", yline);
                                    return ERROR;
                                }
                                fprintf(yyout, ";R15:\t<clase_vector> ::= array <tipo> [ <constante_entera> ]\n");;}
    break;

  case 13:
#line 141 "alfa.y"
    {fprintf(yyout, ";R18:\t<identificadores> ::= <identificador>\n");;}
    break;

  case 14:
#line 143 "alfa.y"
    {fprintf(yyout, ";R19:\t<identificadores> ::= <identificador> , <identificadores>\n");;}
    break;

  case 15:
#line 146 "alfa.y"
    {fprintf(yyout, ";R20:\t<funciones> ::= <funcion> <funciones>\n");;}
    break;

  case 16:
#line 148 "alfa.y"
    {fprintf(yyout, ";R21:\t<funciones> ::= \n");;}
    break;

  case 17:
#line 151 "alfa.y"
    {
                                fprintf(yyout, ";R22:\t<funcion> ::= function <tipo> <identificador> ( <parametros_funcion> ) { <declaraciones_funcion> <sentencias> }\n");
                                /*TODO: cosas con la tabla de simboloss */
                            ;}
    break;

  case 18:
#line 157 "alfa.y"
    {
                                /*TODO: cosas con la tabla de simboloss */
                            ;}
    break;

  case 19:
#line 162 "alfa.y"
    {
                                /*TODO: cosas con la tabla de simboloss */
                            ;}
    break;

  case 20:
#line 167 "alfa.y"
    {fprintf(yyout, ";R23:\t<parametros_funcion> ::= <parametro_funcion> <resto_parametros_funcion>\n");;}
    break;

  case 21:
#line 169 "alfa.y"
    {fprintf(yyout, ";R24:\t<parametros_funcion> ::= \n");;}
    break;

  case 22:
#line 172 "alfa.y"
    {fprintf(yyout, ";R25:\t<resto_parametros_funcion> ::= ; <parametro_funcion> <resto_parametros_funcion>\n");;}
    break;

  case 23:
#line 174 "alfa.y"
    {fprintf(yyout, ";R26:\t<resto_parametros_funcion> ::= \n");;}
    break;

  case 24:
#line 177 "alfa.y"
    {fprintf(yyout, ";R27:\t<parametro_funcion> ::= <tipo> <idpf>\n");;}
    break;

  case 25:
#line 180 "alfa.y"
    {fprintf(yyout, ";R28:\t<declaraciones_funcion> ::= <declaraciones>\n");;}
    break;

  case 26:
#line 182 "alfa.y"
    {fprintf(yyout, ";R29:\t<declaraciones_funcion> ::= \n");;}
    break;

  case 27:
#line 185 "alfa.y"
    {fprintf(yyout, ";R30:\t<sentencias> ::= <sentencia>\n");;}
    break;

  case 28:
#line 187 "alfa.y"
    {fprintf(yyout, ";R31:\t<sentencias> ::= <sentencia> <sentencias>\n");;}
    break;

  case 29:
#line 190 "alfa.y"
    {fprintf(yyout, ";R32:\t<sentencia> ::= <sentencia_simple> ;\n");;}
    break;

  case 30:
#line 192 "alfa.y"
    {fprintf(yyout, ";R33:\t<sentencia> ::= <bloque>\n");;}
    break;

  case 31:
#line 195 "alfa.y"
    {fprintf(yyout, ";R34:\t<sentencia_simple> ::= <asignacion>\n");;}
    break;

  case 32:
#line 197 "alfa.y"
    {fprintf(yyout, ";R35:\t<sentencia_simple> ::= <lectura>\n");;}
    break;

  case 33:
#line 199 "alfa.y"
    {fprintf(yyout, ";R36:\t<sentencia_simple> ::= <escritura>\n");;}
    break;

  case 34:
#line 201 "alfa.y"
    {fprintf(yyout, ";R38:\t<sentencia_simple> ::= <retorno_funcion>\n");;}
    break;

  case 35:
#line 204 "alfa.y"
    {fprintf(yyout, ";R40:\t<bloque> ::= <condicional>\n");;}
    break;

  case 36:
#line 206 "alfa.y"
    {fprintf(yyout, ";R41:\t<bloque> ::= <bucle>\n");;}
    break;

  case 37:
#line 209 "alfa.y"
    {fprintf(yyout, ";R43:\t<asignacion> ::= <identificador> = <exp>\n");;}
    break;

  case 38:
#line 211 "alfa.y"
    {fprintf(yyout, ";R44:\t<asignacion> ::= <elemento_vector> = <exp>\n");;}
    break;

  case 39:
#line 214 "alfa.y"
    {fprintf(yyout, ";R48:\t<elemento_vector> ::= <identificador> [ <exp> ]\n");;}
    break;

  case 40:
#line 217 "alfa.y"
    {fprintf(yyout, ";R50:\t<condicional> ::= if (<exp>) {<sentencias>}\n");;}
    break;

  case 41:
#line 219 "alfa.y"
    {fprintf(yyout, ";R51:\t<condicional> ::= if (<exp>) {<sentencias>} else {<sentencias>}\n");;}
    break;

  case 42:
#line 222 "alfa.y"
    {fprintf(yyout, ";R52:\t<bucle> ::= while (<exp>) {<sentencias>}\n");;}
    break;

  case 43:
#line 225 "alfa.y"
    {fprintf(yyout, ";R54:\t<lectura> ::= scanf <identificador>\n");;}
    break;

  case 44:
#line 228 "alfa.y"
    {fprintf(yyout, ";R56:\t<escritura> ::= printf <exp>\n");;}
    break;

  case 45:
#line 231 "alfa.y"
    {fprintf(yyout, ";R61:\t<retorno_funcion> ::= return <exp>\n");;}
    break;

  case 46:
#line 234 "alfa.y"
    {fprintf(yyout, ";R72:\t<exp> ::= <exp> + <exp>\n"); sumar(yyout, (yyvsp[(1) - (3)].atributos), (yyvsp[(3) - (3)].atributos));;}
    break;

  case 47:
#line 236 "alfa.y"
    {fprintf(yyout, ";R73:\t<exp> ::= <exp> - <exp>\n"); restar(yyout, (yyvsp[(1) - (3)].atributos), (yyvsp[(3) - (3)].atributos));;}
    break;

  case 48:
#line 238 "alfa.y"
    {fprintf(yyout, ";R74:\t<exp> ::= <exp> / <exp>\n"); dividir(yyout, (yyvsp[(1) - (3)].atributos), (yyvsp[(3) - (3)].atributos));;}
    break;

  case 49:
#line 240 "alfa.y"
    {fprintf(yyout, ";R75:\t<exp> ::= <exp> * <exp>\n"); multiplicar(yyout, (yyvsp[(1) - (3)].atributos), (yyvsp[(3) - (3)].atributos));;}
    break;

  case 50:
#line 242 "alfa.y"
    {fprintf(yyout, ";R76:\t<exp> ::= - <exp>\n"); cambiar_signo(yyout, (yyvsp[(2) - (2)].atributos));;}
    break;

  case 51:
#line 244 "alfa.y"
    {fprintf(yyout, ";R77:\t<exp> ::= <exp> && <exp>\n"); y(yyput, (yyvsp[(1) - (3)].atributos), (yyvsp[(3) - (3)].atributos));;}
    break;

  case 52:
#line 246 "alfa.y"
    {fprintf(yyout, ";R78:\t<exp> ::= <exp> || <exp>\n"); o(yyout, (yyvsp[(1) - (3)].atributos), (yyvsp[(3) - (3)].atributos));;}
    break;

  case 53:
#line 248 "alfa.y"
    {fprintf(yyout, ";R79:\t<exp> ::= ! <exp>\n"); ;}
    break;

  case 54:
#line 250 "alfa.y"
    {fprintf(yyout, ";R80:\t<exp> ::= <identificador>\n");;}
    break;

  case 55:
#line 252 "alfa.y"
    {fprintf(yyout, ";R81:\t<exp> ::= <constante>\n");;}
    break;

  case 56:
#line 254 "alfa.y"
    {fprintf(yyout, ";R82:\t<exp> ::= ( <exp> )\n");;}
    break;

  case 57:
#line 256 "alfa.y"
    {fprintf(yyout, ";R83:\t<exp> ::= ( <comparacion> )\n");;}
    break;

  case 58:
#line 258 "alfa.y"
    {fprintf(yyout, ";R85:\t<exp> ::= <elemento_vector>\n");;}
    break;

  case 59:
#line 260 "alfa.y"
    {fprintf(yyout, ";R88:\t<exp> ::= <identificador>( <lista_expresiones> )\n");;}
    break;

  case 60:
#line 263 "alfa.y"
    {fprintf(yyout, ";R89:\t<lista_expresiones> ::= <exp> <resto_lista_expresiones>\n");;}
    break;

  case 61:
#line 265 "alfa.y"
    {fprintf(yyout, ";R90:\t<lista_expresiones> ::=\n");;}
    break;

  case 62:
#line 268 "alfa.y"
    {fprintf(yyout, ";R91:\t<resto_lista_expresiones> ::= , <exp> <resto_lista_expresiones>\n");;}
    break;

  case 63:
#line 270 "alfa.y"
    {fprintf(yyout, ";R92:\t<resto_lista_expresiones> ::=\n");;}
    break;

  case 64:
#line 273 "alfa.y"
    {fprintf(yyout, ";R93:\t<comparacion> ::= <exp> == <exp>\n");;}
    break;

  case 65:
#line 275 "alfa.y"
    {fprintf(yyout, ";R94:\t<comparacion> ::= <exp> != <exp>\n");;}
    break;

  case 66:
#line 277 "alfa.y"
    {fprintf(yyout, ";R95:\t<comparacion> ::= <exp> <= <exp>\n");;}
    break;

  case 67:
#line 279 "alfa.y"
    {fprintf(yyout, ";R96:\t<comparacion> ::= <exp> >= <exp>\n");;}
    break;

  case 68:
#line 281 "alfa.y"
    {fprintf(yyout, ";R97:\t<comparacion> ::= <exp> < <exp>\n");;}
    break;

  case 69:
#line 283 "alfa.y"
    {fprintf(yyout, ";R98:\t<comparacion> ::= <exp> > <exp>\n");;}
    break;

  case 70:
#line 286 "alfa.y"
    {fprintf(yyout, ";R99:\t<constante> ::= <constante_logica>\n");;}
    break;

  case 71:
#line 288 "alfa.y"
    {fprintf(yyout, ";R100:\t<constante> ::= <constante_entera>\n");;}
    break;

  case 72:
#line 291 "alfa.y"
    {fprintf(yyout, ";R102:\t<constante_logica> ::= true\n");;}
    break;

  case 73:
#line 293 "alfa.y"
    {fprintf(yyout, ";R103:\t<constante_logica> ::= false\n");;}
    break;

  case 74:
#line 296 "alfa.y"
    {fprintf(yyout, ";R104:\t<contante_entera> ::= TOK_CONSTANTE_ENTERA\n");;}
    break;

  case 75:
#line 299 "alfa.y"
    {
                                fprintf(yyout, ";R108:\t<identificador> ::= TOK_IDENTIFICADOR\n");
                                /*TODO: insertar en tabla de simboloss */
                                if(is_local_scope(table)) {
                                    if(search_global(table, (yyvsp[(1) - (1)].atributos).lexema)) {
                                        fprintf(yyout, "****Error semantico en lin %d: Declaracion duplicada.\n", yline);
                                        return ERROR;
                                    }
                                } else {

                                }
                            ;}
    break;

  case 76:
#line 313 "alfa.y"
    {
                                /*TODO: insertar en tabla de simboloss */
                            ;}
    break;


/* Line 1267 of yacc.c.  */
#line 1971 "alfa.tab.c"
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


#line 318 "alfa.y"


void yyerror(const char *s){

    if(!err_morf){
        printf("****Error sintactico en [lin %d, col %d]\n", yline, ycol);
        return;
    }

    err_morf = 0;
    return;
}

