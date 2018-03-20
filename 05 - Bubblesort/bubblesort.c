#include "bubblesort.h"
#include <stdio.h>

void imprimevetor(int* vetor, int n){
	int i;
	printf("\n");
	for(i = 0 ; i < n ; i++){
		printf("%d ",vetor[i]);
	}
	printf("\n");
}

void bubblesort(int* vetor, int n){
	int i=0;
	int aux=0;
	do{
		for(i = 0 ; i < n-1 ; i++){
			if(vetor[i]>vetor[i+1]){
				printf("\n%d maior que %d\n",vetor[i],vetor[i+1]);
				aux = vetor[i];
				vetor[i] = vetor[i+1];
				vetor[i+1] = aux;
			}
		}
		n--;
	}while(n!=0);
}