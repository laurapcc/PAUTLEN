#include "generacion.h"


/* OBSERVACIÓN GENERAL A TODAS LAS FUNCIONES:
Todas ellas escriben el código NASM a un FILE* proporcionado como primer
argumento.
*/

void escribir_cabecera_bss(FILE* fpasm) {
    if(fpasm == NULL) return;

    fprintf(fpasm, "segment .bss\n");
    fprintf(fpasm, "__esp resd 1\n");    
}
/*
Código para el principio de la sección .bss.
Con seguridad sabes que deberás reservar una variable entera para guardar el
puntero de pila extendido (esp). Se te sugiere el nombre __esp para esta variable.
*/

void escribir_subseccion_data(FILE* fpasm){
    if (fpasm == NULL) return;

    fprintf(fpasm, "segment .data\n");
    fprintf(fpasm, "error_div_by_zero db 'Error, division by zero.', 0\n");
}
/*
Declaración (con directiva db) de las variables que contienen el texto de los
mensajes para la identificación de errores en tiempo de ejecución.
En este punto, al menos, debes ser capaz de detectar la división por 0.
*/

//NO SE PORQ LA VARIABLE TIPO
void declarar_variable(FILE* fpasm, char * nombre, int tipo, int tamano){
    if (fpasm == NULL) return;

    fprintf(fpasm, "_%s resd %d\n", nombre, tamano);
}
/*
Para ser invocada en la sección .bss cada vez que se quiera declarar una
variable:
- El argumento nombre es el de la variable.
- tipo puede ser ENTERO o BOOLEANO (observa la declaración de las constantes
del principio del fichero).
- Esta misma función se invocará cuando en el compilador se declaren
vectores, por eso se adjunta un argumento final (tamano) que para esta
primera práctica siempre recibirá el valor 1.
*/

void escribir_segmento_codigo(FILE* fpasm) {
    if(fpasm == NULL) return;

    fprintf(fpasm, "segment .txt\n");
    fprintf(fpasm, "global main\n");
    fprintf(fpasm, "extern print_int, scan_int, scan_boolean, print_boolean, print_blank, print_string, print_endofline\n");

}
/*
Para escribir el comienzo del segmento .text, básicamente se indica que se
exporta la etiqueta main y que se usarán las funciones declaradas en la librería
alfalib.o
*/

void escribir_inicio_main(FILE* fpasm){
    if(fpasm == NULL) return;
    fprintf(fpasm, "main:\n");
    fprintf(fpasm, "mov dword [__esp], esp\n");
}
/*
En este punto se debe escribir, al menos, la etiqueta main y la sentencia que
guarda el puntero de pila en su variable (se recomienda usar __esp).
*/

void escribir_fin(FILE* fpasm) {
    if(fpasm == NULL) return;
    
    // Division by 0.
    fprintf(fpasm, "div_by_zero:\n");
    fprintf(fpasm, "push dword error_div_by_zero\n");
    fprintf(fpasm, "call print_string\n");
    fprintf(fpasm, "call print_endofline\n");
    fprintf(fpasm, "add dword esp, 4\n");
    fprintf(fpasm, "jmp end_program\n");
    

    // End program.
    fprintf(fpasm, "end_program:\n");
    fprintf(fpasm, "mov dword esp, [__esp]\n");
    fprintf(fpasm, "ret\n");
}
/*
Al final del programa se escribe:
- El código NASM para salir de manera controlada cuando se detecta un error
en tiempo de ejecución (cada error saltará a una etiqueta situada en esta
zona en la que se imprimirá el correspondiente mensaje y se saltará a la
zona de finalización del programa).
- En el final del programa se debe:
·Restaurar el valor del puntero de pila (a partir de su variable __esp)
·Salir del programa (ret).
*/

void escribir_operando(FILE* fpasm, char* nombre, int es_variable) {
    if (fpasm == NULL || nombre == NULL) return;

    if (es_variable == 0){
        fprintf(fpasm, "mov dword eax, %s\n", nombre);
        fprintf(fpasm, "push dword eax\n");
    }
    else if (es_variable == 1)
        fprintf(fpasm, "push dword _%s\n", nombre);
}
/*
Función que debe ser invocada cuando se sabe un operando de una operación
aritmético-lógica y se necesita introducirlo en la pila.
- nombre es la cadena de caracteres del operando tal y como debería aparecer
en el fuente NASM
- es_variable indica si este operando es una variable (como por ejemplo b1)
con un 1 u otra cosa (como por ejemplo 34) con un 0. Recuerda que en el
primer caso internamente se representará como _b1 y, sin embargo, en el
segundo se representará tal y como esté en el argumento (34).
*/

