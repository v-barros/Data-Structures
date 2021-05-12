/*
 * main.c
 *
 *  Created on: 2021-04-28
 *      Author: @v-barros
 */
#include <stdio.h>
#include <stdlib.h>
#include "binarytree.h"

int main(void){
	int op,i=0;
	Tree * tree = newTree();

	do {
		printf("\n\nTesting Tree\n");
	    printf("<1> Insert\n");
	    printf("<2> Insert and debug\n");
	    printf("<3> Debug all\n");
	    printf("<4> Print Tree INORDER\n");
	    printf("<5> Print Tree PREORDER\n");
	    printf("<6> Print Tree POSTORDER\n");
	    printf("<7> Delete\n");
	    printf("<0> Exit\n");
	    printf("Option => ");
	    scanf("%d", &op);
	    printf("\n");
	    while(getchar()!='\n');
	    switch (op) {
	    	case 1:
	    			printf("\nNumber to add => ");
	    			scanf("%d", &i);
	    			printf("\n");
	    			while(getchar()!='\n');
	    			insert(tree, i);
	        	break;
	    	case 2:
	    			printf("\nNumber to add => ");
	    			scanf("%d", &i);
	    			printf("\n");
	    			while(getchar()!='\n');
	    			insertDebug(tree, i);
	    		break;
	    	case 3:debug(tree);
	    		break;
	    	case 4: printTreeInorderI(tree);
	        	break;
	    	case 5: printTreePreorderI(tree);
	    		break;
	    	case 6: printTreePostorderI(tree);
	    		break;
	    	case 7:
	    		    printf("\nNumber to delete => ");
	    		    scanf("%d", &i);
	    		    printf("\n");
	    		    while(getchar()!='\n');
	    		    delete(tree, i);
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
