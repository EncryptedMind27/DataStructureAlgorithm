#ifndef HEADER_H
#define HEADER_H

typedef int Element;

typedef struct dnode
{
	Element data;
	struct dnode* next;
	struct dnode* prev;
}*DNODE;

typedef struct doublyLinkedList{
	DNODE head;
	DNODE tail;
	int size;
}*DLL;

DLL createList();
void insertFront(DLL, Element);
void insertBack(DLL, Element);
void insertAt(DLL, Element, int);
void deleteFront(DLL);
void deleteBack(DLL);
void deleteAt(DLL,int);
void display(DLL);


#endif // HEADER_H
