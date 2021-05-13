/*
 * hashtable.h
 *
 *  Created on: 2021-05-10
 *      Author: @v-barros
 */

#ifndef ABSTRACTDATATYPES_HASHTABLE_HASHTABLE_H_
#define ABSTRACTDATATYPES_HASHTABLE_HASHTABLE_H_
#define TABLE_SIZE 100
#include <stdint.h>

struct Node{
	unsigned long hash;
	const char * key;
	const char * value;
	struct Node * next;
};
typedef struct Node Node;

struct Table{
	uint32_t tableSize;
	uint32_t numberOfEntries;
	Node * table[TABLE_SIZE];
};
typedef struct Table Table;

Table * createTable();

Node* createNode(const char * key, const char * value, unsigned long hash);
/*
* Checks wheter a key exists or not on the table, if it does, then returns node on linked list, else, returns NULL. 
*/
Node* checkKey(Node * node,unsigned const char * key, unsigned long fullHash);

unsigned long hashGenerate(unsigned const char * str);

uint32_t hashValidate(unsigned long fullHash);

const char * getValue(Table * table,const char * key);

const char * put(Table * table,const char * key, const char * value);

int containsKey(Table * table,const char * key);

int containsValue(Table * table,const char * value);

int removeFromKey(Table * table,const char * key);

#endif /* ABSTRACTDATATYPES_HASHTABLE_HASHTABLE_H_ */