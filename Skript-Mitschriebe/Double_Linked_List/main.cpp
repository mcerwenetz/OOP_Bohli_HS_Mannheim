/*
 * main.cpp
 *
 *  Created on: 29.06.2019
 *      Author: swt
 */

#include "DoubleLinkedList.h"
#include <iostream>
#include <ios>

using namespace std;

int main()
{

	DoubleLinkedList<char> a;
	for(int i=0; i < 10; i++)
	{
		a.push_back(static_cast<char>(i+97));
	}
	a.remove_ele('a');
	a.show();

}
