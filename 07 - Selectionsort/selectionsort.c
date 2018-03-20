#include <stdio.h>
#include <stdlib.h>
#include "selectionsort.h"

void selectionsort(int *vetor, int size){
	int i=0;
	int j=0;
	int minIndex=0;
	int aux = 0;

	for(i = 0 ; i < size ; i++){
		minIndex = i;
		for(j = i+1 ; j < size ; j++)
			if(vetor[j-1]>vetor[j])
				minIndex=j;
		if(minIndex!=i){
			swapNumbers(&vetor[i],&vetor[minIndex]);
		}
	}

}

void printvetor(int *vetor, int size){
	int i;
	printf("\n");
	for(i = 0 ; i < size ; i++){
		printf("%d ",vetor[i]);
	}
	printf("\n");
}

void swapNumbers(int *n1, int *n2){
	int aux = 0;
	aux = *n1;
	*n1 = *n2;
	*n2 = aux;
}