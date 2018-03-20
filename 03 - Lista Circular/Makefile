main:	main.o	listacircular.o
	gcc main.o listacircular.o -o main

main.o:	main.c
	gcc -c main.c

listacircular.o:	listacircular.c	listacircular.h
	gcc -c listacircular.c

clean:
	rm *.o
