#include <stdio.h>
#include <stdlib.h>
#include "symbols_table.h"


int main (int argc, char** argv){
    FILE *entrada = NULL;
    FILE *salida = NULL;

    if (argc != 3){
        printf("Error, pocos argumentos.\n");
        return -1;       
    } 

    entrada = fopen(argv[1], "r");
    if (entrada == NULL) {
        printf("Error when openning the input file.\n");
        return -1;
    }
    
    salida = fopen(argv[2], "w");
    if (salida == NULL){
        printf("Error while opening output file.\n");
        return -1;
    }


    int ret = handle_in_out(entrada, salida);


    fclose(entrada);
    fclose(salida);

    return 0;
}