#include "listaencadeada.h"
#include <stdio.h>
#include <stdlib.h>
List* createList(){
	List* list = (List*) malloc(sizeof(List));
	list->size=0;
	list->head=NULL;
	return list;
}
void push(List* list, DataNode data){
	Node* node = (Node*) malloc(sizeof(Node));
	node->data = data;
	node->next = list->head;
	list->head = node;
	list->size++;
}
void pop(List* list){
	Node* deleted = list->head;
	list->head = deleted->next;
	free(deleted);
	list->size--;
}
void printList(List* list){
	Node* pointer = list->head;
	while(pointer!=NULL){
		printf(" %d -", pointer->data.id);
		pointer = pointer->next;
	}
}
void recursivePrintList(Node* node){
	printf(" %d -", node->data.id);
	if(node->next==NULL)
		return;
	else
		recursivePrintList(node->next);
}
bool isEmpty(List* list){
	if(list->head==NULL)
		return true;
	else
		return false;
}
Node* atPos(List* list, int index){
	int i = 0;
	if(index==0)
		return list->head;
	else{
		if(index>=list->size)
			return NULL;
		else{
			Node* pointer = list->head;
			for(i = 0 ; i < index ; i++){
				pointer = pointer->next;
			}
			return pointer;
		}
	}
}
int indexOf(List* list, Node* node){
	if(node==NULL)
		return -1;
	else{
		int index=0;
		Node* pointer = list->head;
		while(pointer!=node){
			index++;
			pointer = pointer->next;
			if(pointer==NULL){
				return -1;
			}
		}
		return index;
	}
}
void erase(List* list, int index){
	if(index<0 || index >= list->size)
		return;
	else if(index==0)
		pop(list);
	else{
		Node* current = atPos(list,index);
		Node* previous = atPos(list,index-1);
		previous->next = current->next;
		free(current);
		list->size--;
	}
}
void insert(List* list, DataNode data, int index){
	if(index<0 || index >= list->size)
		return;
	else if(index==0)
		push(list,data);
	else{
		Node* current = atPos(list,index);
		Node* previous = atPos(list,index-1);
		Node* insert = (Node*) malloc(sizeof(Node));
		insert->data = data;
		previous->next = insert;
		insert->next = current;
		list->size++;
	}
}
void xchgNodes(List* list,Node* nodeA, Node* nodeB){
	if(nodeA == NULL || nodeB == NULL)
		return;
	else if(nodeA == nodeB)
		return;
	else{
		int indexA = indexOf(list,nodeA);
		int indexB = indexOf(list,nodeB);
		if(indexA > indexB){
			indexA = indexB;
			indexB = indexOf(list,nodeA);
			nodeA = nodeB;
			nodeB = atPos(list,indexB);
		}
		Node* pb = atPos(list,indexB-1);
		if(nodeA == list->head)
			list->head = nodeB;
		else{
			Node* pa = atPos(list,indexA-1);
			pa->next = nodeB;
		}
		pb->next = nodeA;
		Node* pointer = nodeB->next;		
		nodeB->next = nodeA->next;
		nodeA->next = pointer;
	}
}
Node* min(List* list, int index){
	Node* pointer = atPos(list,index);
	if(pointer!=NULL){
		Node* minNode = pointer;
		while(pointer!=NULL){
			if(minNode->data.id > pointer->data.id)
				minNode = pointer;
			pointer = pointer->next;
		}
		return minNode;
	}
	return NULL;
}
Node* max(List* list, int index){
	Node* pointer = atPos(list,index);
	if(pointer!=NULL){
		Node* maxNode = pointer;
		while(pointer!=NULL){
			if(maxNode->data.id < pointer->data.id)
				maxNode = pointer;
			pointer = pointer->next;
		}
		return maxNode;
	}
	return NULL;
}
void incSort(List* list){
	int i = 0;
	for(i = 0 ; i < list->size ; i++)
		xchgNodes(list,atPos(list,i),min(list,i));
}
void decSort(List* list){
	int i = 0;
	for(i = 0 ; i < list->size ; i++)
		xchgNodes(list,atPos(list,i),max(list,i));
}