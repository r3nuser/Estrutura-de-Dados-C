main:	main.o	buscabinaria.o
	gcc main.o buscabinaria.o -o main

main.o:	main.c
	gcc -c main.c

buscabinaria.o:	buscabinaria.c	buscabinaria.h
	gcc -c buscabinaria.c

clean:
	rm *.o
