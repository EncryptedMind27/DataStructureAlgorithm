#include "Stack.h"

STACK createStack(int size){
	STACK stack = (STACK)malloc(sizeof(struct stack));
	if(stack == NULL){
		printf("STACK MALLOC FAILED!\n");
		exit(1);
	}
	stack->capacity = size;
	stack->arr = (_element*)malloc(sizeof(_element)*stack->capacity);
	stack->size = -1;

	return stack;
} 	

int isFull(STACK stack){
	if(stack->size == stack->capacity -1){
		return 1;
	} 
	return 0;
}	

int isEmpty(STACK stack){
	if(stack->size < 0){
		return 1;
	}
	return 0;
}

void push(STACK stack,_element data){
	if(!isFull(stack)){
		stack->arr[++stack->size] = data		;
	} else {
		printf("STACK IS FULL! \n");
	}
}

void pop(STACK stack){
	if(!isEmpty(stack)){
		stack->arr[stack->size--] = 0;
	} else {
		printf("STACK IS EMPTY\n");
	}
}

void display(STACK stack){
	if(!isEmpty(stack)){
		printf("Content: ");
		for(int i=0;i<=stack->size;i++){
			printf("%d ",stack->arr[i]);
		}
	} else {
		printf("STACK IS EMPTY!");
	}
	printf("\n");
} 