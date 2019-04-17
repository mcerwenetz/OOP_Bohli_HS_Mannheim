/*
 * main.cpp
 *
 *  Created on: 20.03.2019
 *      Author: swt
 */

#include "at.h"
#include <iostream>
using namespace std;

int &at(int *vec, int len, int i)
{
	if(i < len)
	{
		return (vec[i]);
	}else
	{
		throw runtime_error("index overflow");
	}

}
