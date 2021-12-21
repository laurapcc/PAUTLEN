CC=gcc
CFLAGS=
SYMBOLS_DIR=symbols_table
SYNTACTIC_DIR=syntactic
ERROR_DIR=errors
CODE_GENERATION_DIR=code_generation

%.c: %.y
%.c: %.l

all: alfa

alfa: y.tab.o lex.yy.o symbols_table.o generacion.o alfa.o
	$(CC) $(CFLAGS) $^ -o $@

alfa.o: alfa.c
	$(CC) $(CFLAGS) -c $^

lex.yy.o: lex.yy.c
	$(CC) $(CFLAGS) -c $^

y.tab.o: y.tab.c
	$(CC) $(CFLAGS) -c $<

lex.yy.c: alfa.l y.tab.h
	flex $<

y.tab.c: alfa.y
	bison -d -y -v --report=all $^

y.tab.h: alfa.y
	bison -d -y -v --report=all $^

symbols_table.o: $(SYMBOLS_DIR)/symbols_table.c
	$(CC) $(CFLAGS) -c $^

generacion.o: $(CODE_GENERATION_DIR)/generacion.c
	$(CC) $(CFLAGS) -c $^



funciones:
	./alfa $(SYNTACTIC_DIR)/funciones.alfa $(SYNTACTIC_DIR)/funciones.asm
	nasm -g -o $(SYNTACTIC_DIR)/funciones.o -f elf32 $(SYNTACTIC_DIR)/funciones.asm
	gcc -Wall -g -m32 -o $(SYNTACTIC_DIR)/funciones $(SYNTACTIC_DIR)/funciones.o $(SYNTACTIC_DIR)/alfalib.o
	./$(SYNTACTIC_DIR)/funciones

condicionales:
	./alfa $(SYNTACTIC_DIR)/condicionales.alfa $(SYNTACTIC_DIR)/condicionales.asm
	nasm -g -o $(SYNTACTIC_DIR)/condicionales.o -f elf32 $(SYNTACTIC_DIR)/condicionales.asm
	gcc -Wall -g -m32 -o $(SYNTACTIC_DIR)/condicionales $(SYNTACTIC_DIR)/condicionales.o $(SYNTACTIC_DIR)/alfalib.o
	./$(SYNTACTIC_DIR)/condicionales

fibonacci:
	./alfa $(SYNTACTIC_DIR)/fibonacci.alfa $(SYNTACTIC_DIR)/fibonacci.asm
	nasm -g -o $(SYNTACTIC_DIR)/fibonacci.o -f elf32 $(SYNTACTIC_DIR)/fibonacci.asm
	gcc -Wall -g -m32 -o $(SYNTACTIC_DIR)/fibonacci $(SYNTACTIC_DIR)/fibonacci.o $(SYNTACTIC_DIR)/alfalib.o
	./$(SYNTACTIC_DIR)/fibonacci

factorial:
	./alfa $(SYNTACTIC_DIR)/factorial.alfa $(SYNTACTIC_DIR)/factorial.asm
	nasm -g -o $(SYNTACTIC_DIR)/factorial.o -f elf32 $(SYNTACTIC_DIR)/factorial.asm
	gcc -Wall -g -m32 -o $(SYNTACTIC_DIR)/factorial $(SYNTACTIC_DIR)/factorial.o $(SYNTACTIC_DIR)/alfalib.o
	./$(SYNTACTIC_DIR)/factorial

funciones_vectores:
	./alfa $(SYNTACTIC_DIR)/funciones_vectores.alfa $(SYNTACTIC_DIR)/funciones_vectores.asm
	nasm -g -o $(SYNTACTIC_DIR)/funciones_vectores.o -f elf32 $(SYNTACTIC_DIR)/funciones_vectores.asm
	gcc -Wall -g -m32 -o $(SYNTACTIC_DIR)/funciones_vectores $(SYNTACTIC_DIR)/funciones_vectores.o $(SYNTACTIC_DIR)/alfalib.o
	./$(SYNTACTIC_DIR)/funciones_vectores

