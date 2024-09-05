#include <stdlib.h>
#include <stdio.h>
#include "header.h"

int main(){

	SLL list = createList();
	insertFront(list,1);
	insertFront(list,2);
	insertFront(list,3);
	insertBack(list,4);
	insertBack(list,7);
	insertFront(list,13);
	insertBack(list,9);
	insertBack(list,3);

	display(list);
	

	return 0;
}