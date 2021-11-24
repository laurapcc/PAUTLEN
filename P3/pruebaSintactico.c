#include <stdio.h>
#include <stdlib.h>

extern FILE *yyin;
extern FILE *yyout;
extern int yyparse();


int main (int argc, char** argv){

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


    int ret_value = yyparse();
    printf("Value returned by yyparse: %d\n", ret_value);
    
    fclose(yyin);
    fclose(yyout);

    return ret_value;
}