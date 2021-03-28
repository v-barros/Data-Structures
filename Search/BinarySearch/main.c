/*
 * main.c
 *
 *  Created on: 2021-03-28
 *      Author: vinicius.barros
 *      Testing binary search algorithm
 */
#include <stdio.h>
#include "binarysearch.h"
#include "../../Utils/intarray.h"

int main(void){
	int arraySize,numberToFind,found;
	IntArray *intArray;

	printf("Array Size: ");
	scanf("%d", &arraySize);
	printf("\n\n");

	intArray = initializeIntArray(arraySize);
	fillSorted(intArray);
	printArray(intArray);

	printf("Number to find in array: ");
	scanf("%d",&numberToFind);
	printf("\n");

	found = binarySearch(intArray->v, intArray->arraySize, numberToFind);

	if(found==-1)
		printf("Number not found\n");
	else
		printf("Number %d found at index %d\n",numberToFind, found);
	return 0;
}