guion:
	./alfa $(SYNTACTIC_DIR)/guion.c $(SYNTACTIC_DIR)/guion.asm
	nasm -g -o $(SYNTACTIC_DIR)/guion.o -f elf32 $(SYNTACTIC_DIR)/guion.asm
	gcc -Wall -g -m32 -o $(SYNTACTIC_DIR)/guion $(SYNTACTIC_DIR)/guion.o $(SYNTACTIC_DIR)/alfalib.o
	./$(SYNTACTIC_DIR)/guion

arithmetic:
	./alfa $(SYNTACTIC_DIR)/arithmetic.alfa $(SYNTACTIC_DIR)/arithmetic.asm
	nasm -g -o $(SYNTACTIC_DIR)/arithmetic.o -f elf32 $(SYNTACTIC_DIR)/arithmetic.asm
	gcc -Wall -g -m32 -o $(SYNTACTIC_DIR)/arithmetic $(SYNTACTIC_DIR)/arithmetic.o $(SYNTACTIC_DIR)/alfalib.o
	./$(SYNTACTIC_DIR)/arithmetic	

logic:
	./alfa $(SYNTACTIC_DIR)/logic.alfa $(SYNTACTIC_DIR)/logic.asm
	nasm -g -o $(SYNTACTIC_DIR)/logic.o -f elf32 $(SYNTACTIC_DIR)/logic.asm
	gcc -Wall -g -m32 -o $(SYNTACTIC_DIR)/logic $(SYNTACTIC_DIR)/logic.o $(SYNTACTIC_DIR)/alfalib.o
	./$(SYNTACTIC_DIR)/logic	



ex1:
	./alfa $(SYNTACTIC_DIR)/ex1.alfa $(SYNTACTIC_DIR)/ex1.asm
	nasm -g -o $(SYNTACTIC_DIR)/ex1.o -f elf32 $(SYNTACTIC_DIR)/ex1.asm
	gcc -Wall -g -m32 -o $(SYNTACTIC_DIR)/ex1 $(SYNTACTIC_DIR)/ex1.o $(SYNTACTIC_DIR)/alfalib.o
	./$(SYNTACTIC_DIR)/ex1

ex2:
	./alfa $(SYNTACTIC_DIR)/ex2.alfa $(SYNTACTIC_DIR)/ex2.asm
	nasm -g -o $(SYNTACTIC_DIR)/ex2.o -f elf32 $(SYNTACTIC_DIR)/ex2.asm
	gcc -Wall -g -m32 -o $(SYNTACTIC_DIR)/ex2 $(SYNTACTIC_DIR)/ex2.o $(SYNTACTIC_DIR)/alfalib.o
	./$(SYNTACTIC_DIR)/ex2

ex3:
	./alfa $(SYNTACTIC_DIR)/ex3.alfa $(SYNTACTIC_DIR)/ex3.asm
	nasm -g -o $(SYNTACTIC_DIR)/ex3.o -f elf32 $(SYNTACTIC_DIR)/ex3.asm
	gcc -Wall -g -m32 -o $(SYNTACTIC_DIR)/ex3 $(SYNTACTIC_DIR)/ex3.o $(SYNTACTIC_DIR)/alfalib.o
	./$(SYNTACTIC_DIR)/ex3

ex4:
	./alfa $(SYNTACTIC_DIR)/ex4.alfa $(SYNTACTIC_DIR)/ex4.asm
	nasm -g -o $(SYNTACTIC_DIR)/ex4.o -f elf32 $(SYNTACTIC_DIR)/ex4.asm
	gcc -Wall -g -m32 -o $(SYNTACTIC_DIR)/ex4 $(SYNTACTIC_DIR)/ex4.o $(SYNTACTIC_DIR)/alfalib.o
	./$(SYNTACTIC_DIR)/ex4

ex5:
	./alfa $(SYNTACTIC_DIR)/ex5.alfa $(SYNTACTIC_DIR)/ex5.asm
	nasm -g -o $(SYNTACTIC_DIR)/ex5.o -f elf32 $(SYNTACTIC_DIR)/ex5.asm
	gcc -Wall -g -m32 -o $(SYNTACTIC_DIR)/ex5 $(SYNTACTIC_DIR)/ex5.o $(SYNTACTIC_DIR)/alfalib.o
	./$(SYNTACTIC_DIR)/ex5

