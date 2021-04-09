/*
 * circularqueue.c
 *
 *  Created on: 2021-04-07
 *      Author: vinicius.barros
 *      Implementation of circularqueue.h
 *
 *      It's just the same as normal queue, but with a few modulus.
 */
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "circularqueue.h"


Queue * newQueue(int capacity){
	Queue * p = (Queue *) malloc(sizeof(Queue));
		if(p ==NULL)
			return NULL;

		p->data = (int *) malloc(capacity * sizeof(int));
		if(p->data == NULL)
			return NULL;
		memset(p->data, 0, capacity*sizeof(int));
		p->size = 0;
		p->front = -1;
		p->rear = -1;
		p->capacity = capacity;

		return p;
}

int enqueue(Queue * queue,int numToAdd){
	if(isFull(queue))
		return INT_MIN;
	*(queue->data+(queue->rear+1)%queue->capacity) = numToAdd;
	queue->rear = (queue->rear+1)%queue->capacity;
	queue->size++;
	if(queue->front ==-1)
		queue->front++;
	return 1;
}

int dequeue(Queue * queue){
	if(isEmpty(queue))
			return INT_MIN;
	int n = *(queue->data+queue->front);
	queue->front = (queue->front+1)%queue->capacity;
	queue->size--;
	return n;
}

int size(Queue * queue){
	return queue->size;
}

int isEmpty(Queue * queue){
	return (!queue->size);
}

int isFull(Queue * queue){
	return(queue->size==queue->capacity);
}

void printQueue(Queue* queue){
	if(isEmpty(queue)){
		printf("\nQueue is Empty!\n");
		return;
	}
	int i,j;

	printf("\nQueue:\nCapacity: [%d] Current usage: [%d] Front: [%d] Rear: [%d]\n",queue->capacity,queue->size,queue->front,queue->rear);
	for( i = queue->front, j = 0; j<queue->size ; j++,i++){
		printf("%03d ",*(queue->data+i%queue->capacity));
	}

	printf("\n");
}
