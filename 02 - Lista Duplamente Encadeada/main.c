#include <stdio.h>
#include "listaduplamenteencadeada.h"
#include <stdlib.h>



int main(void){
	List* list = createList();
	DataNode data;
	int i;
	for(i = 0 ; i < 100 ; i++){
		data.id = i+1;
		push(list,data);	
	}
	
	
	variantSort(list);
	printAllPositions(list);
	printf("\n");

	return 0;
}