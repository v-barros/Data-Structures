/*
 * string.h
 *
 *  Created on: 2021-05-18
 *      Author: @v-barros
 */
#ifndef STRING_H
#define STRIG_H


struct String{
	unsigned long hash;
	const char * str;
	struct String * next;
};
typedef struct String String;

String * literal(const char * str);

String * newString(const char * str);

String * intern(String *);

#endif