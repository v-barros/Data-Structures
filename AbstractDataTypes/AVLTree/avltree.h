/*
 * avltree.h
 *
 *  Created on: 2021-10-12
 *      Author: @v-barros
 */
#ifndef AVLTREE_H_
#define AVLTREE_H_

struct Node{
	int value;
	struct Node * leftChild;
	struct Node * rightChild;
    int height;
};
typedef struct Node Node;

typedef struct {
	Node * root;
	int height;
	int size;
} Tree;

Tree * newTree();

int insert(Tree *, int);

int delete(Tree *, int);

int isEmptyT(Tree *);

/* Left Right Root Iterative*/
void printTreePostorderI(Tree *);

/* Root Left Right Iterative*/
void printTreePreorderI(Tree *);

/*  Left Root Right Iterative*/
void printTreeInorderI(Tree * );

/* Print all node values and the references they're holding on left and right*/
void debug(Tree * );

/* Insert and print the address of the new node*/
int insertDebug(Tree *, int );


#endif /* AVLTREE_H_ */
