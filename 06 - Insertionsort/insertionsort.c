#include <stdio.h>
#include <stdlib.h>
#include "insertionsort.h"

void insertionsort(int *vetor, int size){
	int i=0;
	int j=0;
	int aux=0;
	for(i = 1 ; i < size ; i++){
		aux = vetor[i];
		for(j = i ; j > 0 && aux < vetor[j-1] ; j--)
			vetor[j] = vetor[j-1];
		printf("\nJ: %d\n",j);
		vetor[j] = aux;
	}
}

void swap(int *n1, int *n2){
	int aux;
	aux = *n1;
	*n1 = *n2;
	*n2 = aux;
}

void printvetor(int *vetor, int size){
	int i = 0;
	printf("\n");
	for(i = 0 ; i < size ; i++){
		printf("%d ",vetor[i]);
	}
	printf("\n");
}
