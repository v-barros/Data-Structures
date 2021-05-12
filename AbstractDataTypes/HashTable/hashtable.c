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

Node* getNode(Table * table,unsigned long hash);

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
	if(node==NULL)
		return "";
	do{
		if(!strcmp(node->key,key)){
			return node->value;
		}
		node=node->next;
	}while(node!=NULL);
	return "";
}

const char * put(Table * table,const char * key, const char * value){
	unsigned long fullHash = hashGenerate(key);
	uint32_t i = hashValidate(fullHash);
	Node * node = *(table->table+i);
	char * k_ptr =(char*) malloc(sizeof(key));
	char * v_ptr =(char*) malloc(sizeof(value));
	strcpy(k_ptr,key);
	strcpy(v_ptr,value);

	Node * newNode = (Node*)createNode(k_ptr, v_ptr, fullHash);

	if(node==NULL){
		*(table->table+i)=newNode;
		return v_ptr;
	}else{
		while(node->next){
			node=node->next;
		}
		node->next=newNode;
		return v_ptr;
	}
	return "";
}

int containsKey(Table * table,const char * key);

int containsValue(Table * table,const char * value);

int removeFromKey(Table * table,const char * key);
