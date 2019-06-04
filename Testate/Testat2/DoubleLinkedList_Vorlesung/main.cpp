/*
 * main.cpp
 *
 *  Created on: 26.05.2019
 *      Author: swt
 */

#include "DoubleLinkedList.h"

int main()
{
	DoubleLinkedList<char> lis;
//	lis.push_back('a');
//	lis.push_back('b');
	lis.push_front('a');
	lis.push_front('b');
	lis.push_back('c');
	for(char val : lis)
			cout << val << " ";
	cout << endl;
	return 0;
}


