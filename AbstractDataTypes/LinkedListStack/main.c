/*
 * main.c
 *
 *  Created on: 2021-04-17
 *      Author: vinicius.barros
 */
#include <stdio.h>
#include <stdlib.h>
#include "linkedliststack.h"

int main(void){
	Stack *stack = newStack();
	int op,i=1;
	int * ptr;

	do {
		printf("\n\nTesting List\n");
	    printf("<1> Insert\n");
	    printf("<2> Remove\n");
	    printf("<3> Print List\n");
	    printf("<0> Exit\n");
	    printf("Option => ");
	    scanf("%d", &op);
	    printf("\n");
	    while(getchar()!='\n');
	    switch (op) {
	    	case 1:
	    		ptr = (int*) malloc(sizeof(int));
	    		*ptr = i;
	    		push(stack, ptr);
	        	break;
	        case 2:;
	        	int * n = (int*)pop(stack);
	        	if(n>1){
	        		printf("\npop: %d\n",*n);
	        		free(n);
	        	}
	        	break;
	        case 3: printStack(stack);
	        	break;
	        case 0:
	        	break;
	        default:
	        	printf("\nError: invalid input!\n");
	        }
	        i++;
	    }while (op != 0);
	return 1;
}
