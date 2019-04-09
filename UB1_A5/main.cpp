/*
 * main.cpp
 *
 *  Created on: 20.03.2019
 *      Author: swt
 */

#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
using namespace std;

int main()
{
	ifstream datei;
	string zahl;
	datei.open("textfile.txt");
	while (datei >> zahl) {
	cout << zahl << " ";
	}
	return 0;
}