ex6:
	./alfa $(SYNTACTIC_DIR)/ex6.alfa $(SYNTACTIC_DIR)/ex6.asm
	nasm -g -o $(SYNTACTIC_DIR)/ex6.o -f elf32 $(SYNTACTIC_DIR)/ex6.asm
	gcc -Wall -g -m32 -o $(SYNTACTIC_DIR)/ex6 $(SYNTACTIC_DIR)/ex6.o $(SYNTACTIC_DIR)/alfalib.o
	./$(SYNTACTIC_DIR)/ex6

ex7:
	./alfa $(SYNTACTIC_DIR)/ex7.alfa $(SYNTACTIC_DIR)/ex7.asm
	nasm -g -o $(SYNTACTIC_DIR)/ex7.o -f elf32 $(SYNTACTIC_DIR)/ex7.asm
	gcc -Wall -g -m32 -o $(SYNTACTIC_DIR)/ex7 $(SYNTACTIC_DIR)/ex7.o $(SYNTACTIC_DIR)/alfalib.o
	./$(SYNTACTIC_DIR)/ex7

ex9:
	./alfa $(SYNTACTIC_DIR)/ex9.alfa $(SYNTACTIC_DIR)/ex9.asm
	nasm -g -o $(SYNTACTIC_DIR)/ex9.o -f elf32 $(SYNTACTIC_DIR)/ex9.asm
	gcc -Wall -g -m32 -o $(SYNTACTIC_DIR)/ex9 $(SYNTACTIC_DIR)/ex9.o $(SYNTACTIC_DIR)/alfalib.o
	./$(SYNTACTIC_DIR)/ex9

ex10:
	./alfa $(SYNTACTIC_DIR)/ex10.alfa $(SYNTACTIC_DIR)/ex10.asm
	nasm -g -o $(SYNTACTIC_DIR)/ex10.o -f elf32 $(SYNTACTIC_DIR)/ex10.asm
	gcc -Wall -g -m32 -o $(SYNTACTIC_DIR)/ex10 $(SYNTACTIC_DIR)/ex10.o $(SYNTACTIC_DIR)/alfalib.o
	./$(SYNTACTIC_DIR)/ex10

ex11:
	./alfa $(SYNTACTIC_DIR)/ex11.alfa $(SYNTACTIC_DIR)/ex11.asm
	nasm -g -o $(SYNTACTIC_DIR)/ex11.o -f elf32 $(SYNTACTIC_DIR)/ex11.asm
	gcc -Wall -g -m32 -o $(SYNTACTIC_DIR)/ex11 $(SYNTACTIC_DIR)/ex11.o $(SYNTACTIC_DIR)/alfalib.o
	./$(SYNTACTIC_DIR)/ex11

semantic_error1:
	./alfa $(ERROR_DIR)/semantic_error1.alfa $(ERROR_DIR)/semantic_error1.asm
	nasm -g -o $(ERROR_DIR)/semantic_error1.o -f elf32 $(ERROR_DIR)/semantic_error1.asm
	gcc -Wall -g -m32 -o $(ERROR_DIR)/semantic_error1 $(ERROR_DIR)/semantic_error1.o $(SYNTACTIC_DIR)/alfalib.o
	./$(ERROR_DIR)/semantic_error1		

semantic_error2:
	./alfa $(ERROR_DIR)/semantic_error2.alfa $(ERROR_DIR)/semantic_error2.asm
	nasm -g -o $(ERROR_DIR)/semantic_error2.o -f elf32 $(ERROR_DIR)/semantic_error2.asm
	gcc -Wall -g -m32 -o $(ERROR_DIR)/semantic_error2 $(ERROR_DIR)/semantic_error2.o $(SYNTACTIC_DIR)/alfalib.o
	./$(ERROR_DIR)/semantic_error2		

semantic_error3:
	./alfa $(ERROR_DIR)/semantic_error3.alfa $(ERROR_DIR)/semantic_error3.asm
	nasm -g -o $(ERROR_DIR)/semantic_error3.o -f elf32 $(ERROR_DIR)/semantic_error3.asm
	gcc -Wall -g -m32 -o $(ERROR_DIR)/semantic_error3 $(ERROR_DIR)/semantic_error3.o $(SYNTACTIC_DIR)/alfalib.o
	./$(ERROR_DIR)/semantic_error3	

