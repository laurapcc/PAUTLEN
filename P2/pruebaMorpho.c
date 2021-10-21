#include <stdio.h>
#include <string.h>
#include "tokens.h"



int yylex();

const char* getTokenName(int tok){

    switch (tok){
        case TOK_MAIN:
            return "TOK_MAIN";
        case TOK_INT:
            return "TOK_INT";
        case TOK_BOOLEAN:
            return "TOK_BOOLEAN";
        case TOK_ARRAY:
            return "TOK_ARRAY";
        case TOK_FUNCTION:
            return "TOK_FUNCTION";
        case TOK_IF:
            return "TOK_IF";
        case TOK_ELSE:
            return "TOK_ELSE";
        case TOK_WHILE:
            return "TOK_WHILE";
        case TOK_SCANF:
            return "TOK_SCANF";
        case TOK_PRINTF:
            return "TOK_PRINTF";
        case TOK_RETURN:
            return "TOK_RETURN";
        case TOK_PUNTOYCOMA:
            return "TOK_PUNTOYCOMA";
        case TOK_COMA:
            return "TOK_COMA";
        case TOK_PARENTESISIZQUIERDO:
            return "TOK_PARENTESISIZQUIERDO";
        case TOK_PARENTESISDERECHO:
            return "TOK_PARENTESISDERECHO";
        case TOK_CORCHETEIZQUIERDO:
            return "TOK_CORCHETEIZQUIERDO";
        case TOK_CORCHETEDERECHO:
            return "TOK_CORCHETEDERECHO";
        case TOK_LLAVEIZQUIERDA:
            return "TOK_LLAVEIZQUIERDA";
        case TOK_LLAVEDERECHA:
            return "TOK_LLAVEDERECHA";
        case TOK_ASIGNACION:
            return "TOK_ASIGNACION";
        case TOK_MAS:
            return "TOK_MAS";
        case TOK_MENOS:
            return "TOK_MENOS";
        case TOK_DIVISION:
            return "TOK_DIVISION";
        case TOK_ASTERISCO:
            return "TOK_ASTERISCO";
        case TOK_AND:
            return "TOK_AND";
        case TOK_OR:
            return "TOK_OR";
        case TOK_NOT:
            return "TOK_NOT";
        case TOK_IGUAL:
            return "TOK_IGUAL";
        case TOK_DISTINTO:
            return "TOK_DISTINTO";
        case TOK_MENORIGUAL:
            return "TOK_MENORIGUAL";
        case TOK_MAYORIGUAL:
            return "TOK_MAYORIGUAL";
        case TOK_MENOR:
            return "TOK_MENOR";
        case TOK_MAYOR:
            return "TOK_MAYOR";
        case TOK_IDENTIFICADOR:
            return "TOK_IDENTIFICADOR";
        case TOK_CONSTANTE_ENTERA:
            return "TOK_CONSTANTE_ENTERA";
        case TOK_TRUE:
            return "TOK_TRUE";
        case TOK_FALSE:
            return "TOK_FALSE";
        case TOK_ERROR:
            return "TOK_ERROR";
    }

    return "ERORR!!!";
}

int main (int argc, char** argv){
    int tok;
    extern char *yytext;
    extern int yyleng, ycol, yline;
    extern FILE *yyin;
    extern FILE *yyout;

    if (argc != 3){
        printf("Error, pocos argumentos.\n");
        return -1;       
    } 

    yyin = fopen(argv[1], "r");
    if (yyin == NULL) {
        printf("Error when openning the input file.\n");
        return -1;
    }
    
    yyout = fopen(argv[2], "w");
    if (yyout == NULL){
        printf("Error while opening output file.\n");
        return -1;
    }

    while ((tok = yylex(yyin)) > 0){
        fprintf(yyout, "%s %d %s\n", getTokenName(tok), tok, yytext);
    }

    if (tok == -1){
        if (yyleng > 100){
            fprintf(stderr, "Failed in [line %d, column %d] Max length of variable exceeded (%s)", yline, ycol, yytext);
            return -1;
        }
        fprintf(stderr, "Failed due to other reasons.");
        return -1;
    }

    return 0;
}
