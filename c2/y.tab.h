/* A Bison parser, made by GNU Bison 2.3.  */

/* Skeleton interface for Bison's Yacc-like parsers in C

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




#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
#line 39 "alfa.y"
{
    tipo_atributos atributos;
}
/* Line 1529 of yacc.c.  */
#line 135 "y.tab.h"
	YYSTYPE;
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
# define YYSTYPE_IS_TRIVIAL 1
#endif

extern YYSTYPE yylval;

