%{
#include <stdio.h>
#include "symbols_table/symbols_table.h"
#include "code_generation/generacion.h"
#include "alfa.h"
#include "y.tab.h"

extern FILE * yyout;
extern int yline;
extern int ycol;
extern int err_morf;
extern int yyleng;

int yylex();
void yyerror(const char *s);


/** GLOBAL VARIABLES **/
symbols_table *table;

int tipo_actual; /* INT or BOOLEAN */
int clase_actual; /* ESCALAR or VECTOR */
int tamanio = 1;
int funcion_retorno = 0;
int funcion_tipo;
int num_total_parametros = 0;
int num_total_var_locales = 0;
int etiqueta = 0;
int dentro_fun = 0; /* 1 si estamos dentro de la llamada de una funcion */
int pos_parametro; /* solo para elementos de tipo parametro */ 
int pos_var_local = 0; /* solo para variables locales */
int num_arg_funcion = 0;


%}


%union {
    tipo_atributos atributos;
}

%token <atributos> TOK_IDENTIFICADOR
%token <atributos> TOK_CONSTANTE_ENTERA
%token <atributos> TOK_CONSTANTE_REAL


/* Tokens sin valor semantico */
%token TOK_MAIN
%token TOK_INT
%token TOK_BOOLEAN
%token <atributos> TOK_ARRAY
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

%token TOK_TRUE
%token TOK_FALSE

%token TOK_ERROR

/* No terminales con atributos semanticos */
%type <atributos> condicional
%type <atributos> comparacion
%type <atributos> elemento_vector
%type <atributos> exp
%type <atributos> constante
%type <atributos> constante_entera
%type <atributos> constante_logica
%type <atributos> identificador


%left TOK_IGUAL TOK_MENORIGUAL TOK_MENOR TOK_MAYORIGUAL TOK_MAYOR TOK_DISTINTO
%left TOK_MAS TOK_MENOS TOK_OR
%left TOK_ASTERISCO TOK_DIVISION TOK_AND
%right TOK_NOT

%%

programa: inicioTabla TOK_MAIN TOK_LLAVEIZQUIERDA declaraciones write_before_main funciones  write_inicio_main sentencias TOK_LLAVEDERECHA  {
    fprintf(yyout,";R1:\t<programa> ::= main { <declaraciones> <funciones> <sentencias> }\n");
    escribir_fin(yyout);

    /*
    tipo_atributos t;
    t.tipo = BOOLEAN;
    fprintf(yyout,"Tipo: %d\n", t.tipo);
    fprintf(yyout,"MAX_TAMANIO_VECTOR: %d\n", MAX_TAMANIO_VECTOR);
    symbol * s = new_symbol("simbolooo", 99, ERROR, ERROR, ERROR, ERROR, ERROR, ERROR, ERROR, ERROR);
    print_symbol(yyout, s);
    */
};

inicioTabla: {
    table = create_table();
    if (table == NULL) {
        printf("ERRROR: Error when creating the table.\n");
        return ERROR;
    }
};

write_before_main: {
    escribir_subseccion_data(yyout);
    escribir_cabecera_bss(yyout);
    /* ESCRITURA VARIABLES EN TABLA DE SIMBOLOS
    declarar_variable(salida, "x", ENTERO, 1);
    declarar_variable(salida, "y", ENTERO, 1);
    declarar_variable(salida, "z", ENTERO, 1);
    */
    escribir_segmento_codigo(yyout);
};

write_inicio_main: {
    escribir_inicio_main(yyout);
};

declaraciones:  declaracion {
    fprintf(yyout, ";R2:\t<declaraciones> ::= <declaracion>\n");
}
                | declaracion declaraciones {
    fprintf(yyout, ";R3:\t<declaraciones> ::= <declaracion> <declaraciones>\n");
};

declaracion: clase identificadores TOK_PUNTOYCOMA {
    fprintf(yyout, ";R4:\t<declaracion> ::= <clase> <identificadores> ;\n");
};

