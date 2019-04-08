/*
 * time_main.cpp
 *
 *  Created on: 20.03.2019
 *      Author: swt
 */

#include "time.h"
#include <iostream>

int main()
{
	Time zeit;
	zeit.add(0,0,1);
	zeit.add(0,1,1);
	zeit.print_time();
	return 0;
}
