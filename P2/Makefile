prueba:
	flex alfa.l
	gcc -c -o lex.yy.o lex.yy.c
	gcc -Wall -ansi -pedantic -c -o pruebamorpho.o pruebamorpho.c
	gcc -o pruebamorpho lex.yy.o pruebamorpho.o

test1:
	./pruebamorpho entrada1.txt output1.txt

test2:
	./pruebamorpho entrada2.txt output2.txt

compare1:
	diff -b output1.txt salida1.txt

compare2:
	diff -b output2.txt salida2.txt

clean: 
	rm -rf *.o pruebamorpho
	rm -rf output1.txt output2.txt