/*
 * main.c
 *
 *  Created on: 06.05.2019
 *      Author: swt
 */


#include "Max.h"
#include <iostream>
#include <string>

using namespace std;

int main()
{
	int len=5;
	int* integerarry= new int[len]{1,2,3,4,5};
	int integer_ergebnis;
	integer_ergebnis= max(integerarry,len);

	char* chararray = new char[len]{'a','b','c','d','A'};
	char char_ergebnis;
	char_ergebnis=max(chararray,len);

	string* stringarray = new string[len]{"Hallo","General","Kenobi","Hello","There"};
	string string_ergebnis;
	string_ergebnis=max(stringarray,len);

	return 0;
}

