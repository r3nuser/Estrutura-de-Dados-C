main:	main.o	selectionsort.o
	gcc main.o selectionsort.o -o main

main.o:	main.c
	gcc -c main.c

selectionsort.o:	selectionsort.c	selectionsort.h
	gcc -c selectionsort.c

clean:
	rm *.o
