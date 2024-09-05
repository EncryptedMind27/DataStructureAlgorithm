#include <stdio.h>
#include <stdlib.h>
#include "header.h"

int main(){
	CLL list = createList();
	insertFront(list,4);
	insertFront(list,3);
	insertFront(list,2);
	insertBack(list,0);
	insertBack(list,1);
	deleteBack(list);
	deleteFront(list);
	insertFront(list,2);
	deleteBack(list);
	insertFront(list,1);
	insertAt(list,0,2);
	deleteAt(list,3);
	display(list);
	return 0;
}