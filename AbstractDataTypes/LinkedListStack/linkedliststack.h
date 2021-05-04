/*
 * linkedliststack.h
 *
 *  Created on: 2021-04-17
 *      Author: vinicius.barros
 */

#ifndef LINKEDLISTSTACK_H_
#define LINKEDLISTSTACK_H_

struct StackNode{
	void * value;
	struct StackNode * next;
	struct StackNode * previous;
};
typedef struct StackNode StackNode;

typedef struct{
	int size;
	StackNode * head;
	StackNode * last;
}Stack;

Stack * newStack();

void * pop(Stack *);

int push(Stack *, void *);

int isEmptyS(Stack *);

void printStack(Stack *);

void * peek(Stack *);

#endif /* LINKEDLISTSTACK_H_ */
