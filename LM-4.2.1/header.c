#include <stdio.h>
#include <stdlib.h>
#include "header.h"

CLL createList(){
	CLL list = (CLL)malloc(sizeof(struct circularLinkedList));
	list->head = NULL;
	list->size = 0;

	return list;
}

void insertFront(CLL list, Element data){
	CNODE node = (CNODE)malloc(sizeof(struct cnode));
	node->data = data;
	if(list->size == 0){
		list->head = node;
		node->next = list->head;
		list->size++;
	} else {
		CNODE tmp = list->head;
		while(tmp->next != list->head)
			tmp = tmp->next;

		tmp->next = node;
		node->next = list->head;
		list->head = node;
		list->size++;
	}
}

void insertBack(CLL list, Element data){
	CNODE node = (CNODE)malloc(sizeof(struct cnode));
	CNODE tmp = list->head;
	node->data = data;
	
	while(tmp->next != list->head)
		tmp = tmp->next;

	tmp->next = node;
	node->next = list->head;
	list->size++;
}

void insertAt(CLL list, Element data, int pos){
	CNODE node = (CNODE)malloc(sizeof(struct cnode));
	node->data = data;
	if(pos == 0){
		insertFront(list,data);
	} else if(pos == list->size){
		insertBack(list,data);
	}

	CNODE tmp = list->head;
	while(--pos){
		tmp = tmp->next;
	}

	node->next = tmp->next;
	tmp->next = node;
	list->size++;
} 

void display(CLL list){
	CNODE tmp = list->head;
	int s = list->size;
	printf("Data[%d]: ",list->size);
	for(int i=0;i<s;i++){
		printf("%d ",tmp->data);
		tmp = tmp->next;
	}
}

void deleteBack(CLL list){
	CNODE tmp = list->head;
	while(tmp->next->next!=list->head)
		tmp = tmp->next;

	CNODE toDel = tmp->next;
	tmp->next = list->head;
	list->size--;

	free(toDel);
	toDel = NULL;
}

void deleteFront(CLL list){
	CNODE tmp = list->head;
	while(tmp->next != list->head)
		tmp = tmp->next;
	
	tmp->next = list->head->next;

	CNODE toDel = list->head;
	list->head = tmp->next;
	list->size--;

	free(toDel);
	toDel = NULL;
}

void deleteAt(CLL list, int pos){
	if(pos == 0){
		deleteFront(list);
	} else if(pos == list->size-1){
		deleteBack(list);
	}

	CNODE tmp = list->head;
	while(--pos)
		tmp = tmp->next;

	CNODE toDel = tmp->next;
	tmp->next = tmp->next->next;
	list->size--;

	free(toDel);
	toDel = NULL;
}