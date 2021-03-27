/*
 * intarray.c
 *
 *  Created on: 27 de mar. de 2021
 *      Author: vinicius.barros
 */

#include "intarray.h"

IntArray* initializeIntArray(int n){
    IntArray * p = (IntArray*) malloc(sizeof(IntArray));

    if(p==NULL)
        return NULL;

    p->v = (int*) malloc(n*(sizeof(int)));

    if(p->v==NULL)
        return NULL;
    p->arraySize=n;

    return p;
}
void printArray(IntArray*intArray){
    int i;
    int n = intArray->arraySize;
	for(i=0;i<n;i++){
		printf("%03d ",*(intArray->v+i));
		if(i%10==9)
			printf("\n");
	}
	printf("\n");
}
void fill(IntArray*intArray){
    srand(time(NULL));
    int i;
    int n = intArray->arraySize;
	for(i=0;i<n;i++)
		*(intArray->v+i) = (int)rand()%1000;
}
