main:	main.o	listaduplamenteencadeada.o
	gcc main.o listaduplamenteencadeada.o -o main

main.o:	main.c
	gcc -c main.c

listaduplamenteencadeada.o:	listaduplamenteencadeada.c	listaduplamenteencadeada.h
	gcc -c listaduplamenteencadeada.c

clean:
	rm *.o