void asignar(FILE* fpasm, char* nombre, int es_variable) {
    if (fpasm == NULL || nombre == NULL) return;

    if (es_variable == 0){
        fprintf(fpasm, "pop dword [_%s]\n", nombre);
    }
    else if (es_variable == 1){
        fprintf(fpasm, "pop dword eax\n");
        fprintf(fpasm, "mov dword _%s, [eax]\n", nombre);
    }
}
/*
- Genera el código para asignar valor a la variable de nombre nombre.
- Se toma el valor de la cima de la pila.
- El último argumento es el que indica si lo que hay en la cima de la pila es
una referencia (1) o ya un valor explícito (0).
*/

/* FUNCIONES ARITMÉTICO-LÓGICAS BINARIAS */
/*
En todas ellas se realiza la operación como se ha resumido anteriormente:
- Se extrae de la pila los operandos
- Se realiza la operación
- Se guarda el resultado en la pila
Los dos últimos argumentos indican respectivamente si lo que hay en la pila es
una referencia a un valor o un valor explícito.

Deben tenerse en cuenta las peculiaridades de cada operación. En este sentido
sí hay que mencionar explícitamente que, en el caso de la división, se debe
controlar si el divisor es “0” y en ese caso se debe saltar a la rutina de error
controlado (restaurando el puntero de pila en ese caso y comprobando en el retorno
que no se produce “Segmentation Fault”)
*/
void sumar(FILE* fpasm, int es_variable_1, int es_variable_2) {
    if (fpasm == NULL) return;

    /* store variable 1 in eax */
    if (es_variable_1 == 0)
        fprintf(fpasm, "pop dword eax\n");
    else if (es_variable_1 == 1){
        fprintf(fpasm, "pop dword ecx\n");
        fprintf(fpasm, "mov dword eax, [ecx]\n");
    }

    /* store variable 2 in ebx */
    if (es_variable_2 == 0)
        fprintf(fpasm, "pop dword ebx\n");
    else if (es_variable_2 == 1){
        fprintf(fpasm, "pop dword ecx\n");
        fprintf(fpasm, "mov dword ebx, [ecx]\n");
    }

    /* perform operation and store result in stack */
    fprintf(fpasm, "sub eax, ebx\n");
    fprintf(fpasm, "push dword eax\n");
}

void restar(FILE* fpasm, int es_variable_1, int es_variable_2){
    if (fpasm == NULL) return;

    /* store variable 1 in eax */
    if (es_variable_1 == 0)
        fprintf(fpasm, "pop dword eax\n");
    else if (es_variable_1 == 1){
        fprintf(fpasm, "pop dword ecx\n");
        fprintf(fpasm, "mov dword eax, [ecx]\n");
    }

    /* store variable 2 in ebx */
    if (es_variable_2 == 0)
        fprintf(fpasm, "pop dword ebx\n");
    else if (es_variable_2 == 1){
        fprintf(fpasm, "pop dword ecx\n");
        fprintf(fpasm, "mov dword ebx, [ecx]\n");
    }

    /* perform operation and store result in stack */
    fprintf(fpasm, "add eax, ebx\n");
    fprintf(fpasm, "push dword eax\n");
}

void multiplicar(FILE* fpasm, int es_variable_1, int es_variable_2) {
    if (fpasm == NULL) return;

    /* store variable 1 in eax */
    if (es_variable_1 == 0)
        fprintf(fpasm, "pop dword eax\n");
    else if (es_variable_1 == 1){
        fprintf(fpasm, "pop dword ecx\n");
        fprintf(fpasm, "mov dword eax, [ecx]\n");
    }

    /* store variable 2 in ebx */
    if (es_variable_2 == 0)
        fprintf(fpasm, "pop dword ebx\n");
    else if (es_variable_2 == 1){
        fprintf(fpasm, "pop dword ecx\n");
        fprintf(fpasm, "mov dword ebx, [ecx]\n");
    }

    /* multiply eax times ebx and store result in stack */
    fprintf(fpasm, "imul ebx\n");
    fprintf(fpasm, "push dword eax\n");
}