clase:  clase_escalar {
    fprintf(yyout, ";R5:\t<clase> ::= <clase_escalar>\n");
    clase_actual = ESCALAR;
}
        | clase_vector {
    fprintf(yyout, ";R7:\t<clase> ::= <clase_vector>\n");
    clase_actual = VECTOR;
};

clase_escalar:  tipo {
    fprintf(yyout, ";R9:\t<clase_escalar> ::= <tipo>\n");
};

tipo:   TOK_INT {
    fprintf(yyout, ";R10:\t<tipo> ::= int\n");
    tipo_actual = INT;
}
        | TOK_BOOLEAN {
    fprintf(yyout, ";R11:\t<tipo> ::= boolean\n");
    tipo_actual = BOOLEAN;
};

clase_vector:   TOK_ARRAY tipo TOK_CORCHETEIZQUIERDO constante_entera TOK_CORCHETEDERECHO {
    fprintf(yyout, ";R15:\t<clase_vector> ::= array <tipo> [ <constante_entera> ]\n");
};

identificadores:    identificador {
    fprintf(yyout, ";R18:\t<identificadores> ::= <identificador>\n");
}
                    | identificador TOK_COMA identificadores {
    fprintf(yyout, ";R19:\t<identificadores> ::= <identificador> , <identificadores>\n");
};

funciones:  funcion funciones {
    fprintf(yyout, ";R20:\t<funciones> ::= <funcion> <funciones>\n");
}
            | /* EMPTY */ {
    fprintf(yyout, ";R21:\t<funciones> ::= \n");
};

funcion: TOK_FUNCTION tipo identificadores TOK_PARENTESISIZQUIERDO parametros_funcion TOK_PARENTESISDERECHO TOK_LLAVEIZQUIERDA declaraciones_funcion sentencias TOK_LLAVEDERECHA {
    fprintf(yyout, ";R22:\t<funcion> ::= function <tipo> <identificador> ( <parametros_funcion> ) { <declaraciones_funcion> <sentencias> }\n");
};

parametros_funcion: parametro_funcion resto_parametros_funcion {
    fprintf(yyout, ";R23:\t<parametros_funcion> ::= <parametro_funcion> <resto_parametros_funcion>\n");
}
                    | /* EMPTY */ {
    fprintf(yyout, ";R24:\t<parametros_funcion> ::= \n");
};

resto_parametros_funcion:   TOK_PUNTOYCOMA parametro_funcion resto_parametros_funcion {
    fprintf(yyout, ";R25:\t<resto_parametros_funcion> ::= ; <parametro_funcion> <resto_parametros_funcion>\n");
}
                            | /* EMPTY */ {
    fprintf(yyout, ";R26:\t<resto_parametros_funcion> ::= \n");
};

parametro_funcion:  tipo identificador {
    fprintf(yyout, ";R27:\t<parametro_funcion> ::= <tipo> <identificador>\n");
};

declaraciones_funcion:  declaraciones {
    fprintf(yyout, ";R28:\t<declaraciones_funcion> ::= <declaraciones>\n");
}
                        | /* EMPTY */ {  
    fprintf(yyout, ";R29:\t<declaraciones_funcion> ::= \n");
};

sentencias: sentencia {
    fprintf(yyout, ";R30:\t<sentencias> ::= <sentencia>\n");
}
            | sentencia sentencias {
    fprintf(yyout, ";R31:\t<sentencias> ::= <sentencia> <sentencias>\n");
};

sentencia:  sentencia_simple TOK_PUNTOYCOMA {
    fprintf(yyout, ";R32:\t<sentencia> ::= <sentencia_simple> ;\n");
}
            | bloque {
    fprintf(yyout, ";R33:\t<sentencia> ::= <bloque>\n");
};

sentencia_simple:   asignacion {
    fprintf(yyout, ";R34:\t<sentencia_simple> ::= <asignacion>\n");
}
                    | lectura {
    fprintf(yyout, ";R35:\t<sentencia_simple> ::= <lectura>\n");
}
                    | escritura {
    fprintf(yyout, ";R36:\t<sentencia_simple> ::= <escritura>\n");
}
                    | retorno_funcion {
    fprintf(yyout, ";R38:\t<sentencia_simple> ::= <retorno_funcion>\n");
};

