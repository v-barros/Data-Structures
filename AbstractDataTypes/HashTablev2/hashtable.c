/*
 * hashtable.c
 *
 *  Created on: 2021-05-18
 *      Author: @v-barros
 * 
 * Simplified and better-than-v1 implementation of hashtable, based on pydict: https://github.com/python/cpython/blob/main/Objects/dictobject.c,
 * hostpot openjdk symbol table: http://hg.openjdk.java.net/jdk8/jdk8/hotspot/file/87ee5ee27509/src/share/vm/classfile/symbolTable.hpp
 * and java HashMap: https://docs.oracle.com/javase/8/docs/api/java/util/HashMap.html
 * 
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "hashtable.h"




/**
 * Must receive the first node of a bucket in table->table array.
 * If node is NULL, return NULL.
 * Checks wheter a key exists or not on a bucket, if it does, then returns the previous node on the bucket,
 * else, returns the last node found on the bucket.
 * */
String* lookupAndGetPrevious(String *strNode, const char * key, unsigned long fullHash);

/**
 * Must receive the first node of a bucket in table->table array.
 * If node is NULL, return NULL.
 * Checks wheter a key exists or not on a bucket, if it does, then returns the node that holds the key,
 * else, NULL.
 * */
String* lookup(String * strNode, const char * key, unsigned long fullHash);

/* DJB2. See: https://theartincode.stanis.me/008-djb2/ */
unsigned long hashGenerate(const char * str);

/**
 * Bucket verification
 * */
uint32_t hashValidate(unsigned long fullHash);

Table * createTable(){
	Table t = (Table*) malloc(sizeof(Table));
	
	if(t!=NULL){
		t->tableSize = TABLE_SIZE;
		t->numberOfEntries=0;
		memset(t->table, 0, (t->tableSize)* sizeof(void*) );	
	}
	return t;
}

String *createNode(const char * key, const char * value, unsigned long hash){
	Node * n = (Node*) malloc(sizeof(Node));
	if(n!=NULL){
		n->key = key;
		n->value = value;
		n->hash = hash;
		n->next = NULL;
	}
	return n;
}

String* lookupAndGetPrevious(String *strNode, const char * key, unsigned long fullHash){	
	if(strNode==NULL)
		return NULL;
	String * previous = strNode;
	do{
		if(!(strNode->hash^fullHash)){
			/*
			*	It is kind of redundant, but considering there might be hundreds of nodes 
			*	in a single position on table and comparison using integers is faster than using strings, 
			*   with this aproach we can compare only a few strings even on worst case scenario.
			*/
			if(!(strcmp(strNode->str,key)))
				return previous;
		}
		previous = strNode;
		strNode=strNode->next;
	}while(strNode!=NULL);
	/**
	 * 	If it gets here, there is no equal key on this bucket, 
	 * 	but we don't want to iterate through it again on caller method,
	 * 	so we return the last node we found.
	 * */
	return previous;
}

String * lookup(String* strNode, const char * key, unsigned long fullHash){	
	if(strNode==NULL)
		return NULL;
	
	do{
		if(!(strNode->hash^fullHash)){
			/*
			*	It is kind of redundant, but considering there might be hundreds of nodes 
			*	in a single position on table and comparison using integers is faster than using strings, 
			*   with this aproach we can compare only a few strings even on worst case scenario.
			*/
			if(!(strcmp(strNode->str,key)))
				return strNode;
		}
		strNode=strNode->next;
	}while(strNode!=NULL);
	
	/* reached end of bucket*/
	return NULL;
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

int tableSize(Table * table){
	return table->tableSize;
}

int numberOfEntries(Table * table){
	return table->numberOfEntries;
}

void debugTable(Table * table ){
	int i =0;
	while(i<table->tableSize){
		printf("0x%p ",*(table->table+i++));
	}
}