void dividir(FILE* fpasm, int es_variable_1, int es_variable_2) {
    if (fpasm == NULL) return;

    /* store variable 1 in eax */
    if (es_variable_1 == 0)
        fprintf(fpasm, "pop dword eax\n");
    else if (es_variable_1 == 1){
        fprintf(fpasm, "pop dword ecx\n");
        fprintf(fpasm, "mov dword eax, [ecx]\n");
    }

    /* store variable 2 in ebx */
    if (es_variable_2 == 0)
        fprintf(fpasm, "pop dword ebx\n");
    else if (es_variable_2 == 1){
        fprintf(fpasm, "pop dword ecx\n");
        fprintf(fpasm, "mov dword ebx, [ecx]\n");
    }

    /* check denominator != 0 */
    fprintf(fpasm, "cmp ebx, 0\n");
    fprintf(fpasm, "je div_by_zero\n");

    /* perform operation and store result in stack */
    fprintf(fpasm, "cdq\n");
    fprintf(fpasm, "idiv ebx\n");
    fprintf(fpasm, "push dword eax\n");
}

void o(FILE* fpasm, int es_variable_1, int es_variable_2) {
    if (fpasm == NULL) return;

    /* store variable 1 in eax */
    if (es_variable_1 == 0)
        fprintf(fpasm, "pop dword eax\n");
    else if (es_variable_1 == 1){
        fprintf(fpasm, "pop dword ecx\n");
        fprintf(fpasm, "mov dword eax, [ecx]\n");
    }

    /* store variable 2 in ebx */
    if (es_variable_2 == 0)
        fprintf(fpasm, "pop dword ebx\n");
    else if (es_variable_2 == 1){
        fprintf(fpasm, "pop dword ecx\n");
        fprintf(fpasm, "mov dword ebx, [ecx]\n");
    }

    /* perform operation and store result in stack */
    fprintf(fpasm, "or eax, ebx\n");
    fprintf(fpasm, "push dword eax\n");
}
void y(FILE* fpasm, int es_variable_1, int es_variable_2) {
    if (fpasm == NULL) return;

    /* store variable 1 in eax */
    if (es_variable_1 == 0)
        fprintf(fpasm, "pop dword eax\n");
    else if (es_variable_1 == 1){
        fprintf(fpasm, "pop dword ecx\n");
        fprintf(fpasm, "mov dword eax, [ecx]\n");
    }

    /* store variable 2 in ebx */
    if (es_variable_2 == 0)
        fprintf(fpasm, "pop dword ebx\n");
    else if (es_variable_2 == 1){
        fprintf(fpasm, "pop dword ecx\n");
        fprintf(fpasm, "mov dword ebx, [ecx]\n");
    }

    /* perform operation and store result in stack */
    fprintf(fpasm, "and eax, ebx\n");
    fprintf(fpasm, "push dword eax\n");
}
void cambiar_signo(FILE* fpasm, int es_variable) {
    if (fpasm == NULL) return;

    /* store variable in eax */
    if (es_variable == 0)
        fprintf(fpasm, "pop dword eax\n");
    else if (es_variable == 1){
        fprintf(fpasm, "pop dword ecx\n");
        fprintf(fpasm, "mov dword eax, [ecx]\n");
    }

    /* perform operation and store result in stack */
    fprintf(fpasm, "neg eax\n");
    fprintf(fpasm, "push dword eax\n");
}
/*
Función aritmética de cambio de signo.
Es análoga a las binarias, excepto que sólo requiere de un acceso a la pila ya
que sólo usa un operando.
*/
void no(FILE* fpasm, int es_variable, int cuantos_no) {
    if (fpasm == NULL) return;

    if (es_variable == 0){
        fprintf(fpasm, "pop dword ebx\n");
    }
    else if (es_variable == 1){
        fprintf(fpasm, "pop dword eax\n");
        fprintf(fpasm, "mov dword ebx,[eax]\n");
    }

    fprintf(fpasm,"cmp ebx, 0\n");
    fprintf(fpasm, "je no_uno_%d", cuantos_no);
    /* Si en ebx hay un 1, escribo un 0*/
    fprintf(fpasm, "push dword 0\n");
    fprintf(fpasm, "jmp uno_%d\n", cuantos_no);
    
    fprintf(fpasm, "no_uno_%d:\n", cuantos_no);
    /* Si en ebx hay un 0, escribo un 1*/
    fprintf(fpasm,"push dword 1\n");

    fprintf(fpasm, "uno_%d:\n", cuantos_no);
}

