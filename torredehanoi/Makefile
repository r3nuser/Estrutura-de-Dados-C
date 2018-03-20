main:	main.o	torredehanoi.o
	gcc main.o torredehanoi.o -o main

main.o:	main.c
	gcc -c main.c

listaencadeada.o:	torredehanoi.c	torredehanoi.h
	gcc -c torredehanoi.c

clean:
	rm *.o
