prueba:
	flex alfa.l
	gcc -c -o lex.yy.o lex.yy.c
	gcc -Wall -ansi -pedantic -c -o pruebaMorpho.o pruebaMorpho.c
	gcc -o pruebaMorpho lex.yy.o pruebaMorpho.o

test1:
	./pruebaMorpho entrada1.txt output1.txt

test2:
	./pruebaMorpho entrada2.txt output2.txt

compare1:
	diff -Bb output1.txt salida1.txt

compare2:
	diff -Bb output2.txt salida2.txt

clean: 
	rm -rf *.o pruebaMorpho
	rm -rf output1.txt output2.txt
	rm -rf lex.yy.o lex.yy.c