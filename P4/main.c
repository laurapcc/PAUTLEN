#include <stdio.h>
#include <stdlib.h>
#include "tablaSimbols.h"


int main (int argc, char** argv){

    hash_table *table = NULL;
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


    table = createTable();
    if (table == NULL) {
        printf("Error when creating the table.\n");
    }

    char* line = NULL, *token1 = NULL, *token2 = NULL;
    size_t len = 0;
    ssize_t read;
    int type; 

    while ((read = getline(&line, &len, entrada)) != -1) {
         /* walk through other tokens */
        token1 = strtok(line, " ");
        token2 = strtok(NULL, " ");
        if (token2) {
            type = atoi(token2);

            if (type == -999) {
                if (closeScope(table) == FAILURE) {
                    fprintf(salida, "-1 %s\n", token1);
                }
                else {
                    fprintf(salida, "%s\n", token1);
                }
            }
            else if (type < -1) {
                if (openScope(table, token1, type) == FAILURE) {
                    fprintf(salida, "-1 %s\n", token1);
                }
                else {
                    fprintf(salida, "%s\n", token1);
                }
            }
            else {
                if (addElement(table, token1, type) == FAILURE) {
                    fprintf(salida, "-1 %s\n", token1);
                }
                else {
                    fprintf(salida, "%s\n", token1);
                }
            }
        } 
        else {
            if (searchElement(table, token1) == FAILURE) {
                fprintf(salida, "%s -1\n", token1);
            }
            else {
                fprintf(salida, "%s\n", token1);
            }
        }

    }


    deleteTable(table);
    fclose(entrada);
    fclose(salida);

    return 0;
}