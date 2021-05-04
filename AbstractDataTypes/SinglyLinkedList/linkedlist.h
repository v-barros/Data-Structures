/*
 * linkedlist.h
 *
 *  Created on: 2021-04-11
 *      Author: vinicius.barros
 */

#ifndef SINGLYLINKEDLIST_H_
#define SINGLYLINKEDLIST_H_


struct Node {
	int value;
	struct Node * next;
};
typedef struct Node Node;

typedef struct {
	int size;
	Node * head;
}LinkedList;

LinkedList * newLinkedList ();

/*  – Insert an element at any position of the list.*/
int insert(LinkedList *,int);

/* – Remove the first occurrence of any element from a non-empty list.*/
int removeFirstOf(LinkedList *,int);

/* – Return the number of elements in the list. */
int size(LinkedList *);

/* – Return true if the list is empty, otherwise return false.*/
int isEmptyT(LinkedList *);

/* - Traverse the list and print the elements  */
void printList(LinkedList *);

#endif /* SINGLYLINKEDLIST_H_ */
