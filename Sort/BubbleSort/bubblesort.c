/*
 * bubblesort.c
 *
 *  Created on: 27 de mar. de 2021
 *      Author: vinicius.barros
 */
#include "bubblesort.h"

void bubbleSort(int *v,int n){
	int i,j,aux;
	for(i=1;i<n;i++){
		for(j=0;j<n-i;j++){
   			if(*(v+j)>*(v+j+1)){
				aux = *(v+j);
				*(v+j)=*(v+j+1);
				*(v+j+1)=aux;
			}
		}
	}
}

