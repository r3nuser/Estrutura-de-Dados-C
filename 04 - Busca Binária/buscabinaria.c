#include <stdio.h>
#include "buscabinaria.h"

void preencheVetor(int num[], int n){
	int i;
	printf("\nPreenchendo...\n");
	for(i = 0 ; i < n ; i++){
		num[i]=i+1;
	}
	printf("\nPreenchido !\n");
}
void printaVetor(int num[], int n){
	int i;
	printf("\nPrintando...\n");
	for(i = 0 ; i < n ; i++){
		printf("\n%d",num[i]);
	}
	printf("\n\nPrintado !\n");
}
int buscaBinaria(int num[], int n, int elem){
	int inicio=0;
	int final=n-1;
	int meio;
	while(inicio<=final){
		meio=(inicio+final)/2;
		printf("\nBuscando ...\n");
		printf(" Inicio: %d", inicio);
		printf(" Meio: %d", meio);
		printf(" Final: %d\n", final);
		if(num[meio]==elem)
			return meio;
		else if(elem<num[meio])
			final=meio-1;
		else if(elem>num[meio])
			inicio=meio+1;
	}
	return -1;
}