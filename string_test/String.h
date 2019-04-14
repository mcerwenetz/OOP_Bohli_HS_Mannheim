/*
 * String.h
 *
 *  Created on: 03.04.2019
 *      Author: swt
 */

#ifndef STRING_H_
#define STRING_H_

class String {
private:
	char* _s;
	int _length;
public:
	String(const char *c);
	virtual ~String();
	String &operator=(const String &other);
};
void fun();
void morefun();
#endif /* STRING_H_ */