bloque: condicional {
    fprintf(yyout, ";R40:\t<bloque> ::= <condicional>\n");
}
        | bucle {
    fprintf(yyout, ";R41:\t<bloque> ::= <bucle>\n");
};

asignacion: identificador TOK_ASIGNACION exp {
    fprintf(yyout, ";R43:\t<asignacion> ::= <identificador> = <exp>\n");
    $1.valor_entero = $3.valor_entero;
}
            | elemento_vector TOK_ASIGNACION exp {
    fprintf(yyout, ";R44:\t<asignacion> ::= <elemento_vector> = <exp>\n");
};

elemento_vector:    identificador  TOK_CORCHETEIZQUIERDO exp TOK_CORCHETEDERECHO {
    fprintf(yyout, ";R48:\t<elemento_vector> ::= <identificador> [ <exp> ]\n");
};

condicional:    TOK_IF TOK_PARENTESISIZQUIERDO exp TOK_PARENTESISDERECHO TOK_LLAVEIZQUIERDA sentencias TOK_LLAVEDERECHA {
    fprintf(yyout, ";R50:\t<condicional> ::= if (<exp>) {<sentencias>}\n");
}
                | TOK_IF TOK_PARENTESISIZQUIERDO exp TOK_PARENTESISDERECHO TOK_LLAVEIZQUIERDA sentencias TOK_LLAVEDERECHA TOK_ELSE TOK_LLAVEIZQUIERDA sentencias TOK_LLAVEDERECHA {
    fprintf(yyout, ";R51:\t<condicional> ::= if (<exp>) {<sentencias>} else {<sentencias>}\n");
};

bucle:  TOK_WHILE TOK_PARENTESISIZQUIERDO exp TOK_PARENTESISDERECHO TOK_LLAVEIZQUIERDA sentencias TOK_LLAVEDERECHA {
    fprintf(yyout, ";R52:\t<bucle> ::= while (<exp>) {<sentencias>}\n");
};

lectura:    TOK_SCANF identificador {
    fprintf(yyout, ";R54:\t<lectura> ::= scanf <identificador>\n");
};

escritura:  TOK_PRINTF exp {
    fprintf(yyout, ";R56:\t<escritura> ::= printf <exp>\n");
};

retorno_funcion:    TOK_RETURN exp {
    fprintf(yyout, ";R61:\t<retorno_funcion> ::= return <exp>\n");
};

exp:    exp TOK_MAS exp {
    fprintf(yyout, ";R72:\t<exp> ::= <exp> + <exp>\n");
}
        | exp TOK_MENOS exp {
    fprintf(yyout, ";R73:\t<exp> ::= <exp> - <exp>\n");
}
        | exp TOK_DIVISION exp {
    fprintf(yyout, ";R74:\t<exp> ::= <exp> / <exp>\n");
}
        | exp TOK_ASTERISCO exp {
    fprintf(yyout, ";R75:\t<exp> ::= <exp> * <exp>\n");
}
        | TOK_MENOS exp {
    fprintf(yyout, ";R76:\t<exp> ::= - <exp>\n");
}
        | exp TOK_AND exp {
    fprintf(yyout, ";R77:\t<exp> ::= <exp> && <exp>\n");
}
        | exp TOK_OR exp {
    fprintf(yyout, ";R78:\t<exp> ::= <exp> || <exp>\n");
}
        | TOK_NOT exp {
    fprintf(yyout, ";R79:\t<exp> ::= ! <exp>\n");
}
        | identificador {
    fprintf(yyout, ";R80:\t<exp> ::= <identificador>\n");
    $$.valor_entero = $1.valor_entero;
}
        | constante {
    fprintf(yyout, ";R81:\t<exp> ::= <constante>\n");
}
        | TOK_PARENTESISIZQUIERDO exp TOK_PARENTESISDERECHO {
    fprintf(yyout, ";R82:\t<exp> ::= ( <exp> )\n");
}
        | TOK_PARENTESISIZQUIERDO comparacion TOK_PARENTESISDERECHO {
    fprintf(yyout, ";R83:\t<exp> ::= ( <comparacion> )\n");
}
        | elemento_vector {
    fprintf(yyout, ";R85:\t<exp> ::= <elemento_vector>\n");
}
        | identificador TOK_PARENTESISIZQUIERDO lista_expresiones TOK_PARENTESISDERECHO {
    fprintf(yyout, ";R88:\t<exp> ::= <identificador>( <lista_expresiones> )\n");
};

