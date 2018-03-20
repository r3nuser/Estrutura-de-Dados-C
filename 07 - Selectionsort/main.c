#include <stdio.h>
#include "selectionsort.h"

int main(){
	int size = 10;
	int vetor[size];

	vetor[0] = 10;
	vetor[1] = 9;
	vetor[2] = 8;
	vetor[3] = 7;
	vetor[4] = 6;
	vetor[5] = 5;
	vetor[6] = 4;
	vetor[7] = 3;
	vetor[8] = 2;
	vetor[9] = 1;

	printvetor(vetor,size);
	selectionsort(vetor,size);
	printvetor(vetor,size);

	return 0;
}