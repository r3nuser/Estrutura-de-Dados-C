#include "listaduplamenteencadeada.h"
#include <stdio.h>
#include <stdlib.h>

List* createList(){
	List* list = (List*) malloc(sizeof(List));
	if(list!=NULL)
		*list = NULL;
	return list;
}

void deleteList(List* list){
	if(list!=NULL){
		Node* node;
		while((*list) != NULL){
			node = *list;
			*list = (*list)->next;
			free(node);
		}
		free(list);
	}
}

void push(List* list, DataNode data){
	Node* node = (Node*) malloc(sizeof(Node));
	if(*list!=NULL)
		(*list)->previous = node;
	node->data = data;
	node->previous = NULL;
	node->next = (*list);
	*list = node;
}

void pop(List* list){
	if(isEmpty(list))
		return;
	Node* popped = *list;
	*list = (*list)->next;
	free(popped);
}

void printList(List* list){
	Node* node = *list;
	while(node!=NULL){
		printf("%d ",node->data.id);
		node = node->next;	
	}
}

void reversePrintList(List* list){
	Node* node = atPos(list,sizeList(list)-1);
	while(node!=NULL){
		printf("%d ",node->data.id);
		node = node->previous;
	}
}

void recursivePrintList(Node* node){
	printf("%d ", node->data.id);
	if(node->next==NULL)
		return;
	recursivePrintList(node->next);
}

bool isEmpty(List* list){
	if(*list==NULL)
		return true;
	return false;
}

int sizeList(List* list){
	if(isEmpty(list))
		return 0;
	int size=0;
	Node* node = *list;
	while(node!=NULL){
		size++;
		node = node->next;
	}
	return size;
}

Node* atPos(List* list, int index){
	if(index>=sizeList(list))
		return NULL;
	if(index==0)
		return *list;
	int i=0;
	Node* node = *list;
	while(index!=i){
		node = node->next;
		i++;
	}
	return node;
}

int indexOf(List* list, Node* node){
	if(node==NULL || *list==NULL)
		return -1;
	int index=0;
	Node* equals = *list;
	while(equals!=node){
		equals = equals->next;
		index++;
	}
	return index;
}

void erase(List* list, int index){
	if(isEmpty(list) || index<0 || index>=sizeList(list))
		return;
	else if(index==0)
		pop(list);
	else{
		Node* erased = atPos(list,index);
		Node* previous = atPos(list,index-1);
		previous->next = erased->next;
		if(erased->next!=NULL)
			erased->next->previous = previous;
		free(erased);
	}
}

void insert(List* list, DataNode data, int index){
	if(index==0)
		push(list,data);
	if(index>=sizeList(list))
		return;
	Node* insert = (Node*) malloc(sizeof(Node));
	insert->data = data;
	Node* current = atPos(list,index);
	current->previous->next = insert;
	insert->next = current;
	current->previous = insert;
}

void xchgNodes(List* list,Node* nodeA, Node* nodeB){
	if(nodeA==NULL||nodeB==NULL)
		return;
	else if(nodeA == nodeB)
		return;
	else{
		int indexA=indexOf(list,nodeA);
		int indexB=indexOf(list,nodeB);
		if(indexA>indexB){
			indexA = indexA + indexB;
			indexB = indexA - indexB;
			indexA = indexA - indexB;
			nodeA = atPos(list,indexA);
			nodeB = atPos(list,indexB);
		}
		Node* previousA = nodeA->previous;
		Node* nextA = nodeA->next;
		Node* previousB = nodeB->previous;
		Node* nextB = nodeB->next;
		if(nodeA==*list)
			*list=nodeB;
		else
			previousA->next=nodeB;
		if(nextB!=NULL)
			nextB->previous=nodeA;
		nextA->previous = nodeB;
		previousB->next = nodeA;
		Node atemp = *nodeA;
		nodeA->next = nodeB->next;
		nodeA->previous = nodeB->previous;
		nodeB->next = atemp.next;
		nodeB->previous = atemp.previous;
	}
}

Node* min(List* list, int index){
	Node* it = atPos(list,index);
	if(it!=NULL){
		Node* min = it;
		while(it!=NULL){
			min = it->data.id<min->data.id?it:min;
			it = it->next;
		}
		return min;
	}
	return NULL;
}

Node* max(List* list, int index){
	Node* it = atPos(list,index);
	if(it!=NULL){
		Node* max = it;
		while(it!=NULL){
			max = it->data.id>max->data.id?it:max;
			it = it->next;
		}
		return max;
	}
	return NULL;
}

void incSort(List* list){
	int i;
	for(i = 0; i < sizeList(list) ; i++)
		xchgNodes(list,atPos(list,i),min(list,i));
}

void decSort(List* list){
	int i;
	for(i = 0; i < sizeList(list) ; i++)
		xchgNodes(list,atPos(list,i),max(list,i));
}

void variantSort(List* list){
	int i;
	for(i = 0 ; i < sizeList(list) ; i++){
		if(i%2==0)
			xchgNodes(list,atPos(list,i),min(list,i));
		else
			xchgNodes(list,atPos(list,i),max(list,i));
	}
}

void printAllPositions(List* list){
	int i = 0;
	for( i = 0 ; i < sizeList(list) ; i++)
		printf("%d = %d\n", atPos(list,i)->data.id,indexOf(list,atPos(list,i)));
}