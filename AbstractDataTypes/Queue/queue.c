/*
 * queue.c
 *
 *  Created on: 2021-04-06
 *      Author: vinicius.barros
 *      Implements queue.h
 *
 *      I chose to implement this queue by using a static array, but there is a way to implement queues using a linked list.
 *      Also, this is not a circular queue, so sooner or later it's going to reach its the max capacity.
 */


#include "queue.h"
#include <stdlib.h>
#include <stdio.h>


/*Allocates a new Queue and return its pointer */
Queue * newQueue(int capacity){
	Queue * p = (Queue *) malloc(sizeof(Queue));
	if(p ==NULL)
		return NULL;

	p->data = (int *) malloc(capacity * sizeof(int));
	if(p->data == NULL)
		return NULL;

	p->capacity = capacity;
	p->front = 0;
	p->rear = 0;
	p->size = 0;

	return p;
}

/*Add an element at the end of the queue.*/
int enqueue(Queue * queue,int numToAdd){
	if(isFull(queue))
		return 0;
	*(queue->data+queue->rear++) = numToAdd;
	queue->size++;
	return 1;
}

/* Remove the first element of the queue, if the queue is not empty.Return 1 or 0 */
int dequeue(Queue * queue){
	if(isEmpty(queue))
		return 0;

	queue->front++;
	queue->size--;
	return 1;
}

/*Return the element on the front of the queue without removing it, if the queue is not empty.*/
int peek(Queue * queue, int * value){
	if(isEmpty(queue))
		return 0;

	*(value) = *(queue->data+queue->front);
	return 1;
}

/*Return the number of elements in the queue. */
int size(Queue * queue){
	return queue->size;
}

/*Check whether the queue is empty or not, return 1 or 0 */
int isEmpty(Queue * queue){
	return(!queue->size);
}

/*Check whether the queue is full or not, return 1 or 0 */
int isFull(Queue * queue){
	return (queue->rear>=queue->capacity);
}

void printQueue(Queue* queue){
	if(isEmpty(queue)){
		printf("\nQueue is Empty!\n");
		return;
	}

	printf("\nQueue:\nSize: [%d] Current usage: [%d] Front: [%d] Rear: [%d]\n",queue->capacity,queue->size,queue->front,queue->rear);
	int i;

	for(i = queue->front; i < queue->rear ; i++ ){
		printf("%03d ",*(queue->data+i));
	}

	printf("\n");
}



