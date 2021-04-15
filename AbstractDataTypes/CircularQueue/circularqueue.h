/*
 * circularqueue.h
 *
 *  Created on: 2021-04-07
 *      Author: vinicius.barros
 */

#ifndef CIRCULARQUEUE_H_
#define CIRCULARQUEUE_H_


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

/*Return the number of elements in the queue. */
int size(Queue *);

/*Check whether the queue is empty or not, return 1 or 0 */
int isEmpty(Queue *);

/*Check whether the queue is full or not, return 1 or 0 */
int isFull(Queue *);

void printQueue(Queue*);


#endif /* CIRCULARQUEUE_H_ */

