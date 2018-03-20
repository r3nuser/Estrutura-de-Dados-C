#include <stdlib.h>
#include <stdio.h>
#include "torredehanoi.h"

int main(void){
	// VARIABLES FOR CIRCLES NUMBER AND 3 TOWER
	int n=0;

	

	printf("Insert a circles number for Hanoi Tower:\n");
	scanf("%d",&n);
	printf("\n");

	hanoi(n,'a','b','c');

	
	return 0;
}

