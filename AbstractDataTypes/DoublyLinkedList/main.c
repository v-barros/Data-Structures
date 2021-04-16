/*
 * main.c
 *
 *  Created on: 2021-04-15
 *      Author: vinicius.barros
 */



#include "linkedlist.h"
#include <stdio.h>
#include <stdlib.h>


int main(void){
	LinkedList *linkedList = newLinkedList();
	int op,i=1,n;

	for(i = 0; i < 5; i++)
		insertFirst(linkedList, i);

	for(i = 0; i < 5; i++)
		insertLast(linkedList, i);

	i =0;
	do {
		printf("\n\nTesting List\n");
	    printf("<1> Insert in First position\n\n");
	    printf("<2> Remove first occurrence\n\n");
	    printf("<3> Print List in forward manner\n\n");
	    printf("<4> Insert in last position\n\n");
	    printf("<5> Remove last occurrence\n\n");
	    printf("<6> Print List in backward manner\n\n");
	    printf("<0> Exit\n");
	    printf("Option => ");
	    scanf("%d", &op);
	    printf("\n");
	    while(getchar()!='\n');
	    switch (op) {
	    	case 1:
	    		insertFirst(linkedList, i);
	        	break;
	        case 2:
	        	printf("\nnumToRemove => ");
	        	scanf("%d", &n);
	        	printf("\n");
	        	while(getchar()!='\n');
	        	removeFirstOf(linkedList, n);
	        	break;
	        case 3:
	        	printListForwards(linkedList);
	        	break;
	        case 4:
	        	insertLast(linkedList, i);
	        	break;
	        case 5:
	        	printf("\nnumToRemove => ");
	        	scanf("%d", &n);
	        	printf("\n");
	        	while(getchar()!='\n');
	        	removeLastOf(linkedList, n);
	        	break;
	        case 6:
	        	printListBackwards(linkedList);
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
