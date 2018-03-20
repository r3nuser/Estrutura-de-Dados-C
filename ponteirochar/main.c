#include <stdlib.h>
#include <stdio.h>

char* fillString(){
	int i;
	printf("\nChoose I\n");
	scanf("%d",&i);
	return i<0?"Renan":"Willian";
}

int main(void){
	char* string;
	string = fillString();
	printf("\n%s\n",string);
	return 0;
}
