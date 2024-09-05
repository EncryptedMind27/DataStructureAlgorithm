#include <stdlib.h>
#include <stdio.h>
#include "header.h"

SLL createList(){
	SLL list = (SLL)malloc(sizeof(struct singlyLinkedList));
	if (list == NULL) {
        printf("Memory allocation failed\n");
        exit(1);
    }

	list->head = NULL;
	list->size = 0;
	return list;
}

void insertFront(SLL list, Element data){
	SNODE node = (SNODE)malloc(sizeof(struct snode));
	if (node == NULL) {
        printf("Memory allocation failed\n");
        exit(1);
    }
	node->data = data;
	node->next = list->head;

	list->head = node;
	list->size++;
}

void insertBack(SLL list, Element data){
	SNODE tmp;
	SNODE node = (SNODE)malloc(sizeof(struct snode));
	if(node == NULL){
		printf("Memory allocation failed!\n");
		exit(1);
	}

	if(list->size == 0){
		insertFront(list,data);
		return;
	}

	node->data = data;
	node->next = NULL;
	list->size++;

	tmp = list->head;
	while(tmp->next != NULL){
		tmp = tmp->next;
	}
	tmp->next = node;
}

void deleteFront(SLL list){
	SNODE tmp = list->head;
	list->head = tmp->next;
	free(tmp);
	tmp = NULL;
	list->size--;
}

void deleteBack(SLL list){
	if(list->size == 1){
		deleteFront(list);
		return;
	}
	SNODE tmp = list->head;
	while(tmp->next->next != NULL){
		tmp = tmp->next;
	}
	SNODE toDelete = tmp->next;
	tmp->next = NULL;
	free(toDelete);
	toDelete = NULL;
	list->size--;
}

void display(SLL list){
	SNODE tmp = list->head;
	printf("Data[%d]: ",list->size);

	while(tmp != NULL){
		printf("%d ",tmp->data);
		tmp = tmp->next;
	}
}