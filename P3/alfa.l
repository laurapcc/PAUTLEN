%{
#include <stdio.h>
#include "y.tab.h"

int ycol = 1;
int yline = 1;

%}

%option noyywrap

LETTER [a-zA-Z]
DIGIT [0-9]


%%

" " { ycol += yyleng; }
\n { yline++; ycol = 1;}
"//".*\n { yline++; ycol = 1; }


main { ycol += yyleng; return TOK_MAIN; }
int { ycol += yyleng; return TOK_INT; }
boolean { ycol += yyleng; return TOK_BOOLEAN; }
array { ycol += yyleng; return TOK_ARRAY; }
function { ycol += yyleng; return TOK_FUNCTION; }
if { ycol += yyleng; return TOK_IF; }
else { ycol += yyleng; return TOK_ELSE; }
while { ycol += yyleng; return TOK_WHILE; }
scanf { ycol += yyleng; return TOK_SCANF; }
printf { ycol += yyleng; return TOK_PRINTF; }
return { ycol += yyleng; return TOK_RETURN; }



";" { ycol += yyleng; return TOK_PUNTOYCOMA; }
"," { ycol += yyleng; return TOK_COMA; }
"(" { ycol += yyleng; return TOK_PARENTESISIZQUIERDO; }
")" { ycol += yyleng; return TOK_PARENTESISDERECHO; }
"[" { ycol += yyleng; return TOK_CORCHETEIZQUIERDO; }
"]" { ycol += yyleng; return TOK_CORCHETEDERECHO; }
"{" { ycol += yyleng; return TOK_LLAVEIZQUIERDA; }
"}" { ycol += yyleng; return TOK_LLAVEDERECHA; }
"=" { ycol += yyleng; return TOK_ASIGNACION; }
"+" { ycol += yyleng; return TOK_MAS; }
"-" { ycol += yyleng; return TOK_MENOS; }
"/" { ycol += yyleng; return TOK_DIVISION; }
"*" { ycol += yyleng; return TOK_ASTERISCO; }
"&&" { ycol += yyleng; return TOK_AND; }
"||" { ycol += yyleng; return TOK_OR; }
"!" { ycol += yyleng; return TOK_NOT; }
"==" { ycol += yyleng; return TOK_IGUAL; }
"!=" { ycol += yyleng; return TOK_DISTINTO; }
"<=" { ycol += yyleng; return TOK_MENORIGUAL; }
">=" { ycol += yyleng; return TOK_MAYORIGUAL; }
"<" { ycol += yyleng; return TOK_MENOR; }
">" { ycol += yyleng; return TOK_MAYOR; }

true { ycol += yyleng; return TOK_TRUE; }
false { ycol += yyleng; return TOK_FALSE; }


{LETTER}({DIGIT}|{LETTER}){100,} { return TOK_ERROR; }

{DIGIT}+ { ycol += yyleng; return TOK_CONSTANTE_ENTERA; }
{LETTER}({DIGIT}|{LETTER}){0,99} { ycol += yyleng; return TOK_IDENTIFICADOR; }



[^({LETTER}(({DIGIT}|{LETTER}){0,99}))] { return TOK_ERROR; }

%%

