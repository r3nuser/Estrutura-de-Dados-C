main:	main.o	allsorts.o
	gcc main.o allsorts.o -o main

main.o:	main.c
	gcc -c main.c

allsorts.o:	allsorts.c	allsorts.h
	gcc -c allsorts.c

clean:
	rm *.o