semantic_error4:
	./alfa $(ERROR_DIR)/semantic_error4.alfa $(ERROR_DIR)/semantic_error4.asm
	nasm -g -o $(ERROR_DIR)/semantic_error4.o -f elf32 $(ERROR_DIR)/semantic_error4.asm
	gcc -Wall -g -m32 -o $(ERROR_DIR)/semantic_error4 $(ERROR_DIR)/semantic_error4.o $(SYNTACTIC_DIR)/alfalib.o
	./$(ERROR_DIR)/semantic_error4			

semantic_error5:
	./alfa $(ERROR_DIR)/semantic_error5.alfa $(ERROR_DIR)/semantic_error5.asm
	nasm -g -o $(ERROR_DIR)/semantic_error5.o -f elf32 $(ERROR_DIR)/semantic_error5.asm
	gcc -Wall -g -m32 -o $(ERROR_DIR)/semantic_error5 $(ERROR_DIR)/semantic_error5.o $(SYNTACTIC_DIR)/alfalib.o
	./$(ERROR_DIR)/semantic_error5

semantic_error6:
	./alfa $(ERROR_DIR)/semantic_error6.alfa $(ERROR_DIR)/semantic_error6.asm
	nasm -g -o $(ERROR_DIR)/semantic_error6.o -f elf32 $(ERROR_DIR)/semantic_error6.asm
	gcc -Wall -g -m32 -o $(ERROR_DIR)/semantic_error6 $(ERROR_DIR)/semantic_error6.o $(SYNTACTIC_DIR)/alfalib.o
	./$(ERROR_DIR)/semantic_error6

semantic_error7:
	./alfa $(ERROR_DIR)/semantic_error7.alfa $(ERROR_DIR)/semantic_error7.asm
	nasm -g -o $(ERROR_DIR)/semantic_error7.o -f elf32 $(ERROR_DIR)/semantic_error7.asm
	gcc -Wall -g -m32 -o $(ERROR_DIR)/semantic_error7 $(ERROR_DIR)/semantic_error7.o $(SYNTACTIC_DIR)/alfalib.o
	./$(ERROR_DIR)/semantic_error7	
 
semantic_error8:
	./alfa $(ERROR_DIR)/semantic_error8.alfa $(ERROR_DIR)/semantic_error8.asm
	nasm -g -o $(ERROR_DIR)/semantic_error8.o -f elf32 $(ERROR_DIR)/semantic_error8.asm
	gcc -Wall -g -m32 -o $(ERROR_DIR)/semantic_error8 $(ERROR_DIR)/semantic_error8.o $(SYNTACTIC_DIR)/alfalib.o
	./$(ERROR_DIR)/semantic_error8

semantic_error9:
	./alfa $(ERROR_DIR)/semantic_error9.alfa $(ERROR_DIR)/semantic_error9.asm
	nasm -g -o $(ERROR_DIR)/semantic_error9.o -f elf32 $(ERROR_DIR)/semantic_error9.asm
	gcc -Wall -g -m32 -o $(ERROR_DIR)/semantic_error9 $(ERROR_DIR)/semantic_error9.o $(SYNTACTIC_DIR)/alfalib.o
	./$(ERROR_DIR)/semantic_error9

semantic_error10:
	./alfa $(ERROR_DIR)/semantic_error10.alfa $(ERROR_DIR)/semantic_error10.asm
	nasm -g -o $(ERROR_DIR)/semantic_error10.o -f elf32 $(ERROR_DIR)/semantic_error10.asm
	gcc -Wall -g -m32 -o $(ERROR_DIR)/semantic_error10 $(ERROR_DIR)/semantic_error10.o $(SYNTACTIC_DIR)/alfalib.o
	./$(ERROR_DIR)/semantic_error10

semantic_error11:
	./alfa $(ERROR_DIR)/semantic_error11.alfa $(ERROR_DIR)/semantic_error11.asm
	nasm -g -o $(ERROR_DIR)/semantic_error11.o -f elf32 $(ERROR_DIR)/semantic_error11.asm
	gcc -Wall -g -m32 -o $(ERROR_DIR)/semantic_error11 $(ERROR_DIR)/semantic_error11.o $(SYNTACTIC_DIR)/alfalib.o
	./$(ERROR_DIR)/semantic_error11	

