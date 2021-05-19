/*
 * hashtable.h
 *
 *  Created on: 2021-05-18
 *      Author: @v-barros
 */

#ifndef ABSTRACTDATATYPES_HASHTABLE_HASHTABLE_H_
#define ABSTRACTDATATYPES_HASHTABLE_HASHTABLE_H_
#define TABLE_SIZE 10
#include <stdint.h>
#include <stdbool.h>
#include "string.h"



struct Table{
	uint32_t tableSize;
	uint32_t numberOfEntries;
	String * table[TABLE_SIZE];
};
typedef struct Table  Table;

/**
 *  Alloc a new table struct with default size defined by TABLE_SIZE macro and return its pointer
 * */
Table  createTable();

/**
 * Lookup for a key on the given table
 * If the key is present, returns its value, else, returns an empty string ""
 * */
const char * getValue(Table * table,const char * key);

/**
 * Given a key and a value, try to insert a new structure on the table
 * If the key already exists, places the new value on the present structure 
 * If it doesnt, creates a new structure to insert key and value
 * Returns the (updated) value passed to the key
 * */
const char * put(Table * table,const char * key, const char * value);



/**
 * Remove a key on the table
 * return 1 if removed sucessfuly, else, return 0 
 * */
bool removeByKey(Table * table,const char * key);

/**
 * Return the number of entries on the table(number of active keys)
 * */
int numberOfEntries(Table * table);

/**
 * Return the table size(number of buckets)
 * */
int tableSize(Table * table);

/**
 *  Prints address of buckets from 0 to tableSize, but it doesnt loop through Buckets
 * */
void debugTable(Table * table );

void rehash(Table *  table);

#endif /* ABSTRACTDATATYPES_HASHTABLE_HASHTABLE_H_ */
