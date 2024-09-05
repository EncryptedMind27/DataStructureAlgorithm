#ifndef HEADER_H
#define HEADER_H

typedef int Element;
typedef struct cnode{
	Element data;
	struct cnode* next;
}*CNODE;

typedef struct circularLinkedList{
	CNODE head;
	int size;
}*CLL;

CLL createList();
void insertFront(CLL,Element);
void insertBack(CLL,Element);
void insertAt(CLL, Element, int);
void deleteBack(CLL);
void deleteFront(CLL);
void deleteAt(CLL,int);
void display(CLL);


#endif // HEADER_H