/* FUNCIONES COMPARATIVAS */
/*
Todas estas funciones reciben como argumento si los elementos a comparar son o
no variables. El resultado de las operaciones, que siempre será un booleano (“1”
si se cumple la comparación y “0” si no se cumple), se deja en la pila como en el
resto de operaciones. Se deben usar etiquetas para poder gestionar los saltos
necesarios para implementar las comparaciones.
*/
void igual(FILE* fpasm, int es_variable1, int es_variable2, int etiqueta) {
    if (fpasm == NULL) return;

    if (es_variable1 == 1){
        fprintf(fpasm, "pop dword eax\n");
        fprintf(fpasm, "mov dword ebx, [eax]\n");
    }
    else if (es_variable1 == 0){
        fprintf(fpasm, "pop dword ebx\n");
    }

    if (es_variable2 == 1){
        fprintf(fpasm, "pop dword eax\n");
        fprintf(fpasm, "mov dword ecx, [eax]\n");
    }
    else if(es_variable2 == 0){
        fprintf(fpasm, "pop dword ecx\n");
    }

    fprintf(fpasm, "cmp ebx, ecx\n");
    fprintf(fpasm, "je same_%d\n", etiqueta);
    /* Si no son iguales escribimos un 0 */
    fprintf(fpasm, "push dword 0\n");
    fprintf(fpasm, "jmp distintos_%d\n", etiqueta);

    fprintf(fpasm, "same_%d:\n", etiqueta);
    /* Si son iguales escribimos un 1 */
    fprintf(fpasm, "push dword 1\n");

    fprintf(fpasm, "distintos_%d:\n", etiqueta);
}

void distinto(FILE* fpasm, int es_variable1, int es_variable2, int etiqueta) {
    if (fpasm == NULL) return;

    if (es_variable1 == 1){
        fprintf(fpasm, "pop dword eax\n");
        fprintf(fpasm, "mov dword ebx, [eax]\n");
    }
    else if (es_variable1 == 0){
        fprintf(fpasm, "pop dword ebx\n");
    }

    if (es_variable2 == 1){
        fprintf(fpasm, "pop dword eax\n");
        fprintf(fpasm, "mov dword ecx, [eax]\n");
    }
    else if(es_variable2 == 0){
        fprintf(fpasm, "pop dword ecx\n");
    }

    fprintf(fpasm, "cmp ebx, ecx\n");
    fprintf(fpasm, "je same_%d\n", etiqueta);
    /* Si no son iguales escribimos un 1 */
    fprintf(fpasm, "push dword 1\n");
    fprintf(fpasm, "jmp distintos_%d\n", etiqueta);

    fprintf(fpasm, "same_%d:\n", etiqueta);
    /* Si son iguales escribimos un 0 */
    fprintf(fpasm, "push dword 0\n");

    fprintf(fpasm, "distintos_%d:\n", etiqueta);
}

void menor_igual(FILE* fpasm, int es_variable1, int es_variable2, int etiqueta) {
    if (fpasm == NULL) return;

    if (es_variable1 == 1){
        fprintf(fpasm, "pop dword eax\n");
        fprintf(fpasm, "mov dword ebx, [eax]\n");
    }
    else if (es_variable1 == 0){
        fprintf(fpasm, "pop dword ebx\n");
    }

    if (es_variable2 == 1){
        fprintf(fpasm, "pop dword eax\n");
        fprintf(fpasm, "mov dword ecx, [eax]\n");
    }
    else if(es_variable2 == 0){
        fprintf(fpasm, "pop dword ecx\n");
    }

    fprintf(fpasm, "cmp ebx, ecx\n");
    fprintf(fpasm, "jle menor_igual_%d\n", etiqueta);
    /* Si son mayores escribimos un 0 */
    fprintf(fpasm, "push dword 0\n");
    fprintf(fpasm, "jmp mayor_%d\n", etiqueta);

    fprintf(fpasm, "menor_igual_%d:\n", etiqueta);
    /* Si son iguales escribimos un 1 */
    fprintf(fpasm, "push dword 1\n");

    fprintf(fpasm, "mayor_%d:\n", etiqueta);
}

