/*
 * queue.h
 *
 *  Created on: 2021-04-06
 *      Author: vinicius.barros
 */

#ifndef QUEUE_H_
#define QUEUE_H_

typedef struct {
	int rear, front,size;
	unsigned int capacity;
	int *data;
}Queue;

/*Allocates a new Queue and return a pointer its pointer */
Queue * newQueue(int capacity);

/*Add an element at the end of the queue.*/
int enqueue(Queue *,int);

/* Remove and return the first element of the queue, if the queue is not empty. */
int dequeue(Queue *);

/*Return the element on the front of the queue without removing it, if the queue is not empty.*/
int peek(Queue *, int *);

/*Return the number of elements in the queue. */
int size(Queue *);

/*Check whether the queue is empty or not, return 1 or 0 */
int isEmptyT(Queue *);

/*Check whether the queue is full or not, return 1 or 0 */
int isFull(Queue *);

void printQueue(Queue*);

#endif /* QUEUE_H_ */
