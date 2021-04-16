/*
 * linkedlist.c
 *
 *  Created on: 2021-04-15
 *      Author: vinicius.barros
 */
#include <stdio.h>
#include <stdlib.h>
#include "linkedlist.h"

LinkedList * newLinkedList(){
	LinkedList * p = (LinkedList *) malloc(sizeof(LinkedList));
	if(p!=NULL){
		p->head = NULL;
		p->last = NULL;
		p->size = 0;
	}
	return p;
}

Node * newNode(int n){
	Node * p = (Node *) malloc (sizeof(Node));
	if(p!= NULL){
		p->value = n;
		p->next = NULL;
		p->previous = NULL;
	}
	return p;
}

int insertFirst(LinkedList *linkedList,int numToAdd){
	Node * newnode = newNode(numToAdd);
	if(newnode!=NULL){
		if(isEmpty(linkedList)){
			linkedList->last = newnode;
		}else{
			linkedList->head->previous = newnode;
			newnode->next=linkedList->head;
		}
		linkedList->head = newnode;
		linkedList->size++;
		return 1;
	}
	return 0;
}

int insertLast(LinkedList * linkedList,int numToAdd){
	Node * newnode = newNode(numToAdd);
	if(newnode!=NULL){
		if(isEmpty(linkedList)){
			linkedList->head = newnode;
		}else{
			linkedList->last->next =newnode;
			newnode->previous = linkedList->last;
		}
		linkedList->last = newnode;
		linkedList->size++;
		return 1;
	}
	return 0;
}

int removeFirstOf(LinkedList * linkedList,int numToRemove){
	if(isEmpty(linkedList))
		return 0;

	Node * node  = linkedList->head;

	if(node->value == numToRemove){//numToRemove is at linked list head
		if(node->next==NULL){//linked list has only one element
			linkedList->head = NULL;
			linkedList->last = NULL;
		}else{
			linkedList->head->next->previous=NULL;
			linkedList->head =linkedList->head->next;
		}
		free(node);
		linkedList->size--;
		return 1;
	}

	while(node!=NULL && node->value!=numToRemove){
		node = node->next;
	}
	if(node!=NULL){// then node->value == numToRemove
		if(node->next == NULL){ // last Node
			node->previous->next = NULL;
			linkedList->last = node->previous;
		}else{
			node->next->previous = node->previous;
			node->previous->next = node->next;
		}
		free(node);
		linkedList->size--;
		return 1;
	}// not found
	return 0;
}

int removeLastOf(LinkedList * linkedList,int numToRemove){
	if(isEmpty(linkedList))
			return 0;

	Node * node  = linkedList->last;

	if(node->value == numToRemove){//numToRemove is at linked list last
		if(node->previous==NULL){// list has only one element
			linkedList->head = NULL;
			linkedList->last = NULL;
		}else{
			linkedList->last->previous->next = NULL;
			linkedList->last = linkedList->last->previous;
		}
		free(node);
		linkedList->size--;
		return 1;
	}

	while(node!=NULL && node->value!=numToRemove){
		node = node->previous;
	}
	if(node!=NULL){// then node->value == numToRemove
		if(node->previous==NULL){//first position
			node->next->previous= NULL;
			linkedList->head = node->next;
		}else{
			node->next->previous = node->previous;
			node->previous->next = node->next;
		}
		free(node);
		linkedList->size--;
		return 1;
	}// not found
	return 0;
}

int size(LinkedList * linkedList){
	return linkedList->size;
}

int isEmpty(LinkedList * linkedList){
	return linkedList->head == NULL;
}

void printListForwards(LinkedList * linkedList){
	if(isEmpty(linkedList)){
		printf("\nList is empty!\n");
		return;
	}
	int i = 0;
	Node * node =linkedList->head;
	printf("\nList:\nSize:[%d] Head:[%d] Last:[%d]\n",linkedList->size,linkedList->head->value,linkedList->last->value);

	while(node!=NULL){
		printf("%03d ",node->value);
		if(i%10==9)
			printf("\n");
		node = node->next;
		i++;
	}
	printf("\n");
}

void printListBackwards(LinkedList * linkedList){
	if(isEmpty(linkedList)){
		printf("\nList is empty!\n");
		return;
	}
	int i = 0;
	Node * node =linkedList->last;
	printf("\nList:\nSize:[%d] Head:[%d] Last:[%d]\n",linkedList->size,linkedList->head->value,linkedList->last->value);

	while(node!=NULL){
		printf("%03d ",node->value);
		if(i%10==9)
			printf("\n");
		node = node->previous;
		i++;
	}
	printf("\n");
}