void mayor_igual(FILE* fpasm, int es_variable1, int es_variable2, int etiqueta) {
    if (fpasm == NULL) return;

    if (es_variable1 == 1){
        fprintf(fpasm, "pop dword eax\n");
        fprintf(fpasm, "mov dword ebx, [eax]\n");
    }
    else if (es_variable1 == 0){
        fprintf(fpasm, "pop dword ebx\n");
    }

    if (es_variable2 == 1){
        fprintf(fpasm, "pop dword eax\n");
        fprintf(fpasm, "mov dword ecx, [eax]\n");
    }
    else if(es_variable2 == 0){
        fprintf(fpasm, "pop dword ecx\n");
    }

    fprintf(fpasm, "cmp ebx, ecx\n");
    fprintf(fpasm, "jge mayor_igual_%d\n", etiqueta);
    /* Si son menores escribimos un 0 */
    fprintf(fpasm, "push dword 0\n");
    fprintf(fpasm, "jmp menor_%d\n", etiqueta);

    fprintf(fpasm, "mayor_igual_%d:\n", etiqueta);
    /* Si son iguales escribimos un 1 */
    fprintf(fpasm, "push dword 1\n");

    fprintf(fpasm, "menor_%d:\n", etiqueta);
}

void menor(FILE* fpasm, int es_variable1, int es_variable2, int etiqueta) {
    if (fpasm == NULL) return;

    if (es_variable1 == 1){
        fprintf(fpasm, "pop dword eax\n");
        fprintf(fpasm, "mov dword ebx, [eax]\n");
    }
    else if (es_variable1 == 0){
        fprintf(fpasm, "pop dword ebx\n");
    }

    if (es_variable2 == 1){
        fprintf(fpasm, "pop dword eax\n");
        fprintf(fpasm, "mov dword ecx, [eax]\n");
    }
    else if(es_variable2 == 0){
        fprintf(fpasm, "pop dword ecx\n");
    }

    fprintf(fpasm, "cmp ebx, ecx\n");
    fprintf(fpasm, "jl menor_%d\n", etiqueta);
    /* Si no es menor escribimos un 0 */
    fprintf(fpasm, "push dword 0\n");
    fprintf(fpasm, "jmp mayor_igual_%d\n", etiqueta);

    fprintf(fpasm, "menor_%d:\n", etiqueta);
    /* Si es menor escribimos un 1 */
    fprintf(fpasm, "push dword 1\n");

    fprintf(fpasm, "distintos_%d:\n", etiqueta);
}

void mayor(FILE* fpasm, int es_variable1, int es_variable2, int etiqueta) {
    if (fpasm == NULL) return;

    if (es_variable1 == 1){
        fprintf(fpasm, "pop dword eax\n");
        fprintf(fpasm, "mov dword ebx, [eax]\n");
    }
    else if (es_variable1 == 0){
        fprintf(fpasm, "pop dword ebx\n");
    }

    if (es_variable2 == 1){
        fprintf(fpasm, "pop dword eax\n");
        fprintf(fpasm, "mov dword ecx, [eax]\n");
    }
    else if(es_variable2 == 0){
        fprintf(fpasm, "pop dword ecx\n");
    }

    fprintf(fpasm, "cmp ebx, ecx\n");
    fprintf(fpasm, "jg mayor_%d\n", etiqueta);
    /* Si no es mayor escribimos un 0 */
    fprintf(fpasm, "push dword 0\n");
    fprintf(fpasm, "jmp menor_igual_%d\n", etiqueta);

    fprintf(fpasm, "mayor_%d:\n", etiqueta);
    /* Si son iguales escribimos un 1 */
    fprintf(fpasm, "push dword 1\n");

    fprintf(fpasm, "menor_igual_%d:\n", etiqueta);
}

/* FUNCIONES DE ESCRITURA Y LECTURA */
/*
Se necesita saber el tipo de datos que se va a procesar (ENTERO o BOOLEANO) ya
que hay diferentes funciones de librería para la lectura (idem. escritura) de cada
tipo.
Se deben insertar en la pila los argumentos necesarios, realizar la llamada
(call) a la función de librería correspondiente y limpiar la pila.
*/

