#include <stdio.h>
#include <stdlib.h>
#include "listaencadeada.h"

int main(){
	List* list = createList();
	DataNode data;
	int i = 0;
	
	for(i=0;i<10;i++){
		data.id=i;
		push(list,data);
	}

	printf("\n\n");
	incSort(list);
	printList(list);
	printf("\n");
	decSort(list);
	printList(list);
	printf("\n\n");
	
	return 0;
}
