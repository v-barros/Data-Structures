/*
 * main.c
 *
 *  Created on: 27 de mar. de 2021
 *      Author: vinicius.barros
 *      Testing Bubble Sort algorithm
 */
#include "../../Utils/intarray.h"
#include "bubblesort.h"

int main(void){

    IntArray * intArray;
    int arraySize;
    printf("Array size: ");
    scanf("%d",&arraySize);
    printf("\n\n");

    intArray = initializeIntArray(arraySize);
    fill(intArray);

    printf("Before:\n");
    printArray(intArray);

    bubbleSort(intArray->v,intArray->arraySize);

    printf("After:\n");
    printArray(intArray);

    return 0;
}