void leer(FILE* fpasm, char* nombre, int tipo) {
    if (fpasm == NULL) return;

    /* Cargamos en la pila la variable */
    fprintf(fpasm, "push dword _%s\n", nombre);

    /* LLamadas a las correspondientes funciones */
    if (tipo == ENTERO){
        fprintf(fpasm, "call scan_int\n");
    }
    else if (tipo == BOOLEANO){
        fprintf(fpasm, "call scan_boolean\n");
    }

    /* Limpiamos la pila */
    fprintf(fpasm, "add esp, 4\n");
}

void escribir(FILE* fpasm, int es_variable, int tipo) {
    if (fpasm == NULL) return;

    if (es_variable == 1){
        fprintf(fpasm, "push dword eax\n");
        fprintf(fpasm, "mov dword ebx, [eax]\n");
        fprintf(fpasm, "push dword ebx\n");
    }
    
    if (tipo == ENTERO){
        fprintf(fpasm, "call print_int\n");
    }
    else if (tipo == BOOLEANO){
        fprintf(fpasm, "call print_boolean\n");
    }

    // add 8 o 4??
    fprintf(fpasm, "add esp, 8\n");
    /* Salto de linea */
    fprintf(fpasm, "call print_endofline\n");
}

void ifthenelse_inicio(FILE * fpasm, int exp_es_variable, int etiqueta) {
    if (fpasm == NULL) return;

    if (exp_es_variable == 1){
        fprintf(fpasm, "pop dowrd eax\n");
        fprintf(fpasm, "mov ebx, [eax]\n");
    }
    else if (exp_es_variable == 0){
        fprintf(fpasm, "pop dword ebx\n");
    }
    
    fprintf(fpasm, "cmp ebx, 0\n");
    fprintf(fpasm, "je near then_%d", etiqueta);
}

void ifthen_inicio(FILE * fpasm, int exp_es_variable, int etiqueta) {
    if (fpasm == NULL) return;

    if (exp_es_variable == 1){
        fprintf(fpasm, "pop dowrd eax\n");
        fprintf(fpasm, "mov ebx, [eax]\n");
    }
    else if (exp_es_variable == 0){
        fprintf(fpasm, "pop dword ebx\n");
    }
    
    fprintf(fpasm, "cmp ebx, 0\n");
    fprintf(fpasm, "je near then_%d", etiqueta);
}

void ifthen_fin(FILE * fpasm, int etiqueta) {
    if (fpasm == NULL) return;

    fprintf(fpasm, "then_%d:\n", etiqueta);
}

void ifthenelse_fin_then( FILE * fpasm, int etiqueta) {
    if (fpasm == NULL) return;
    
    fprintf(fpasm, "jmp near then_else_%d\n", etiqueta);
    fprintf(fpasm, "then_%d:\n", etiqueta);
}

void ifthenelse_fin( FILE * fpasm, int etiqueta) {
    if (fpasm == NULL) return;

    fprintf(fpasm, "then_else_%d:\n", etiqueta);
}

void while_inicio(FILE * fpasm, int etiqueta) {
    if (fpasm == NULL) return;

    fprintf(fpasm, "while_%d:\n", etiqueta);
}   

void while_exp_pila (FILE * fpasm, int exp_es_variable, int etiqueta) {
    if (fpasm == NULL) return;

    if (exp_es_variable == 1){
        fprintf(fpasm, "pop dword eax\n");
        fprintf(fpasm, "mov ebx, [eax]\n");
    }
    else if (exp_es_variable == 0){
        fprintf(fpasm, "pop dword ebx\n");
    }

    fprintf(fpasm, "cmp ebx, 0\n");
    fprintf(fpasm, "je fin_while_%d\n", etiqueta);       
}

void while_fin( FILE * fpasm, int etiqueta) {
    if (fpasm == NULL) return;

    fprintf(fpasm, "jmp while_%d\n", etiqueta);
    fprintf(fpasm, "fin_while_%d:\n", etiqueta);
}

void escribir_elemento_vector(FILE * fpasm,char * nombre_vector,
int tam_max, int exp_es_direccion);
/*
Generación de código para indexar un vector
Cuyo nombre es nombre_vector
Declarado con un tamaño tam_max
La expresión que lo indexa está en la cima de la pila
Puede ser una variable (o algo equivalente) en cuyo caso exp_es_direccion vale 1
Puede ser un valor concreto (en ese caso exp_es_direccion vale 0)
Según se especifica en el material, es suficiente con utilizar dos registros para realizar esta
tarea.
*/

