/*
 * main.cpp
 *
 *  Created on: 03.04.2019
 *      Author: swt
 */
#include <iostream>
#include "Date.h"

using namespace std;
int main()
{
	//Date fullyear[2] = {{1,1,1},{2,2,2}};
	const Date epoch (1,1,1990);
	cout << epoch.day() << "." << epoch.month() << "." <<epoch.year() << endl;
	//epoch.add_day(1);
	//cout << epoch.day() << "." << epoch.month() << "." <<epoch.year() << endl;
}
