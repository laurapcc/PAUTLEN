all: 
	gcc -c tablaSimbolos.c
	gcc -c symbols_table.c
	gcc tablaSimbolos.o symbols_table.o -o tablaSimbolos

run:
	./tablaSimbolos entrada.txt mi_salida.txt 
	
compare: 
	diff -bB salida.txt mi_salida.txt 

clean:
	rm -rf *.o tablaSimbolos mi_salida.txt

