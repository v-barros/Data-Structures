/*
 * intarray.h
 *
 *  Created on: 27 de mar. de 2021
 *      Author: vinicius.barros
 */

#ifndef INTARRAY_H_
#define INTARRAY_H_
#include <stdlib.h>
#include <time.h>
#include <stdio.h>

typedef struct {
int arraySize;
int *v;
} IntArray;

IntArray* initializeIntArray(int);
void printArray(IntArray*);
void fill(IntArray*);
void fillSorted(IntArray*);


#endif /* INTARRAY_H_ */
