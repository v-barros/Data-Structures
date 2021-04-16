/*
 * linkedlist.h
 *
 *  Created on: 2021-04-15
 *      Author: vinicius.barros
 */

#ifndef DOUBLYLINKEDLIST_T_H_
#define DOUBLYLINKEDLIST_H_



struct Node{
	int value;
	struct Node * next;
	struct Node * previous;
};
typedef struct Node Node;

typedef struct {
	int size;
	Node * head;
	Node * last;
}LinkedList;

LinkedList * newLinkedList();

/*  – Insert an element at the beginning of the list.*/
int insertFirst(LinkedList *,int);

/*  – Insert an element at the end of the list.*/
int insertLast(LinkedList *,int);

/* – Remove the first occurrence of any element from a non-empty list.*/
int removeFirstOf(LinkedList *,int);

/* – Remove the last occurrence of any element from a non-empty list.*/
int removeLastOf(LinkedList *,int);

/* – Return the number of elements in the list. */
int size(LinkedList *);

/* – Return true if the 1 is empty, otherwise return 0.*/
int isEmpty(LinkedList *);

/* - Traverse the list and print the elements  */
void printListForwards(LinkedList *);

/* - Traverse the list in backward manner and print the elements  */
void printListBackwards(LinkedList *);

#endif /* DOUBLYLINKEDLIST_H_ */
