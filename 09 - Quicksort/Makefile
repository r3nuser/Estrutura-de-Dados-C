main:	main.o	insertionsort.o
	gcc main.o insertionsort.o -o main

main.o:	main.c
	gcc -c main.c

insertionsort.o:	insertionsort.c	insertionsort.h
	gcc -c insertionsort.c

clean:
	rm *.o
