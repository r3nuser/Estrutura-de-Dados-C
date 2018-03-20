#include "listacircular.h"
#include <stdlib.h>
#include <stdio.h>

int main(void){
	List* list  = createList();

	DataNode data;
	data.id = 10;
	push(list,data);
	data.id = 20;
	push(list,data);
	data.id = 30;
	push(list,data);
	data.id = 40;
	push(list,data);

	printf("\n");
	printList(list);
	printf("\n");
	
	deleteList(list);
	return 0;
}