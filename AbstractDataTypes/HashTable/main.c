/*
 * main.c
 *
 *  Created on: 2021-05-11
 *      Author: @v-barros
 */
#include "hashtable.h"
#include <stdio.h>
#include <stdlib.h>

int main(void){
	Table * table = createTable();
	int op,i=1,n;
	int *p = &n;
	//char * key,value;
	char key[20],value[20];
	do {
		printf("\n\nTesting Hash Table\n");
		printf("<1> Put \n");
		printf("<2> Get \n");
		printf("<3> \n");
		printf("<4>  \n");
		printf("<0> \n");
		printf("Option => ");
		scanf("%d", &op);
		printf("\n");
		while(getchar()!='\n');
		switch (op) {
			case 1:
				printf("Enter key\n=>");
				scanf ( "%[^\n]", key);
				while(getchar()!='\n');
				printf("Enter value\n=>");
				scanf ( "%[^\n]", value);
				while(getchar()!='\n');

				printf("%s\n",put(table, key, value));
				break;
			case 2:
				printf("Enter key\n=>");
				scanf ( "%[^\n]", key);
				//printf("%s %s",key,value);
				while(getchar()!='\n');
				printf("=>%s",getValue(table, key));
				break;
			case 3:
				break;
			case 4:
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
