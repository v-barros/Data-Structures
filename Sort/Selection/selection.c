/*
 * selection.c
 *
 *  Created on: 27 de mar. de 2021
 *      Author: vinicius.barros
 */
#include "selection.h"

void selection(int * v,int n){
	int currentMinIndex, aux,j,i;
	for(i=0;i<n-1;i++){
		currentMinIndex = i;

		for(j=i+1;j<n;j++){
			if(*(v+j)<*(v+currentMinIndex)){
				currentMinIndex = j;
			}
		}

		if(currentMinIndex!= i){
			aux = *(v+i);
			*(v+i) = *(v+currentMinIndex);
			*(v+currentMinIndex) = aux;
		}
    }
}
