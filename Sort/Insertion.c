/*
*   Author: Vinicius Barros
*   Date:26/03/2021
*/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int * createIntVector(int);
void printVector(int*,int);
void fill(int*,int);
void insertion(int *,int );

int main(void){
    srand(time(NULL));
    int *vector,vectorSize;
    printf("Vector size: ");
    scanf("%d",&vectorSize);
    printf("\n\n");

    vector = createIntVector(vectorSize);
    fill(vector,vectorSize);

    printf("Before:\n");
    printVector(vector,vectorSize);

    insertion(vector,vectorSize);

    printf("After:\n");
    printVector(vector,vectorSize);

    return 0;
}
int * createIntVector(int size){
    return (int*)malloc(size*sizeof(int));
}
void printVector(int*v,int n){
	int i;
	for(i=0;i<n;i++){
		printf("%-6d ",*(v+i));
		if(i%11==10)
			printf("\n");
	}
	printf("\n");
}
void fill(int *v,int n){
	int i;
	for(i=0;i<n;i++)
		*(v+i) = (int)rand()%1000;
}
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

