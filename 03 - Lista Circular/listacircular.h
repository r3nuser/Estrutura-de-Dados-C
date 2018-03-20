typedef enum Boolean{
	true = 1, false = 0
}bool;

typedef struct datanode{
	int id;
}DataNode;

typedef struct node{
	DataNode data;
	struct node* next;
}Node;

typedef struct node* List;

List* createList();

void deleteList(List* list);

void push(List* list, DataNode data);

void pop(List* list);

void printList(List* list);

void recursivePrintList(List* list, Node* node);

bool isEmpty(List* list);

int sizeList(List* list);

Node* atPos(List* list, int index);

int indexOf(List* list, Node* node);

void erase(List* list, int index);

void insert(List* list, DataNode data, int index);

void xchgNodes(List* list,Node* nodeA, Node* nodeB);

Node* min(List* list, int index);

Node* max(List* list, int index);

void incSort(List* list);

void decSort(List* list);
