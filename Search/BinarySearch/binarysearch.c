/*
 * binarysearch.c
 *
 *  Created on: 2021-03-28
 *      Author: vinicius.barros
 */
#include "binarysearch.h"

int binarySearch(int* array, int arraySize,int key){
	int half,
	lower=0,
	upper=arraySize;

	while(upper>=lower){
		half = (lower+upper)/2;

		if(key==*(array+half))
			return half;

		if(key>*(array+half))
			lower=half+1;
		else
			upper=half-1;
	}
	return -1;
}



