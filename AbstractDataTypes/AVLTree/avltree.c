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
#define BALANCE_FACTOR 1

/* Given the tree and the node to be inserted, navigates the tree and add the node.
   Returns a stack containg the path to the new node, example:
				10
			   / \
			  5   15
   If basicAdd() was called with the tree above and a node containing the value 3,
   the node would be added on the left of '5' and the returned stack would look 
   like this: [10,5].
   If the tree is empty, then the node is set as root and the return value is NULL.
*/
Stack * basicAdd(Tree * tree, Node * nodeToAdd);

Node * new_node(int n);
/*
	Given a Stack, checks whether there is an unbalanced node and return 0 if there
	is nothing unbalanced or 1 if there is an unbalanced node, example:
					10
				   	/ \
				   9   11
				  /
			     8
	If we insert a node with value 5 on the tree above, then the stack passed to
	is_unbalanced() will look like this: [10,9,8] and the node 9 would be
	unbalanced, so the return value is 1 and the head of the stack is now the
	unbalanced node, which is 9, so the stack look like this:	
	[10,9].
	If the unbalanced node is the root of the tree, then the stack is empty, but
	return value is still 1;
*/
int is_unbalanced(Stack * stack);

int get_height(Node *node);

void set_height(Node *node);

int max(int x,int y);

void right_rotation(Node * father,Node* son);

void left_rotation(Node * father,Node* son);

int max(int x,int y){
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

int is_unbalanced(Stack * stack){
	assert(stack);
	int aux;
	Node * node;
	while(!isEmptyS(stack)){
		node = pop(stack);
		aux = get_height(node);
		printf("changing height of %d, from %d to ", node->value, aux);
		set_height(node);
		printf("%d\n", get_height(node));
		if(aux != get_height(node)){//balance factor need to be checked here
			if(abs(get_height(node->leftChild) - get_height(node->rightChild)) > BALANCE_FACTOR){ // unbalanced
				printf("unbalanced on node %d, balance factor: %d\n", node->value,get_height(node->leftChild) - (get_height(node->rightChild)));
				push(stack,node);
				return 1;
			}
		}
		else{
			printf("breaking on %d\n\n",node->value);
			return 0;//nothing else to check
		}
	}
	return 0;
}

void right_rotation(Node * father,Node* son){
	father->leftChild = son->rightChild;
	son->rightChild = father;
}

void left_rotation(Node * father,Node* son){
	father->rightChild = son->leftChild;
	son->leftChild = father;
}

Stack * basicAdd(Tree * tree, Node * nodeToAdd){
	Stack * stack = newStack();
	Node * aux;
    int n;
    if(isEmptyT(tree)){
		tree->root = nodeToAdd;
		return NULL;
	}else{
		Node * node = tree->root;
        while(1){
			push(stack,node);
            if(nodeToAdd->value > node->value){//right
                if(node->rightChild == NULL){
                    node->rightChild = nodeToAdd;
                    return stack;
                }else{
                    node = node->rightChild;
                }
            }else{//left
                if(node->leftChild == NULL){
                    node->leftChild = nodeToAdd;
                    return stack;
                }else{
                    node = node->leftChild;
                }
            }
        }
    }
}

Node * new_node(int n){
	Node * newnode = (Node*) malloc (sizeof(Node));
    assert(newnode!=NULL);
    newnode->value = n;
    newnode->leftChild = NULL;
    newnode->rightChild = NULL;
	newnode->height=0;

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
    Stack * navStack = basicAdd(tree,newNode);
	
	tree->size++;
	if(navStack){
   		if(is_unbalanced(navStack)){
			Node * temp = pop(navStack);
			if(get_height(temp->leftChild)-(get_height(temp->rightChild))>0){//left heavy
				Node * temp_left = temp->leftChild;
				right_rotation(temp,temp_left);
				temp = pop(navStack);
				if(temp){//not root
					if(temp->leftChild ==temp_left->rightChild) // moving the parent of the unbalanced subtree to the new root of the subtree, which is temp_left
						temp->leftChild = temp_left;
					else
						temp->rightChild = temp_left;
				}else{ //root was unbalanced
					tree->root = temp_left;
				}

			}else{ //right heavy
				Node * temp_right = temp->rightChild;
				left_rotation(temp,temp_right);
				temp = pop(navStack);
				if(temp){//not root
					if(temp->rightChild ==temp_right->leftChild)// moving the parent of the unbalanced subtree to the new root of the subtree, which is temp_right
						temp->rightChild = temp_right;
					else
						temp->leftChild = temp_right;
				}else{ //root was unbalanced
					tree->root = temp_right;
				}
			}	
		}			
		free(navStack);
	}
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
