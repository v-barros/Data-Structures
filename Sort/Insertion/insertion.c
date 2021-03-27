/*
 * insertion.c
 *
 *  Created on: 27 de mar. de 2021
 *      Author: vinicius.barros
 */

#include "../../Utils/intarray.h"
#include "insertion.h"

void insertion(int *v,int n){
	int i,j,key;
	for(i=1;i<n;i++){
		key=*(v+i);
		j=i-1;
		while(j>=0&&*(v+j)>key){
			*(v+j+1) =*(v+j);
			j--;
		}
	*(v+j+1) = key;
	}
}
