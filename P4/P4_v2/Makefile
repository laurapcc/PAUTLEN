run: 
	gcc -c main.c
	gcc -c symbols_table.c
	gcc main.o symbols_table.o -o main
	./main entrada.txt mi_salida.txt 
compare: 
	diff -bB salida.txt mi_salida.txt 

clean:
	rm -rf *.o main mi_salida.txt

