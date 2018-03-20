main:	main.o	bubblesort.o
	gcc main.o bubblesort.o -o main

main.o:	main.c
	gcc -c main.c

bubblesort.o:	bubblesort.c	bubblesort.h
	gcc -c bubblesort.c

clean:
	rm *.o
