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

void ifthenelse_inicio(FILE * fpasm, int exp_es_variable, int etiqueta);
/*
Generación de código para el inicio de una estructura if-then-else
Como es el inicio de uno bloque de control de flujo de programa que requiere de una nueva
etiqueta deben ejecutarse antes las tareas correspondientes a esta situación
exp_es_variable
Es 1 si la expresión de la condición es algo asimilable a una variable (identificador,
elemento de vector)
Es 0 en caso contrario (constante u otro tipo de expresión)
*/

void ifthen_inicio(FILE * fpasm, int exp_es_variable, int etiqueta);
/*
Generación de código para el inicio de una estructura if-then
Como es el inicio de uno bloque de control de flujo de programa que requiere de una nueva
etiqueta deben ejecutarse antes las tareas correspondientes a esta situación
exp_es_variable
Es 1 si la expresión de la condición es algo asimilable a una variable (identificador,
elemento de vector)
Es 0 en caso contrario (constante u otro tipo de expresión)
*/

void ifthen_fin(FILE * fpasm, int etiqueta);
/*
Generación de código para el fin de una estructura if-then
Como es el fin de uno bloque de control de flujo de programa que hace uso de la etiqueta
del mismo se requiere que antes de su invocación tome el valor de la etiqueta que le toca
según se ha explicado
Y tras ser invocada debe realizar el proceso para ajustar la información de las etiquetas
puesto que se ha liberado la última de ellas.
*/

void ifthenelse_fin_then( FILE * fpasm, int etiqueta);
/*
Generación de código para el fin de la rama then de una estructura if-then-else
Sólo necesita usar la etiqueta adecuada, aunque es el final de una rama, luego debe venir
otra (la rama else) antes de que se termine la estructura y se tenga que ajustar las etiquetas
por lo que sólo se necesita que se utilice la etiqueta que corresponde al momento actual.
*/

void ifthenelse_fin( FILE * fpasm, int etiqueta);
/*
Generación de código para el fin de una estructura if-then-else
Como es el fin de uno bloque de control de flujo de programa que hace uso de la etiqueta
del mismo se requiere que antes de su invocación tome el valor de la etiqueta que le toca
según se ha explicado
Y tras ser invocada debe realizar el proceso para ajustar la información de las etiquetas
puesto que se ha liberado la última de ellas.
*/

void while_inicio(FILE * fpasm, int etiqueta);
/*
Generación de código para el inicio de una estructura while
Como es el inicio de uno bloque de control de flujo de programa que requiere de una nueva
etiqueta deben ejecutarse antes las tareas correspondientes a esta situación
exp_es_variable
Es 1 si la expresión de la condición es algo asimilable a una variable (identificador,
elemento de vector)
Es 0 en caso contrario (constante u otro tipo de expresión)
*/

void while_exp_pila (FILE * fpasm, int exp_es_variable, int etiqueta);
/*
Generación de código para el momento en el que se ha generado el código de la expresión
de control del bucle
Sólo necesita usar la etiqueta adecuada, por lo que sólo se necesita que se recupere el valor
de la etiqueta que corresponde al momento actual.
exp_es_variable
Es 1 si la expresión de la condición es algo asimilable a una variable (identificador,
o elemento de vector)
Es 0 en caso contrario (constante u otro tipo de expresión)
*/

void while_fin( FILE * fpasm, int etiqueta);
/*
Generación de código para el final de una estructura while
Como es el fin de uno bloque de control de flujo de programa que hace uso de la etiqueta
del mismo se requiere que antes de su invocación tome el valor de la etiqueta que le toca
según se ha explicado
Y tras ser invocada debe realizar el proceso para ajustar la información de las etiquetas
puesto que se ha liberado la última de ellas.
*/

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

void declararFuncion(FILE * fd_asm, char * nombre_funcion, int num_var_loc);
/*
Generación de código para iniciar la declaración de una función.
Es necesario proporcionar
Su nombre
Su número de variables locales
*/

void retornarFuncion(FILE * fd_asm, int es_variable);
/*
Generación de código para el retorno de una función.
La expresión que se retorna está en la cima de la pila.
Puede ser una variable (o algo equivalente) en cuyo caso exp_es_direccion vale 1
Puede ser un valor concreto (en ese caso exp_es_direccion vale 0)
*/

void escribirParametro(FILE* fpasm, int pos_parametro, int num_total_parametros);
/*
Función para dejar en la cima de la pila la dirección efectiva del parámetro que ocupa la
posición pos_parametro (recuerda que los parámetros se ordenan con origen 0) de un total
de num_total_parametros
*/

void escribirVariableLocal(FILE* fpasm, int posicion_variable_local);
/*
Función para dejar en la cima de la pila la dirección efectiva de la variable local que ocupa
la posición posicion_variable_local (recuerda que ordenadas con origen 1)
*/

void asignarDestinoEnPila(FILE* fpasm, int es_variable);
/*
Función para poder asignar a un destino que no es una variable “global” (tipo _x) por
ejemplo parámetros o variables locales (ya que en ese caso su nombre real de alto nivel, no
se tiene en cuenta pues es realmente un desplazamiento a partir de ebp: ebp+4 o ebp-8 por
ejemplo).
Se debe asumir que en la pila estará
Primero (en la cima) lo que hay que asignar
Debajo (se ha introducido en la pila antes) la dirección donde hay que asignar
es_variable
Es 1 si la expresión que se va a asignar es algo asimilable a una variable
(identificador, o elemento de vector)
Es 0 en caso contrario (constante u otro tipo de expresión)
*/

void operandoEnPilaAArgumento(FILE * fd_asm, int es_variable);
/*
Como habrás visto en el material, nuestro convenio de llamadas a las funciones asume que
los argumentos se pasan por valor, esto significa que siempre se dejan en la pila “valores” y
no “variables”
Esta función realiza la tarea de dado un operando escrito en la pila y sabiendo si es variable
o no (es_variable) se deja en la pila el valor correspondiente
*/

void llamarFuncion(FILE * fd_asm, char * nombre_funcion, int num_argumentos);
/*
Esta función genera código para llamar a la función nombre_funcion asumiendo que los
argumentos están en la pila en el orden fijado en el material de la asignatura.
Debe dejar en la cima de la pila el retorno de la función tras haberla limpiado de sus
argumentos
Para limpiar la pila puede utilizar la función de nombre limpiarPila
*/

void limpiarPila(FILE * fd_asm, int num_argumentos);
/*
Genera código para limpiar la pila tras invocar una función
Esta función es necesaria para completar la llamada a métodos, su gestión dificulta el
conocimiento por parte de la función de llamada del número de argumentos que hay en la
pila
*/


void main(){
    FILE *f = fopen("a.txt", "w+");
    escribir_cabecera_bss(f);
}
