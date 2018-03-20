#include "listacircular.h"
#include <stdio.h>
#include <stdlib.h>

List* createList(){
	List* list = (List*) malloc(sizeof(List));
	if(list!=NULL)
		*list=NULL;
	return list;
}

void deleteList(List* list){
	if(list!=NULL){
		Node* init = *list;
		Node* node;
		while(*list!=init){
			node = *list;
			*list = (*list)->next;
			free(node);
		}
		free(list);
	}
}

void push(List* list, DataNode data){
	if(list==NULL)
		return;
	Node* node = (Node*) malloc(sizeof(Node));
	node->data = data; 
	if(*list==NULL){
		*list = node;
		node->next = node;
	}else{
		Node* pointer = *list;
		while(pointer->next!=*list)
			pointer = pointer->next;
		node->next = pointer->next;
		pointer->next = node;
	}
}

void pop(List* list){
	if(list==NULL || *list==NULL)
		return;
	Node* previous = *list;
	if(previous->next == *list){
		free(previous);
		*list = NULL;
	}else{
		Node* pointer;
		while(previous->next->next!=*list)
			previous = previous->next;
		pointer = previous->next;
		previous->next = pointer->next;
		free(pointer);
	}
}

void printList(List* list){
	if(list==NULL || *list==NULL)
		return;
	Node* node = *list;
	do{
		printf("%d ",node->data.id);
		node = node->next;
	}while(node!=*list);
}

void recursivePrintList(List* list, Node* node){
	if(list==NULL || *list==NULL)
		return;
	printf("%d ", node->data.id);
	if(node->next!=*list)
		recursivePrintList(list,node->next);
}

bool isEmpty(List* list){
	return *list==NULL?true:false;
}

int sizeList(List* list){
	if(list==NULL || *list==NULL)
		return 0;
	Node* pointer = *list;
	if(pointer->next==*list)
		return 1;
	int i=0;
	do{
		i++;
		pointer = pointer->next;
	}while(pointer!=*list);
	return i;
}

Node* atPos(List* list, int index){
	if(list==NULL || *list==NULL || index>sizeList(list))
		return NULL;
	int i;
	Node* pointer = *list;
	for(i = 0 ; i < index ; i++)
		pointer = pointer->next;
	return pointer;
}

int indexOf(List* list, Node* node){
	if(list==NULL || *list==NULL || node==NULL)
		return -1;
	Node* pointer = *list;
	int i = 0;
	while(pointer!=node){
		i++;
		pointer = pointer->next;
	}
	return i;
}

void erase(List* list, int index){
	int size=sizeList(list);
	if(list==NULL || *list==NULL || index<0 || index>=size)
		return;
	if(index==size-1)
		pop(list);
	else{
		Node* erased = atPos(list,index);
		Node* previous;
		if(index==0){
			previous = atPos(list,size-1);
			*list = erased->next;
		}else
		previous = atPos(list,index-1);
		
		previous->next = erased->next;
		
		free(erased);
	}
}

void insert(List* list, DataNode data, int index){
	int size = sizeList(list);

	if(list == NULL || index>size || index<0)
		return;
	if(index==size || *list == NULL)
		push(list,data);		
	else{
		Node* inserted = (Node*) malloc(sizeof(Node));
		inserted->data = data;
		Node* previous;
		if(index==0){
			previous = atPos(list,size-1);
			*list = inserted;
		}else
		previous = atPos(list,index-1);
		inserted->next = previous->next;
		previous->next = inserted;
	}

}

void xchgNodes(List* list,Node* nodeA, Node* nodeB){
	if(list== NULL || *list == NULL || sizeList(list)==1)
		return;
	if(nodeA == nodeB)
		return;
	int indexA = indexOf(list,nodeA);
	int indexB = indexOf(list,nodeB);

	if(indexA > indexB){
		indexA = indexA + indexB;
		indexB = indexA - indexB;
		indexA = indexA - indexB;

		nodeA = nodeB;
		nodeB = atPos(list,indexB);
	}
	Node* pA;
	Node* pB = atPos(list,indexB-1);
	
	if(indexA==0){
		pA = atPos(list,sizeList(list)-1);
		*list = nodeB;
	}else{
		pA = atPos(list,indexA-1);
	}
	pA->next = nodeB;
	pB->next = nodeA;
	
	Node* pointer = nodeB->next;
	nodeB->next = nodeA->next;
	nodeA->next = pointer;
	
}

Node* min(List* list, int index){
	Node* min = atPos(list,index);
	Node* pointer = min;
	do{
		min=pointer->data.id<min->data.id?pointer:min;
		pointer = pointer->next;
	}while(pointer!=*list);
	return min;
}

Node* max(List* list, int index){
	Node* max = atPos(list,index);
	Node* pointer = max;
	do{
		max=pointer->data.id>max->data.id?pointer:max;
		pointer = pointer->next;
	}while(pointer!=*list);
	return max;
}

void incSort(List* list){
	int i;
	for(i = 0 ; i < sizeList(list) ; i++)
		xchgNodes(list,atPos(list,i),max(list,i));
}

void decSort(List* list){
	int i;
	for(i = 0 ; i < sizeList(list) ; i++)
		xchgNodes(list,atPos(list,i),min(list,i));
}