lista_expresiones:  exp resto_lista_expresiones {
    fprintf(yyout, ";R89:\t<lista_expresiones> ::= <exp> <resto_lista_expresiones>\n");
}
                    | /* EMPTY */ {
    fprintf(yyout, ";R90:\t<lista_expresiones> ::=\n");
};

resto_lista_expresiones:    TOK_COMA exp resto_lista_expresiones {
    fprintf(yyout, ";R91:\t<resto_lista_expresiones> ::= , <exp> <resto_lista_expresiones>\n");
}
                            | /* EMPTY */ { 
    fprintf(yyout, ";R92:\t<resto_lista_expresiones> ::=\n");
};

comparacion:    exp TOK_IGUAL exp {
    fprintf(yyout, ";R93:\t<comparacion> ::= <exp> == <exp>\n");
}
                | exp TOK_DISTINTO exp {
    fprintf(yyout, ";R94:\t<comparacion> ::= <exp> != <exp>\n");
}
                | exp TOK_MENORIGUAL exp {
    fprintf(yyout, ";R95:\t<comparacion> ::= <exp> <= <exp>\n");
}
                | exp TOK_MAYORIGUAL {
    fprintf(yyout, ";R96:\t<comparacion> ::= <exp> >= <exp>\n");
}
                | exp TOK_MENOR exp {
    fprintf(yyout, ";R97:\t<comparacion> ::= <exp> < <exp>\n");
}
                | exp TOK_MAYOR exp {
    fprintf(yyout, ";R98:\t<comparacion> ::= <exp> > <exp>\n");
};

constante:  constante_logica {
    fprintf(yyout, ";R99:\t<constante> ::= <constante_logica>\n");
}
            | constante_entera {
    fprintf(yyout, ";R100:\t<constante> ::= <constante_entera>\n");
};

constante_logica:   TOK_TRUE {
    fprintf(yyout, ";R102:\t<constante_logica> ::= true\n");
}
                    | TOK_FALSE {
    fprintf(yyout, ";R103:\t<constante_logica> ::= false\n");
};

constante_entera:   TOK_CONSTANTE_ENTERA {
    fprintf(yyout, ";R104:\t<contante_entera> ::= TOK_CONSTANTE_ENTERA\n");
};

identificador:  TOK_IDENTIFICADOR {
    fprintf(yyout, ";R108:\t<identificador> ::= TOK_IDENTIFICADOR\n");
    symbol * s = search_current_scope(table, $1.lexema);
    if (s != NULL) {
        printf("****Error semantico en lin %d: Declaracion duplicada.\n", yline);
        return ERROR;
    } 

    if(actual_scope(table) == GLOBAL) {
        declare_global(table, $1.lexema, $1.valor_entero, VARIABLE, clase_actual, tipo_actual, ERROR, ERROR, pos_var_local, ERROR, ERROR);
    } else { // local scope
        declare_local(table, $1.lexema, $1.valor_entero, VARIABLE, clase_actual, tipo_actual, ERROR, ERROR, pos_var_local, ERROR, ERROR);
    }
};

%%

void yyerror(const char *s){

    if(!err_morf){
        printf("****Error sintactico en [lin %d, col %d]\n", yline, ycol);
        return;
    }

    err_morf = 0;
    return;
}

