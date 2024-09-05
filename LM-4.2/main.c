#include <stdlib.h>
#include <stdio.h> 
#include "header.h"

int main(){
	DLL list = createList();
	insertFront(list,5);
	insertFront(list,8);
	insertBack(list,4);
	insertFront(list,9);
	insertAt(list,7,2);
	insertAt(list,6,3);
	insertBack(list,3);
	insertBack(list,2);
	insertBack(list,1);
	deleteFront(list);
	insertFront(list,0);
	deleteBack(list);
	insertBack(list,10);
	deleteAt(list,3);
	display(list);
	return 0;
}