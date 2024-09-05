#include <stdlib.h>
#include <stdio.h>
#include "header.h"

int main(){

	SLL list = createList();
	insertFront(list,1);
	insertFront(list,2);
	insertFront(list,3);
	insertBack(list,4);
	deleteFront(list);
	insertBack(list,5);
	deleteBack(list);
	deleteFront(list);
	deleteBack(list);
	deleteBack(list);
	display(list);

	return 0;
}