/*
 * linkedliststack.c
 *
 *  Created on: 2021-04-17
 *      Author: vinicius.barros
 */


#include <stdio.h>
#include <stdlib.h>
#include "linkedliststack.h"

Stack * newStack(){
	Stack * p = (Stack *) malloc (sizeof(Stack));

	if(p!=NULL){
		p->size=0;
		p->head=NULL;
		p->last=NULL;
	}

	return p;
}

StackNode * newNodeS(void * n){
	StackNode * newnode = (StackNode*) malloc(sizeof(StackNode));

	if(newnode!=NULL){
		newnode->value=n;
		newnode->next=NULL;
		newnode->previous=NULL;
	}
	return newnode;
}

void * pop(Stack * stack){
	if(isEmptyS(stack))
		return NULL;

	StackNode * node = stack->head;
	void * n = stack->head->value;

	if(stack->head->next!=NULL){
		stack->head->next->previous=NULL;
		stack->head = stack->head->next;
	}else{//only 1 element
		stack->head=NULL;
		stack->last=NULL;
	}

	stack->size--;
	free(node);
	return n;
}

int push(Stack * stack, void * valueToPush){
	StackNode * newnode = newNodeS(valueToPush);
	if(newnode==NULL){
		return 0;
	}

	if(isEmptyS(stack)){
		stack->head=newnode;
		stack->last=newnode;
	}else{
		stack->head->previous=newnode;
		newnode->next=stack->head;
		stack->head=newnode;
	}
	stack->size++;
	return 1;

}

int isEmptyS(Stack * stack){
	return stack->head==NULL;
}

void printStack(Stack * stack){
	if(isEmptyS(stack)){
		printf("\nList is empty!\n");
		return;
	}
	int i = 0;
	StackNode * node = stack->last;
	/*
	 * I'm assuming I'm only pushing int variables into stack, because there is no trivial way to check what type of data a void pointer is pointing to;
	 */
	printf("\nList:\nSize:[%d] Head:[%d]\n",stack->size,*(int*)(stack->head->value));

	while(node!=NULL){
		printf("%03d ",*(int*)node->value);
		if(i%10==9)
			printf("\n");
		node = node->previous;
		i++;
	}
		printf("\n");
}
void * peek(Stack * stack){
	if(isEmptyS(stack))
				return NULL;
	return stack->head->value;
}
