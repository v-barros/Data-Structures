/*
 * binarytree.c
 *
 *  Created on: 2021-04-26
 *      Author: @v-barros
 */
#include <stdio.h>
#include <stdlib.h>
#include "binarytree.h"
#include "../LinkedListStack/linkedliststack.h"
#define ITEMS_PER_LINE 10

Tree * newTree(){
	Tree * t = (Tree *) malloc (sizeof(Tree));
	if(t!=NULL){
		t->height =0;
		t->root = NULL;
		t->size=0;
	}
	return t;
}

Node * newNode(int n){
	Node * newnode = (Node*) malloc (sizeof(Node));
	if(newnode!=NULL){
		newnode->value = n;
		newnode->leftChild = NULL;
		newnode->rightChild = NULL;
	}
	return newnode;
}

int insert(Tree * tree, int numToAdd){
	Node * newnode = newNode(numToAdd);
	int n =0;
	if(newnode!=NULL){

		if(isEmptyT(tree)){
			tree->root = newnode;
		}else{
			Node * node = tree->root;
			do{
				if(newnode->value > node->value  ){//right
					if(node->rightChild == NULL){
						node->rightChild = newnode;
						n=1;
					}else{
						node = node->rightChild;
					}
				}else{//left
					if(node->leftChild == NULL){
						node->leftChild = newnode;
						n=1;
					}else{
						node = node->leftChild;
					}
				}
			}while(n!=1);
		}
		tree->size++;
		return 1;
	}
	return 0;
}

int insertDebug(Tree * tree, int numToAdd){
	Node * newnode = newNode(numToAdd);
	int n =0;
	if(newnode!=NULL){

		if(isEmptyT(tree)){
			tree->root = newnode;
		}else{
			Node * node = tree->root;
			do{
				if(newnode->value > node->value  ){//right
					if(node->rightChild == NULL){
						node->rightChild = newnode;
						n=1;
					}else{
						node = node->rightChild;
					}
				}else{//left
					if(node->leftChild == NULL){
						node->leftChild = newnode;
						n=1;
					}else{
						node = node->leftChild;
					}
				}
			}while(n!=1);
		}
		printf("\nThe address of [%d] is: 0x%x\n",newnode->value,newnode);
		tree->size++;
		return 1;
	}
	return 0;
}

Node * findPreviousBiggest(Node * node){
	node = node->leftChild;
	Node * previous = node;
	while(node->rightChild!=NULL){
		previous = node;
		node=node->rightChild;
	}
	return previous;
}

void deleteExec(Tree * tree,Node * previous, Node *nodeToDelete){

	if(nodeToDelete->rightChild==NULL && nodeToDelete->leftChild==NULL){
		if(previous==NULL){
			tree->root=NULL;
		}else if(previous->leftChild == nodeToDelete){
			previous->leftChild = NULL;
		}else{
			previous->rightChild = NULL;
		}

	}else if(nodeToDelete->leftChild == NULL){
		if(previous==NULL){
			tree->root = nodeToDelete->rightChild;
		}else if(previous->leftChild == nodeToDelete){
			previous->leftChild = nodeToDelete->rightChild;
		}else{
			previous->rightChild = nodeToDelete->rightChild;
		}

	}else if(nodeToDelete->rightChild == NULL){
		if(previous==NULL){
			tree->root = nodeToDelete->leftChild;
		}
		if(previous->leftChild == nodeToDelete){
			previous->leftChild = nodeToDelete->leftChild;
		}else{
			previous->rightChild = nodeToDelete->leftChild;
		}

	}else{
		Node * nodeToSwap = findPreviousBiggest(nodeToDelete); // find biggest number on nodeToDelete->leftchild subtree
		if(nodeToSwap->rightChild!=NULL){
			nodeToDelete->value = nodeToSwap->rightChild->value;
			nodeToDelete = nodeToSwap->rightChild;
			nodeToSwap->rightChild = nodeToSwap->rightChild->leftChild;
		}else{
			nodeToDelete->value = nodeToSwap->value;
			nodeToDelete->leftChild =nodeToSwap->leftChild;
			nodeToDelete = nodeToSwap;
		}
	}
	free(nodeToDelete);
}

/* return the father of first occurrence of a node containing numToFind, if exists*/
Node * find(Node * node, int numToFind){
	Node * previous=node;
	do{
		if(node==NULL) // not found
			return NULL;
		if(numToFind == node->value){
			return previous;
		}
		previous = node;
		if(numToFind > node->value){//right
			node = node->rightChild;
		}else{//left
			node = node->leftChild;
		}
	}while(1);

}

int delete(Tree * tree, int numToDelete){
	if(isEmptyT(tree))
		return 0;

	if(tree->root->value == numToDelete){
		deleteExec(tree,NULL, tree->root);
		return 1;
	}
	Node * previousOfNumToDelete=find(tree->root,numToDelete);

	if(previousOfNumToDelete==NULL)
		return 0;

	if(previousOfNumToDelete->leftChild->value ==numToDelete)
		deleteExec(tree,previousOfNumToDelete, previousOfNumToDelete->leftChild);
	else
		deleteExec(tree,previousOfNumToDelete, previousOfNumToDelete->rightChild);
	return 1;
}

int isEmptyT(Tree * tree){
	return (tree->root==NULL);
}

void printTreePostorderI(Tree * tree){
	if(isEmptyT(tree)){
		printf("\n\nTree is Empty!\n");
		return;
	}
	int i =0;
	Node * node = tree->root;
	Stack * stack = newStack();
	push(stack,node);

	while(1){
		node =(Node *)pop(stack);
		if(node==NULL){
			if(isEmptyS(stack)){
				break;
			}
			node = (Node *)pop(stack);
			if(node->rightChild == (Node*)peek(stack)){
				Node *aux =(Node*) pop(stack);
				push(stack,node);
				push(stack,aux);
			}else{
				printf("%03d ",node->value);
				push(stack,NULL);//this looks weird, but it works properly
				if(i%ITEMS_PER_LINE==ITEMS_PER_LINE-1)
					printf("\n");
				i++;
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
	printf("\n");
	free(stack);
}

void printTreeInorderI(Tree * tree){
	if(isEmptyT(tree)){
		printf("\n\nTree is Empty!\n");
		return;
	}
	int i =0;
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
			printf("%03d ",node->value);
			push(stack,node->rightChild);
			if(i%ITEMS_PER_LINE==ITEMS_PER_LINE-1)
				printf("\n");
			i++;
		}
	}
	printf("\n");
	free(stack);
}

void printTreePreorderI(Tree * tree){
	if(isEmptyT(tree)){
		printf("\n\nTree is Empty!\n");
		return;
	}
	int i =0;
	Node * node = tree->root;
	Stack * stack = newStack();
	push(stack, node);
	while(1){
		node = (Node*)pop(stack);
		if(node!=NULL){
			printf("%03d ",node->value);
			push(stack,node);
			push(stack,node->leftChild);
		}else{
			if(isEmptyS(stack)){
				break;
			}
			node =(Node*) pop(stack);
			push(stack,node->rightChild);
			if(i%ITEMS_PER_LINE==ITEMS_PER_LINE-1)
				printf("\n");
			i++;
		}
	}
	printf("\n");
	free(stack);
}

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
			printf("\nThe node with value [%03d] points to 0x%x on the left and 0x%x on the right\n",node->value,node->leftChild,node->rightChild);
			push(stack,node->rightChild);
		}

	}
	printf("\n");
	free(stack);
}

