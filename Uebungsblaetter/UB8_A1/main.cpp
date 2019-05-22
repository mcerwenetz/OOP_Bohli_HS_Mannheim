/*
 * main.cpp
 *
 *  Created on: 20.05.2019
 *      Author: swt
 */

#include <iostream>
#include "Sequence.h"

using namespace std;

int main()
{
	Sequence<int> Liste(1);
	int i;
	while(Liste.capacity() != 100)
	{
		Liste.push_back(17);
		i++;
	}
	cout << i << endl;
	return 0;
}
