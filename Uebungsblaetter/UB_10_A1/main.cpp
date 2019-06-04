/*
 * main.cpp
 *
 *  Created on: 03.06.2019
 *      Author: swt
 */



#include <iostream>
#include "Resistor.h"

using namespace std;

int main()
{
Resistor R1(10);
Resistor R2(10);
Serial Serial1(R1, R2);
cout << Serial1.getvalue() << endl;
Paralel Para1(R1,R2);
cout << Para1.getvalue() << endl;
}
