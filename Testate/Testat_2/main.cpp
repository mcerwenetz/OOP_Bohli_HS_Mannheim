/*
 * main.c
 *
 *  Created on: 22.05.2019
 *      Author: swt
 */

#include <iostream>
#include "List.h"

using namespace std;

int main()
{
	List liste(3);
	cout << liste.size() << endl;
	liste.remove_all(3);
	cout << liste.size() << endl;

	return 0;
}


