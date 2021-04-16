/*
 * main.c
 *
 *  Created on: 2021-04-12
 *      Author: vinicius.barros
 */


#include "linkedlist.h"
#include <stdio.h>
#include <stdlib.h>


int main(void){
	LinkedList *linkedList = newLinkedList();
	int op,i=1;

	for(i = 0; i < 10; i++)
		insert(linkedList, i);

	i =0;
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
	    	case 1: insert(linkedList, i);
	        	break;
	        case 2:
	        	printf("\nnumToRemove => ");
	        	scanf("%d", &i);
	        	printf("\n");
	        	while(getchar()!='\n');
	        	removeFirstOf(linkedList, i);
	        	break;
	        case 3: printList(linkedList);
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
