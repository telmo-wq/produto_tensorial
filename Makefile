tensor_tmfc.out: main.o biblioteca.o
	gcc main.o biblioteca.o -o tensor_tmfc.out -lm

main.o: source/main.c
	gcc -c source/main.c

biblioteca.o: source/biblioteca.c source/biblioteca.h
	gcc -c source/biblioteca.c

clean: 
	rm *.o tensor_tmfc.out