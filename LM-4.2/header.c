#include <stdio.h>
#include <stdlib.h>
#include "header.h"

DLL createList(){
	DLL list = (DLL)malloc(sizeof(struct doublyLinkedList));
	if(list == NULL){
		printf("Memory allocation failed!");
		exit(1);
	}

	list->head = NULL;
	list->tail = NULL;
	list->size = 0;

	return list;
}

void insertFront(DLL list, Element data){
	DNODE node = (DNODE)malloc(sizeof(struct dnode));
	if(node == NULL){
		printf("Memory allocation failed!");
		exit(1);
	}

	if(list->size == 0){
		list->head = node;
		list->tail = node;
	}

	node->data = data;
	node->next = list->head;
	node->prev = NULL;

	list->head->prev = node;
	list->head = node;

	list->size++;
}


void insertBack(DLL list, Element data){
 	DNODE node = (DNODE)malloc(sizeof(struct dnode));
	if(node == NULL){
		printf("Memory allocation failed!");
		exit(1);
	}

	if(list->size == 0){
		list->head = node;
		list->tail = node;
	}

	node->data = data;
	node->prev = list->tail;
	node->next = NULL;

	list->tail->next = node;
	list->tail = node;

	list->size++;
}

void insertAt(DLL list, Element data, int pos){
	if(pos == list->size){
		insertBack(list,data);
		return;
	} else if(pos == 0){
		insertFront(list,data);
		return; 
	}

	DNODE node = (DNODE)malloc(sizeof(struct dnode));
	DNODE tmp = list->head;

	while(--pos){
		tmp = tmp->next;
	}
	node->data = data;

	node->next = tmp->next;
	node->prev = tmp;

	tmp->next->prev = node;
	tmp->next = node;
	list->size++;
}	

void deleteFront(DLL list){
	DNODE tmp = list->head;	
	tmp->next->prev = NULL;
	list->head = tmp->next;
	list->size--;

	free(tmp);
	tmp = NULL;
}

void deleteBack(DLL list){
	DNODE tmp = list->tail;
	tmp->prev->next = NULL;
	list->tail = tmp->prev;
	list->size--;

	free(tmp);
	tmp = NULL;
}

void deleteAt(DLL list, int pos){
	if(pos == 0){
		deleteFront(list);
		return;
	} else if (pos == list->size-1){
		deleteBack(list);
	}

	DNODE tmp = list->head;

	while(pos--){
		tmp = tmp->next;
	}

	tmp->prev->next = tmp->next;
	tmp->next->prev = tmp->prev;	
	list->size--;

	free(tmp);
	tmp = NULL;

}

void display(DLL list){
 	DNODE tmp = list->head;
 	int s = list->size;
 	printf("Data[%d]: ",list->size); 
 	while(s--) {
 	    printf("%d ", tmp->data);
 	    tmp = tmp->next;
 	}
}
