#include <stdio.h>
#include <stdlib.h>
#include "buscabinaria.h"

int main(){
	int tam=550;
	int num[tam];
	preencheVetor(num,tam);	
	printaVetor(num,tam);

	printf("\n\n%d\n\n", buscaBinaria(num,tam,551));

	return 0;
}