#include "Stack.h"

int main(){
	STACK stack = createStack(10);	
	push(stack,1);
	push(stack,2);
	display(stack);
	pop(stack);
	display(stack);
	push(stack,4);
	push(stack,5);
	display(stack);
	return 0;
}