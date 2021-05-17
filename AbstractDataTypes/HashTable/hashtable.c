/*
 * hashtable.c
 *
 *  Created on: 2021-05-11
 *      Author: @v-barros
 * 
 * Simplified implementation of hashtable, based on pydict: https://github.com/python/cpython/blob/main/Objects/dictobject.c,
 * hostpot openjdk symbol table: http://hg.openjdk.java.net/jdk8/jdk8/hotspot/file/87ee5ee27509/src/share/vm/classfile/symbolTable.hpp
 * and java HashMap: https://docs.oracle.com/javase/8/docs/api/java/util/HashMap.html
 *  
 * 
 */

#include <stdio.h>
#include <stdlib.h>
#include "hashtable.h"
#include <string.h>

/**
 * Must receive the first node of a bucket in table->table array.
 * If node is NULL, return NULL.
 * Checks wheter a key exists or not on a bucket, if it does, then returns the previous node on linked list,
 * else, returns the last node found on the bucket.
 * */
Node* lookupAndGetPrevious(Node * node, const char * key, unsigned long fullHash);//need to improve this

/* DJB2. See: https://theartincode.stanis.me/008-djb2/ */
unsigned long hashGenerate(const char * str);

/**
 * Bucket verification
 * */
uint32_t hashValidate(unsigned long fullHash);

Table * createTable(){
	Table * t = (Table*) malloc(sizeof(Table));
	
	if(t!=NULL){
		t->tableSize = TABLE_SIZE;
		t->numberOfEntries=0;
		memset(t->table, 0, (t->tableSize)* sizeof(void*) );
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

Node* lookupAndGetPrevious(Node * node, const char * key, unsigned long fullHash){	
	if(node==NULL)
		return NULL;
	Node * previous = node;
	do{
		if(!(node->hash^fullHash)){
			/*
			*	It is kind of redundant, but considering there might be hundreds of nodes 
			*	in a single position on table and comparison using integers is faster than using strings, 
			*   with this aproach we can compare only a few strings even on worst case scenario.
			*/
			if(!(strcmp(node->key,key)))
				return previous;
		}
		previous = node;
		node=node->next;
	}while(node!=NULL);
	/**
	 * 	If it gets here, there is no equal key on this bucket, 
	 * 	but we don't want to iterate through it again on caller method,
	 * 	so we return the last node we found.
	 * */
	return previous;
}

unsigned long hashGenerate(const char * str){
	unsigned long hash = 5381;
	int8_t c;
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
	if(table->numberOfEntries<=0) return 0;
	
	unsigned long fullHash = hashGenerate(key);
	uint32_t i = hashValidate(fullHash);
	Node * node = *(table->table+i);
	Node * checkNode = lookupAndGetPrevious(node,key,fullHash);
	
	if(checkNode==NULL)/*There is no such key on the table */
		return "";
	if(!strcmp(checkNode->key,key))/*The node with thekey  first on table->table[i]*/
		return checkNode->value;
	return checkNode->next->value;
}

const char * put(Table * table,const char * key, const char * value){
	unsigned long fullHash = hashGenerate(key);
	uint32_t i = hashValidate(fullHash);
	Node * node = *(table->table+i);
	Node * newNode;

	node = lookupAndGetPrevious(node,key,fullHash);
	
	
	/**
	 * Alloc only value, because key might exist
	 * */
	char * v_ptr =(char*) malloc(sizeof(value));
	strcpy(v_ptr,value);
	
	if(node==NULL){
		/*That means there is nothing on bucket table->table[i] */
		
		char * k_ptr =(char*) malloc(sizeof(key));
		strcpy(k_ptr,key);
		newNode = (Node*)createNode(k_ptr, v_ptr, fullHash);
		
		*(table->table+i)=newNode;
		table->numberOfEntries++;

	}else if(!(strcmp(node->key,key))){
		/*key is at the first node of the bucket*/
		
		free((char*) node->value);
		node->value = v_ptr;

	}else if(node->next==NULL){ 
		/* That means lookupAndGetPrevious() reached end of bucket, so we assing a newNode to end of list*/
		
		char * k_ptr =(char*) malloc(sizeof(key));
		strcpy(k_ptr,key);
		newNode = (Node*)createNode(k_ptr, v_ptr, fullHash);
						
		node->next=newNode;
		table->numberOfEntries++;
	}else{	
		/* node->next->value is equal value, so we free it and change node->next->value to v_ptr */
				
		free((char*) node->next->value);
		node->next->value = v_ptr;
	}
	return v_ptr;
}

int containsKey(Table * table,const char * key){
	if(table->numberOfEntries<=0)return 0;
	
	unsigned long fullHash = hashGenerate(key);
	uint32_t i = hashValidate(fullHash);
	Node * node = *(table->table+i);
	node = lookupAndGetPrevious(node,key,fullHash);
	
	if(node==NULL)
		return 0;
	
	/**
	 * 	3 possibilities here, ->
	 *  1: key is at the first node of the bucket(table->table[i]);
	 *  2: key is anywhere but the first node(node->next);
	 *  3: there is no such key 
	 * */
	if(!strcmp(key,node->key)){/* case 1*/
		return 1;
	}else if(node->next == NULL){/* case 3*/	
		return 0;
	}else{ /* case 2*/
		return 1;
	}
}

int containsValue(Table * table,const char * value){
	if(table->numberOfEntries<=0)return 0;

	int i ;
	Node * node = table->table[0];

	for(i=1 ; i < table->tableSize ; i++){
		 /* Iterate bucket by bucket*/

		node = *(table->table+i);
		while(node!=NULL){
			/* iterate through nodes on bucket*/

			if(!(strcmp(node->value,value))) 
				return 1;
			node=node->next;
		}
	}
	return 0;
}

int tableSize(Table * table){
	return table->tableSize;
}

int numberOfEntries(Table * table){
	return table->numberOfEntries;
}

int removeByKey(Table * table,const char * key){
	unsigned long fullHash = hashGenerate(key);
	uint32_t i = hashValidate(fullHash);
	Node * nodeToDelete = *(table->table+i);
	Node * checkNode = lookupAndGetPrevious(nodeToDelete,key,fullHash);
	
	if(checkNode==NULL)/* there is no node on this bucket*/
		return 0;
	
	/**
	 * 	3 possibilities here, ->
	 *  1: key is at the first node of the bucket(table->table[i]);
	 *  2: key is anywhere but the first node(checkNode->next);
	 *  3: there is no such key 
	 * */ 
	if(!strcmp(key,checkNode->key)){/* case 1*/
		*(table->table+i) = nodeToDelete->next;
	}else if(checkNode->next == NULL){/* case 3*/	
		return 0;
	}else{ /* case 2*/
		nodeToDelete = checkNode->next;
		checkNode->next=nodeToDelete->next;
	}
	
	free((char *)nodeToDelete->value);
	free(nodeToDelete);
	table->numberOfEntries--;
	return 1;
}

void debugTable(Table * table ){
	int i =0;
	while(i<table->tableSize){
		printf("0x%p ",*(table->table+i++));
	}
}