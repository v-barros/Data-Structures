/*
 * stack.c
 *
 *  Created on: 2021-03-28
 *      Author: vinicius.barros
 *      Implements stack.h
 */
#include <stdlib.h>
#include <stdio.h>
#include "stack.h"

Stack * newStack(int size){
	Stack * p;

	p = (Stack*) malloc(sizeof(Stack));
	if(p==NULL)
		return NULL;

	p->items = (int*) malloc(size*sizeof(int));
	if(p->items==NULL){
		free(p);
		return NULL;
	}
	p->stackSize=size;
	p->top=0;
	return p;
}

int push(Stack *stack,int num){
	if(isFull(stack))
		return 0;//overFlow
	*(stack->items+stack->top++) = num;
	return 1;
}

int pushMany(Stack * stack, int numToAdd,int nTimes){
	int i, max;
	max = stack->stackSize;

	if(stack->top+nTimes>max)
		return 0; //overFlow

	for(i =0; i<nTimes && stack->top<max ;i++)
		*(stack->items+stack->top++) = numToAdd;

	return 1;
}

int pop(Stack * stack){
	if(isEmptyT(stack))
		return 0;
	stack->top--;
	return 1;
}

int popMany(Stack * stack, int nTimes){
	if(stack->top-nTimes<0)
		return 0;
	stack->top-=nTimes;
	return 1;
}

int peek(Stack * stack, int *value){
	if(isEmptyT(stack))
		return 0;
	*value =  *(stack->items+stack->top-1);
	return 1;
}

int isFull(Stack * stack){
	return(stack->top>=stack->stackSize);
}

int isEmptyT(Stack *stack){
	return(!stack->top);
}

void printStack(Stack* stack){
	int i, max;
	max = stack->top;

	printf("\nStack:\nSize:[%d]\nCurrent usage:[%d]\n",stack->stackSize,max);
	for(i=0;i<max;i++){
		printf("%03d ",*(stack->items+i));
		if(i%10==9)
			printf("\n");
	}
	printf("\n");
}
