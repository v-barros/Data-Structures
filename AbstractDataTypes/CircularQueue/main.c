/*
 * main.c
 *
 *  Created on: 2021-04-07
 *      Author: vinicius.barros
 */

#include "circularqueue.h"
#include <stdio.h>
#include <stdlib.h>
#define QUEUE_SIZE 10

int main(void){
	Queue * queue = newQueue(QUEUE_SIZE);
	int op,i=1;

		do {
			printf("\n\nTesting Queue\n");
	        printf("<1> Enqueue\n");
	        printf("<2> Dequeue\n");
	        printf("<3> Print Queue\n");
	        printf("<0> Exit\n");
	        printf("Option => ");
	        scanf("%d", &op);
	        printf("\n");
	        while(getchar()!='\n');
	        switch (op) {
	            case 1: enqueue(queue, i);
	                break;
	            case 2: printf("\ndequeue %d\n",dequeue(queue));
	                break;
	            case 3: printQueue(queue);
	                break;
	            case 0:
	                break;
	            default:
	            	printf("\nError: invalid input!\n");
	        }
	        i++;
	    }while (op != 0);

	return 0;
}
