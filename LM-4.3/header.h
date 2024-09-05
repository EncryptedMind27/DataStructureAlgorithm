#ifndef HEADER_H
#define HEADER_H

typedef int Element;

typedef struct snode{
	Element data; 
	struct snode* next;
}*SNODE;

typedef struct singlyLinkedList{
	SNODE head;
	int size;
}*SLL;

SLL createList();
void insertFront(SLL, Element);
void insertBack(SLL, Element);
void deleteFront(SLL);
void deleteBack(SLL);
void display(SLL);

// 4.3 Here  

void sortAscending(SLL);

#endif 
