#include <stdio.h>
#include <string.h>
#include "tokens.h"

#define getVariableName(x) #x

int yylex();

int main (int argc, char** argv){
    int tok;
    extern char *yytext;
    extern int yyleng;
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
        fprintf(yyout, "%s %d %s\n", getVariableName(tok), tok, yytext);
    }

    if (tok == -1){
        if (yyleng > 100){
            fprintf(stderr, "Failed. Max length of variable exceeded");
            return -1;
        }
        fprintf(stderr, "Failed due to other reasons.");
        return -1;
    }

    //printf("%s = %d\n",getVariableName(TOK_MAIN),TOK_MAIN);

    return 0;
}