tensor: main.o biblioteca.o
	gcc -fopenmp main.o biblioteca.o -o tensor -lm -lrt

main.o: source/main.c
	gcc -c source/main.c

biblioteca.o: source/biblioteca.c source/biblioteca.h
	gcc -c source/biblioteca.c

clean: 
	rm *.o tensor