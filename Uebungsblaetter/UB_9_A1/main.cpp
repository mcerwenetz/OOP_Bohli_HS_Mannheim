/*
 * main.cpp
 *
 *  Created on: 26.05.2019
 *      Author: swt
 */

#include "IntVector.h"
#include <iostream>

using namespace std;

int main()
{
	int anfang, ende;
	anfang = 1;
	ende = 10000;
	IntVector inti(ende);
	int summe=0;
	for(auto it = inti.begin(); it != inti.end(); ++it)
	{
		*it = anfang;
		anfang++;
	}
	for(auto it = inti.begin(); it != inti.end(); ++it)
	{
		summe+= *it;
	}
	cout << summe;
	return 0;
}
