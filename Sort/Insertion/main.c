/*
 * main.c
 *
 *  Created on: 27 de mar. de 2021
 *      Author: vinicius.barros
 *  Testing insertion algorithm
 */


#include "../../Utils/intarray.h"
#include "insertion.h"


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

    insertion(intArray->v,intArray->arraySize);

    printf("After:\n");
    printArray(intArray);


    return 0;
}
