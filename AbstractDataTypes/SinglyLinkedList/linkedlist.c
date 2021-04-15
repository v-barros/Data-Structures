/*
 * linkedlist.c
 *
 *  Created on: 2021-04-11
 *      Author: vinicius.barros
 */

#include "linkedlist.h"
#include <stdio.h>
#include <stdlib.h>

LinkedList * newLinkedList (){
	LinkedList* p = (LinkedList *) malloc(sizeof(LinkedList));

	if(p!=NULL){
		p->size=0;
		p->head=NULL;
	}
	return p;
}

Node * newNode(int n){
	Node * node = (Node *) malloc(sizeof(Node));
	if(node!=NULL){
		node->next=NULL;
		node->value=n;
	}
	return node;
}

int insert(LinkedList * linkedList, int numToAdd){
	 Node * node = newNode(numToAdd);
	 if(node!=NULL){
		 node->next =(struct Node *)linkedList->head;
	 	 linkedList->head =node;
	 	 linkedList->size++;
	 	 return 1;
	 }
	 return 0;
}

int removeFirstOf(LinkedList * linkedList,int numToRemove){
	Node * node  = linkedList->head;
	Node * previous = node;

	if(node->value == numToRemove){//numToRemove is at linked list head
		linkedList->head =(Node *) node->next;
		free(node);
		linkedList->size--;
		return 1;
	}

	while(node!=NULL && node->value!=numToRemove){
		previous = node;
		node =(Node *) node->next;

	}
	if(node!=NULL){// then node->value == numToRemove
		previous->next = node->next;
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
	return linkedList->head==NULL;
}

void printList(LinkedList * linkedList){
	if(isEmpty(linkedList)){
		printf("\nList is empty!\n");
		return;
	}
	int i = 0;
	Node * node =linkedList->head;
	printf("\nList:\nSize:[%d] Head:[%d]\n",linkedList->size,node->value);


	while(node!=NULL){
		printf("%03d ",node->value);

		if(i%10==9)
			printf("\n");

		node =(Node *) node->next;
		i++;
	}

	printf("\n");
}