semantic_error12:
	./alfa $(ERROR_DIR)/semantic_error12.alfa $(ERROR_DIR)/semantic_error12.asm
	nasm -g -o $(ERROR_DIR)/semantic_error12.o -f elf32 $(ERROR_DIR)/semantic_error12.asm
	gcc -Wall -g -m32 -o $(ERROR_DIR)/semantic_error12 $(ERROR_DIR)/semantic_error12.o $(SYNTACTIC_DIR)/alfalib.o
	./$(ERROR_DIR)/semantic_error12	

semantic_error13:
	./alfa $(ERROR_DIR)/semantic_error13.alfa $(ERROR_DIR)/semantic_error13.asm
	nasm -g -o $(ERROR_DIR)/semantic_error13.o -f elf32 $(ERROR_DIR)/semantic_error13.asm
	gcc -Wall -g -m32 -o $(ERROR_DIR)/semantic_error13 $(ERROR_DIR)/semantic_error13.o $(SYNTACTIC_DIR)/alfalib.o
	./$(ERROR_DIR)/semantic_error13	

semantic_error14:
	./alfa $(ERROR_DIR)/semantic_error14.alfa $(ERROR_DIR)/semantic_error14.asm
	nasm -g -o $(ERROR_DIR)/semantic_error14.o -f elf32 $(ERROR_DIR)/semantic_error14.asm
	gcc -Wall -g -m32 -o $(ERROR_DIR)/semantic_error14 $(ERROR_DIR)/semantic_error14.o $(SYNTACTIC_DIR)/alfalib.o
	./$(ERROR_DIR)/semantic_error14			

semantic_error15:
	./alfa $(ERROR_DIR)/semantic_error15.alfa $(ERROR_DIR)/semantic_error15.asm
	nasm -g -o $(ERROR_DIR)/semantic_error15.o -f elf32 $(ERROR_DIR)/semantic_error15.asm
	gcc -Wall -g -m32 -o $(ERROR_DIR)/semantic_error15 $(ERROR_DIR)/semantic_error15.o $(SYNTACTIC_DIR)/alfalib.o
	./$(ERROR_DIR)/semantic_error15		

semantic_error16:
	./alfa $(ERROR_DIR)/semantic_error16.alfa $(ERROR_DIR)/semantic_error16.asm
	nasm -g -o $(ERROR_DIR)/semantic_error16.o -f elf32 $(ERROR_DIR)/semantic_error16.asm
	gcc -Wall -g -m32 -o $(ERROR_DIR)/semantic_error16 $(ERROR_DIR)/semantic_error16.o $(SYNTACTIC_DIR)/alfalib.o
	./$(ERROR_DIR)/semantic_error16		

runtime_error_div_by_0:
	./alfa $(ERROR_DIR)/runtime_error_div_by_0.alfa $(ERROR_DIR)/runtime_error_div_by_0.asm
	nasm -g -o $(ERROR_DIR)/runtime_error_div_by_0.o -f elf32 $(ERROR_DIR)/runtime_error_div_by_0.asm
	gcc -Wall -g -m32 -o $(ERROR_DIR)/runtime_error_div_by_0 $(ERROR_DIR)/runtime_error_div_by_0.o $(SYNTACTIC_DIR)/alfalib.o
	./$(ERROR_DIR)/runtime_error_div_by_0	

runtime_error_out_of_index_vector:
	./alfa $(ERROR_DIR)/runtime_error_out_of_index_vector.alfa $(ERROR_DIR)/runtime_error_out_of_index_vector.asm
	nasm -g -o $(ERROR_DIR)/runtime_error_out_of_index_vector.o -f elf32 $(ERROR_DIR)/runtime_error_out_of_index_vector.asm
	gcc -Wall -g -m32 -o $(ERROR_DIR)/runtime_error_out_of_index_vector $(ERROR_DIR)/runtime_error_out_of_index_vector.o $(SYNTACTIC_DIR)/alfalib.o
	./$(ERROR_DIR)/runtime_error_out_of_index_vector					

clean: 
	rm -rf *.o 
	rm -rf alfa *.gch 
	rm -rf output_sin_1.txt output_sin_2.txt output_sin_3.txt output_sin_4.txt output_sin_5.txt
	rm -rf y.output y.tab.c y.tab.h lex.yy.c

