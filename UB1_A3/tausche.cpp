/*
 * main.cpp
 *
 *  Created on: 18.03.2019
 *      Author: swt
 */

#include <iostream>
#include "tausche.h"

void tausche(int*& p, int*& q)
{
	int* tmp=p;
	p=q;
	q=tmp;
}



