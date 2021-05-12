/*
 * queue.c
 *
 *  Created on: 2021-04-06
 *      Author: @v-barros
 *      Implements queue.h
 *
 *      I chose to implement this queue by using a static array, but there is a way to implement queues using a linked list.
 *      Also, this is not a circular queue, so when queue.rear is equal queue.capacity there is no way to put new numbers.
 */


#include "queue.h"
#include <stdlib.h>
#include <stdio.h>


Queue * newQueue(int capacity){
	Queue * p = (Queue *) malloc(sizeof(Queue));
	if(p ==NULL)
		return NULL;

	p->data = (int *) malloc(capacity * sizeof(int));
	if(p->data == NULL)
		return NULL;

	p->size = 0;
	p->front = 0;
	p->rear = 0;
	p->capacity = capacity;

	return p;
}

int enqueue(Queue * queue,int numToAdd){
	if(isFull(queue))
		return 0;
	*(queue->data+queue->rear++) = numToAdd;
	queue->size++;
	return 1;
}

int dequeue(Queue * queue){
	if(isEmptyT(queue))
		return 0;

	queue->front++;
	queue->size--;
	return 1;
}

int peek(Queue * queue, int * value){
	if(isEmptyT(queue))
		return 0;

	*(value) = *(queue->data+queue->front);
	return 1;
}

int size(Queue * queue){
	return queue->size;
}

int isEmptyT(Queue * queue){
	return(!queue->size);
}

int isFull(Queue * queue){
	return (queue->rear>=queue->capacity);
}

void printQueue(Queue* queue){
	if(isEmptyT(queue)){
		printf("\nQueue is Empty!\n");
		return;
	}

	printf("\nQueue:\Capacity: [%d] Current usage: [%d] Front: [%d] Rear: [%d]\n",queue->capacity,queue->size,queue->front,queue->rear);
	int i;

	for(i = queue->front; i < queue->rear ; i++ ){
		printf("%03d ",*(queue->data+i));
	}

	printf("\n");
}



