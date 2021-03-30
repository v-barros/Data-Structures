/*
 * main.c
 *
 *  Created on: 2021-03-29
 *      Author: vinicius.barros
 *      Testing stack structure
 */
#include <stdio.h>
#include "stack.h"

int main(void){
	Stack* stack = newStack(20);
	int op,i=1,n;
	int *p = &n;
		do {
			printf("\n\nTesting Stack\n");
	        printf("<1> Push\n");
	        printf("<2> Push Many\n");
	        printf("<3> Pop\n");
	        printf("<4> Pop Many\n");
	        printf("<5> Peek\n");
	        printf("<6> Print Stack\n");
	        printf("<0> Exit\n");
	        printf("Option => ");
	        scanf("%d", &op);
	        printf("\n");
	        while(getchar()!='\n');
	        switch (op) {
	            case 1: push(stack,i);
	                break;
	            case 2: pushMany(stack, i, 3);
	                break;
	            case 3: pop(stack);
	                break;
	            case 4: popMany(stack,3);
	                break;
	            case 5: if(peek(stack,p))printf("\ntop: %d\n",*p);
	                break;
	            case 6: printStack(stack);
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

