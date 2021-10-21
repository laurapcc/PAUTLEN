prueba:
	flex alfa.l
	gcc -c -o lex.yy.o lex.yy.c
	gcc -Wall -ansi -pedantic -c -o pruebamorpho.o pruebamorpho.c
	gcc -o pruebamorpho lex.yy.o pruebamorpho.o

test1:
	pruebamorpho input1.txt output1.txt

test2:
	pruebamorpho input2.txt output2.txt

compare1:
	diff –Bb input1.txt ficheros\ de\ prueba/salida1.txt

compare2:
	diff –Bb input2.txt ficheros\ de\ prueba/salida2.txt

clean: 
	rm -rf *.o pruebamorpho