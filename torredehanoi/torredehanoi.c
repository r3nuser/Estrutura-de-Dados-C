#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include "torredehanoi.h"

//HANOI ALGORITHM
void hanoi(int n, char origem, char auxiliar, char destino){
	if(n>0){
		printf("\nprimeira recursao\n");
		hanoi(n-1,origem,destino,auxiliar);
		printf("Mova o disco %d de %c para %c\n", n, origem, destino);
		printf("\nsegunda recursao\n");
		hanoi(n-1,auxiliar,origem,destino);
	}
}


