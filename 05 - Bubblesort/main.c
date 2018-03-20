#include <stdio.h>
#include <stdlib.h>
#include "bubblesort.h"

int main(){
	int n = 10;
	int vetor[n];

	vetor[0]=1;
	vetor[1]=5;
	vetor[2]=2;
	vetor[3]=3;
	vetor[4]=10;
	vetor[5]=7;
	vetor[6]=6;
	vetor[7]=9;
	vetor[8]=8;
	vetor[9]=4;

	imprimevetor(vetor,n);
	bubblesort(vetor,n);
	imprimevetor(vetor,n);

	return 0;
}