#include <stdio.h>
#include <stdlib.h>
#include "insertionsort.h"

int main(void){
	int size = 20;
	int vetor[size];
	vetor[0]=18;
	vetor[1]=19;
	vetor[2]=17;
	vetor[3]=16;
	vetor[4]=15;
	vetor[5]=14;
	vetor[6]=13;
	vetor[7]=12;
	vetor[8]=11;
	vetor[9]=10;
	vetor[10]=9;
	vetor[11]=8;
	vetor[12]=7;
	vetor[13]=6;
	vetor[14]=5;
	vetor[15]=4;
	vetor[16]=3;
	vetor[17]=2;
	vetor[18]=1;
	vetor[19]=0;

	printvetor(vetor,size);
	insertionsort(vetor,size);
	printvetor(vetor,size);

	return 0;
}