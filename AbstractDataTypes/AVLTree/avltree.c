/*
 * avltree.h
 *
 *  Created on: 2021-10-12
 *      Author: @v-barros
 */

#include "avltree.h"
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "../LinkedListStack/linkedliststack.h"

void basicAdd(Tree * tree, Node * nodeToAdd);

Node * new_node(int n);

void countHeight(Node *node);

int get_height(Node *node);

void set_height(Node *node);

int max (int x, int y);

int max (int x, int y){
	return x>y?x:y;
}
int get_height(Node *node){
	if(node)
		return node->height;
	return -1;
}

void set_height(Node *node){
	assert(node!=NULL);
	node->height = max(get_height(node->rightChild),get_height(node->leftChild)) +1;
}

void countHeight(Node * node){
	Stack * stack = newStack();
	push(stack,node);

	while(1){
		node =(Node *)pop(stack);
		if(node==NULL){
			if(isEmptyS(stack)){
				break;
			}
			node = (Node *)pop(stack);
			if(node->rightChild !=NULL
			&& node->rightChild == (Node*)peek(stack)){
				Node *aux =(Node*) pop(stack);
				push(stack,node);
				push(stack,aux);
			}else{
				set_height(node);
				push(stack,NULL);//this looks weird, but it works properly
			}
		}else if(node->rightChild!=NULL){
			push(stack,node->rightChild);
			push(stack,node);
			push(stack,node->leftChild);
		}else{
			push(stack,node);
			push(stack,node->leftChild);
		}
	}
	free(stack);
}

void basicAdd(Tree * tree, Node * nodeToAdd){
    int n;
    if(isEmptyT(tree)){
		tree->root = nodeToAdd;
	}else{
		Node * node = tree->root;
        do{
            if(nodeToAdd->value > node->value){//right
                if(node->rightChild == NULL){
                    node->rightChild = nodeToAdd;
                    n=1;
                }else{
                    node = node->rightChild;
                }
            }else{//left
                if(node->leftChild == NULL){
                    node->leftChild = nodeToAdd;
                    n=1;
                }else{
                    node = node->leftChild;
                }
            }
        }while(n!=1);
    }
}

Node * new_node(int n){
	Node * newnode = (Node*) malloc (sizeof(Node));
    assert(newnode!=NULL);
    newnode->value = n;
    newnode->leftChild = NULL;
    newnode->rightChild = NULL;

	return newnode;
}

Tree * newTree(){
    Tree * t = (Tree *) malloc (sizeof(Tree));
    assert(t!=NULL);
    t->height =0;
    t->root = NULL;
    t->size=0;

	return t;
}

int insert(Tree * tree, int numToAdd){
	Node * newNode = new_node(numToAdd);
    int i;
    basicAdd(tree,newNode);
	
	tree->size++;
	
   	countHeight(tree->root);
	return newNode->value;
}

int delete(Tree *, int);

int isEmptyT(Tree * tree){
	return (tree->root==NULL);
}

/* Left Right Root Iterative*/
void printTreePostorderI(Tree *);

/* Root Left Right Iterative*/
void printTreePreorderI(Tree *);

/*  Left Root Right Iterative*/
void printTreeInorderI(Tree * );

/* Print all node values and the references they're holding on left and right*/
void debug(Tree * tree){
	if(isEmptyT(tree)){
		printf("\n\nTree is Empty!\n");
		return;
	}

	Node * node = tree->root;
	Stack * stack = newStack();
	push(stack, node);

	while(1){
		node = (Node*)pop(stack);
		if(node!=NULL){
			push(stack,node);
			push(stack,node->leftChild);
		}else{
			if(isEmptyS(stack)){
				break;
			}
			node = (Node*)pop(stack);
			printf("\nThe node with value [%03d] has height %d and points to %p on the left and %p on the right\n",node->value,node->height,node->leftChild,node->rightChild);
			push(stack,node->rightChild);
		}

	}
	printf("\n");
	free(stack);
}


/* Insert and print the address of the new node*/
int insertDebug(Tree *, int );

void rightRotate(Node *);

void leftRotate(Node *);

void leftRightRotate(Node *);

void rightLeftRotate(Node *);
