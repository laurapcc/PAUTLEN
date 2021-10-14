#include <stdio.h>
#include "tokens.h"

int main (int argc, char** argv){
    FILE *input = NULL, *output = NULL;

    if (argc != 3){
        printf("Error, pocos argumentos.\n");
        return -1;       
    } 

    input = fopen(argv[1], "r");
    if (input == NULL) {
        printf("Error when openning the input file.\n");
        return -1;
    }
    
    output = fopen(argv[2], "w");
    if (output == NULL){
        printf("Error while opening output file.\n");
        return -1;
    }

    while (yylex(input) != 0){
        fprintf(output, yylex(input));
    }

    printf("%d", TOK_MAIN);

    return 0;
}