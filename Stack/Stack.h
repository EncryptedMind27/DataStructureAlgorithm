#ifndef STACK_LIST
#define STACK_LIST

#include <stdio.h>
#include <stdlib.h>

typedef int _element;
typedef struct stack {
	_element *arr;
	int size;
	int capacity;
} *STACK;

STACK createStack(int);
int isFull(STACK);
int isEmpty(STACK);
void push(STACK,_element);
void pop(STACK);
void display(STACK);


#endif