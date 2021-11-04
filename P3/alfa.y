%{
#include <stdio.h>
FILE * yyout;


%}

%union {
    char* string;
    int number;
}

%token TOK_MAIN
%token TOK_INT
%token TOK_BOOLEAN
%token TOK_FUNCTION
%token TOK_IF
%token TOK_ELSE
%token TOK_WHILE
%token TOK_SCANF
%token TOK_PRINTF
%token TOK_RETURN

%token TOK_PUNTOYCOMA
%token TOK_COMA
%token TOK_PARENTESISIZQUIERDO
%token TOK_PARENTESISDERECHO
%token TOK_CORCHETEIZQUIERDO
%token TOK_CORCHETEDERECHO
%token TOK_LLAVEIZQUIERDA
%token TOK_LLAVEDERECHA
%token TOK_ASIGNACION
%token TOK_MAS
%token TOK_MENOS
%token TOK_DIVISION
%token TOK_ASTERISCO
%token TOK_AND
%token TOK_OR
%token TOK_NOT
%token TOK_IGUAL
%token TOK_DISTINTO
%token TOK_MENORIGUAL
%token TOK_MAYORIGUAL
%token TOK_MENOR
%token TOK_MAYOR

%token <string> TOK_IDENTIFICADOR

%token <number> TOK_CONSTANTE_ENTERA
%token TOK_TRUE
%token TOK_FALSE

%left TOK_MAS TOK_MENOS
%left TOK_ASTERISCO TOK_DIVISION
%left TOK_NOT

%%

programa:       TOK_MAIN TOK_LLAVEIZQUIERDA declaraciones funciones sentencias TOK_LLAVEDERECHA
                {fprintf(yyout, ";R1:\t<programa> ::= main { <declaraciones> <funciones> <sentencias> }\n");}

declaraciones:  declaracion 
                {fprintf(yyout, ";R2:\t<declaraciones> ::= <declaracion>\n");}
                | declaracion declaraciones 
                {fprintf(yyout, ";R3:\t<declaraciones> ::= <declaracion> <declaraciones>\n");}

declaracion:    clase identificadores TOK_PUNTOYCOMA
                {fprintf(yyout, ";R4:\t<declaracion> ::= <clase> <identificadores> ;\n");}

clase:          clase_escalar
                {fprintf(yyout, ";R5:\t<clase> ::= <clase_escalar>\n");}
                | clase_vector
                {fprintf(yyout, ";R7:\t<clase> ::= <clase_vector>\n");}

clase_escalar:  tipo
                {fprintf(yyout, ";R9:\t<clase_escalar> ::= <tipo>\n");}

tipo:           TOK_INT
                {fprintf(yyout, ";R10:\t<tipo> ::= int\n");}
                | TOK_BOOLEAN
                {fprintf(yyout, ";R11:\t<tipo> ::= boolean\n");}

clase_vector:   TOK_ARRAY tipo TOK_CORCHETEIZQUIERDO constante_entera TOK_CORCHETEDERECHO
                {fprintf(yyout, ";R15:\t<clase_vector> ::= array <tipo> [ <constante_entera> ]\n");}

                



asignacion:     identificador TOK_ASIGNACION exp
                {fprintf(yyout, ";R43:\t<asignacion> ::= <identificador> = <exp>\n");}
                | elemento_vector TOK_ASIGNACION exp
                {fprintf(yyout, ";R44:\t<asignacion> ::= <elemento_vector> = <exp>\n");}

elemento_vector:    identificador  TOK_CORCHETEIZQUIERDO exp TOK_CORCHETEDERECHO
                    {fprintf(yyout, ";R48:\t<elemento_vector> ::= <identificador> [ <exp> ]\n");}
                    | identificador TOK_CORCHETEIZQUIERDO exp TOK_COMA exp TOK_CORCHETEDERECHO
                    {fprintf(yyout, ";R49:\t<elemento_vector> ::= <identificador> [ <exp> , <exp> ]\n");}



condicional:    TOK_IF TOK_PARENTESISIZQUIERDO exp TOK_PARENTESISDERECHO TOK_CORCHETEIZQUIERDO sentencias 
                TOK_CORCHETEDERECHO  {}





digito:         

%%