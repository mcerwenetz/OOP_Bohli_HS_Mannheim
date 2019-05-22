/*
 * Studi.cpp
 *
 *  Created on: 22.05.2019
 *      Author: swt
 */

#include "Studi.h"

Studi::Studi() {
	// TODO Auto-generated constructor stub

}

Studi::~Studi() {
	// TODO Auto-generated destructor stub
}

void student_einlesen(ifstream datei, Studi Student)
{

}

int get_number_of_lines(ifstream & datei)
{
	int i=1;
	string line;
	while(getline(datei, line))
	{
		i++;
	}
	return i;
}