clean_output: 
	rm -rf $(SYMBOLS_DIR)/mi_salida.txt $(CODE_GENERATION_DIR)/ex1.asm
	rm -rf $(SYNTACTIC_DIR)/condicionales.asm $(SYNTACTIC_DIR)/condicionales.asm $(SYNTACTIC_DIR)/condicionales $(SYNTACTIC_DIR)/condicionales.o
	rm -rf $(SYNTACTIC_DIR)/funciones.asm $(SYNTACTIC_DIR)/funciones.asm $(SYNTACTIC_DIR)/funciones $(SYNTACTIC_DIR)/funciones.o
	rm -rf $(SYNTACTIC_DIR)/fibonacci.asm $(SYNTACTIC_DIR)/fibonacci.asm $(SYNTACTIC_DIR)/fibonacci $(SYNTACTIC_DIR)/fibonacci.o
	rm -rf $(SYNTACTIC_DIR)/factorial.asm $(SYNTACTIC_DIR)/factorial.asm $(SYNTACTIC_DIR)/factorial $(SYNTACTIC_DIR)/factorial.o
	rm -rf $(SYNTACTIC_DIR)/funciones_vectores.asm $(SYNTACTIC_DIR)/funciones_vectores.asm $(SYNTACTIC_DIR)/funciones_vectores $(SYNTACTIC_DIR)/funciones_vectores.o
	rm -rf $(SYNTACTIC_DIR)/guion.asm $(SYNTACTIC_DIR)/guion.asm $(SYNTACTIC_DIR)/guion $(SYNTACTIC_DIR)/guion.o
	rm -rf $(SYNTACTIC_DIR)/ex1.asm $(SYNTACTIC_DIR)/ex1.asm $(SYNTACTIC_DIR)/ex1 $(SYNTACTIC_DIR)/ex1.o
	rm -rf $(SYNTACTIC_DIR)/ex2.asm $(SYNTACTIC_DIR)/ex2.asm $(SYNTACTIC_DIR)/ex2 $(SYNTACTIC_DIR)/ex2.o
	rm -rf $(SYNTACTIC_DIR)/ex3.asm $(SYNTACTIC_DIR)/ex3.asm $(SYNTACTIC_DIR)/ex3 $(SYNTACTIC_DIR)/ex3.o
	rm -rf $(SYNTACTIC_DIR)/ex4.asm $(SYNTACTIC_DIR)/ex4.asm $(SYNTACTIC_DIR)/ex4 $(SYNTACTIC_DIR)/ex4.o
	rm -rf $(SYNTACTIC_DIR)/ex5.asm $(SYNTACTIC_DIR)/ex5.asm $(SYNTACTIC_DIR)/ex5 $(SYNTACTIC_DIR)/ex5.o
	rm -rf $(SYNTACTIC_DIR)/ex6.asm $(SYNTACTIC_DIR)/ex6.asm $(SYNTACTIC_DIR)/ex6 $(SYNTACTIC_DIR)/ex6.o
	rm -rf $(SYNTACTIC_DIR)/ex7.asm $(SYNTACTIC_DIR)/ex7.asm $(SYNTACTIC_DIR)/ex7 $(SYNTACTIC_DIR)/ex7.o
	rm -rf $(SYNTACTIC_DIR)/ex9.asm $(SYNTACTIC_DIR)/ex9.asm $(SYNTACTIC_DIR)/ex9 $(SYNTACTIC_DIR)/ex9.o
	rm -rf $(SYNTACTIC_DIR)/ex10.asm $(SYNTACTIC_DIR)/ex10.asm $(SYNTACTIC_DIR)/ex10 $(SYNTACTIC_DIR)/ex10.o
	rm -rf $(SYNTACTIC_DIR)/ex11.asm $(SYNTACTIC_DIR)/ex11.asm $(SYNTACTIC_DIR)/ex11 $(SYNTACTIC_DIR)/ex11.o
	rm -rf $(SYNTACTIC_DIR)/arithmetic.asm $(SYNTACTIC_DIR)/arithmetic.asm $(SYNTACTIC_DIR)/arithmetic $(SYNTACTIC_DIR)/arithmetic.o
	rm -rf $(SYNTACTIC_DIR)/logic.asm $(SYNTACTIC_DIR)/logic.asm $(SYNTACTIC_DIR)/logic $(SYNTACTIC_DIR)/logic.o
	rm -rf $(ERROR_DIR)/semantic_error1.asm $(ERROR_DIR)/semantic_error1.asm $(ERROR_DIR)/semantic_error1 $(ERROR_DIR)/semantic_error1.o
	rm -rf $(ERROR_DIR)/semantic_error2.asm $(ERROR_DIR)/semantic_error2.asm $(ERROR_DIR)/semantic_error2 $(ERROR_DIR)/semantic_error2.o
	rm -rf $(ERROR_DIR)/semantic_error3.asm $(ERROR_DIR)/semantic_error3.asm $(ERROR_DIR)/semantic_error3 $(ERROR_DIR)/semantic_error3.o
	rm -rf $(ERROR_DIR)/semantic_error4.asm $(ERROR_DIR)/semantic_error4.asm $(ERROR_DIR)/semantic_error4 $(ERROR_DIR)/semantic_error4.o
	rm -rf $(ERROR_DIR)/semantic_error5.asm $(ERROR_DIR)/semantic_error5.asm $(ERROR_DIR)/semantic_error5 $(ERROR_DIR)/semantic_error5.o
	rm -rf $(ERROR_DIR)/semantic_error6.asm $(ERROR_DIR)/semantic_error6.asm $(ERROR_DIR)/semantic_error6 $(ERROR_DIR)/semantic_error6.o
	rm -rf $(ERROR_DIR)/semantic_error7.asm $(ERROR_DIR)/semantic_error7.asm $(ERROR_DIR)/semantic_error7 $(ERROR_DIR)/semantic_error7.o
	rm -rf $(ERROR_DIR)/semantic_error8.asm $(ERROR_DIR)/semantic_error8.asm $(ERROR_DIR)/semantic_error8 $(ERROR_DIR)/semantic_error8.o
	rm -rf $(ERROR_DIR)/semantic_error9.asm $(ERROR_DIR)/semantic_error9.asm $(ERROR_DIR)/semantic_error9 $(ERROR_DIR)/semantic_error9.o
	rm -rf $(ERROR_DIR)/semantic_error10.asm $(ERROR_DIR)/semantic_error10.asm $(ERROR_DIR)/semantic_error10 $(ERROR_DIR)/semantic_error10.o
	rm -rf $(ERROR_DIR)/semantic_error11.asm $(ERROR_DIR)/semantic_error11.asm $(ERROR_DIR)/semantic_error11 $(ERROR_DIR)/semantic_error11.o
	rm -rf $(ERROR_DIR)/semantic_error12.asm $(ERROR_DIR)/semantic_error12.asm $(ERROR_DIR)/semantic_error12 $(ERROR_DIR)/semantic_error12.o
	rm -rf $(ERROR_DIR)/semantic_error13.asm $(ERROR_DIR)/semantic_error13.asm $(ERROR_DIR)/semantic_error13 $(ERROR_DIR)/semantic_error13.o
	rm -rf $(ERROR_DIR)/semantic_error14.asm $(ERROR_DIR)/semantic_error14.asm $(ERROR_DIR)/semantic_error14 $(ERROR_DIR)/semantic_error14.o
	rm -rf $(ERROR_DIR)/semantic_error15.asm $(ERROR_DIR)/semantic_error15.asm $(ERROR_DIR)/semantic_error15 $(ERROR_DIR)/semantic_error15.o
	rm -rf $(ERROR_DIR)/semantic_error16.asm $(ERROR_DIR)/semantic_error16.asm $(ERROR_DIR)/semantic_error16 $(ERROR_DIR)/semantic_error16.o
	rm -rf $(ERROR_DIR)/runtime_error_div_by_0.asm $(ERROR_DIR)/runtime_error_div_by_0.asm $(ERROR_DIR)/runtime_error_div_by_0 $(ERROR_DIR)/runtime_error_div_by_0.o
	rm -rf $(ERROR_DIR)/runtime_error_out_of_index_vector.asm $(ERROR_DIR)/runtime_error_out_of_index_vector.asm $(ERROR_DIR)/runtime_error_out_of_index_vector $(ERROR_DIR)/runtime_error_out_of_index_vector.o
	

clean_all: clean clean_output