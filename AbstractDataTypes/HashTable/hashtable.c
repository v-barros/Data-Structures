/*
 * hashtable.c
 *
 *  Created on: 2021-05-11
 *      Author: @v-barros
 */

#include <stdio.h>
#include <stdlib.h>
#include "hashtable.h"
#include <string.h>

Table * createTable(){
	Table * t = (Table*) malloc(sizeof(Table));
	if(t!=NULL){
		if(t->table!=NULL){
			t->tableSize = TABLE_SIZE;
			t->numberOfEntries=0;
		}else{
			printf("NULL");
			return NULL;
		}
	}
	return t;
}

Node* createNode(const char * key, const char * value, unsigned long hash){
	Node * n = (Node*) malloc(sizeof(Node));
	if(n!=NULL){
		n->key = key;
		n->value = value;
		n->hash = hash;
		n->next = NULL;
	}
	return n;
}

Node* checkKey(Node * node ,unsigned const char * key, unsigned long fullHash){
	
	if(node==NULL)
		return NULL;
	do{
		if(!(node->hash^fullHash)){
			/*	It is kind of redundant, but considering there might be hundreds of nodes 
			*	in a single position on table and comparison using integers is faster than using strings, 
			*   with this aproach we can compare only a few strings even on worst case scenario.
			*	On the other hand, its slower in cases where the bucket is not so populated.
			*/
			if(!(strcmp(node->key,key)))
				return node;
		}
		node=node->next;
	}while(node!=NULL);
	return NULL;
}

/* DJB2*/
unsigned long hashGenerate(unsigned const char * str){
	unsigned long hash = 5381;
	int32_t c;
	while (c = *str++)
		hash = ((hash << 5) + hash) + c; /* hash * 33 + c */
	return hash;
}

uint32_t hashValidate(unsigned long fullHash){
	int32_t h = fullHash % TABLE_SIZE;
	if(!(h >= 0 && h < TABLE_SIZE))
		printf("Illegal hash value");
	return h;
}

const char * getValue(Table * table,const char * key){
	unsigned long fullHash = hashGenerate(key);
	uint32_t i = hashValidate(fullHash);
	Node * node = *(table->table+i);
	Node * checkNode = checkKey(node,key,fullHash);
	
	if(checkNode==NULL)
		return "";
	return node->value;
}

const char * put(Table * table,const char * key, const char * value){
	unsigned long fullHash = hashGenerate(key);
	uint32_t i = hashValidate(fullHash);
	Node * node = *(table->table+i);
	Node * newNode = checkKey(node,key,fullHash);

	/**
	 * Alloc only value, because key might exist
	*/
	char * v_ptr =(char*) malloc(sizeof(value));
	strcpy(v_ptr,value);

	/*If the newNode is NULL, we create a new structure to allocate key and value */
	if(newNode==NULL){
		char * k_ptr =(char*) malloc(sizeof(key));
		strcpy(k_ptr,key);
		
		newNode = (Node*)createNode(k_ptr, v_ptr, fullHash);
		if(node==NULL){
			*(table->table+i)=newNode;
		}else{
			/**
			 * This is O(n*2), need to improve 
			 */
			while(node->next){
				node=node->next;
			}
			node->next=newNode;
		}
	}else{
		free((char*)newNode->value);
		newNode->value=v_ptr;	
	}
	return v_ptr;

}

int containsKey(Table * table,const char * key);

int containsValue(Table * table,const char * value);

int removeFromKey(Table * table,const char * key);
