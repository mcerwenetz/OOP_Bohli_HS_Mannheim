/*
 * String.cpp
 *
 *  Created on: 03.04.2019
 *      Author: swt
 */

#include "String.h"
#include <cstring>

String::String(const char *c) {
	// TODO Auto-generated constructor stub
	_length=strlen(c);
	_s = new char[_length+1];
	strcpy(_s,c);
}

String::~String() {
	// TODO Auto-generated destructor stub
	delete []_s;
}

String &String::operator=(const String &other)
{
	if(this != &other)
	{
		delete [] _s;
		_length = other._length;
		_s = new char[_length+1];
		strcpy(_s,other._s);
	}
	return *this;
}

void fun()
{
	String string("Hallo");
}

void morefun()
{
	String str("Hallo");
	String zuzuweisen("Welt");
	str=zuzuweisen;
}
