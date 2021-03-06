/*
 * stack.h
 *
 *  Created on: 2021-03-28
 *      Author: vinicius.barros
 */
#ifndef STACK_H_
#define STACK_H_

typedef struct {
	int stackSize,top;
	int *items;
}Stack;

/*Allocates a Stack struct and returns its pointer*/
Stack * newStack(int);

/* Add a new element to the stack, returns 1 or 0*/
int push(Stack *,int);

/* Add n times the same element to the stack, returns 1 or 0*/
int pushMany(Stack *, int,int);

/* Remove an element from the top of the stack, returns 1 or 0*/
int pop(Stack *);

/* Remove n elements from the top of the stack, returns 1 or 0*/
int popMany(Stack *, int);

/* Get value of the top of the stack without removing the element from stack, assign the top value to an int pointer and returns 1 or 0*/
int peek(Stack *,int*);

/* Checks whether its full or not, returns 1 or 0 */
int isFull(Stack *);

/*Checks whether its empty or not, returns 1 or 0 */
int isEmptyT(Stack *);

/*Print stack from base to top*/
void printStack(Stack*);

#endif /* STACK_H_ */
