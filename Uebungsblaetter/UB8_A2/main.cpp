/*
 * main.cpp
 *
 *  Created on: 22.05.2019
 *      Author: swt
 */


#include "Studi.h"
#include "Studi.cpp"

#include <vector>

using namespace std;


int main()
{
	ifstream datei;
	datei.open("studis.txt");

	int linenumbers = get_number_of_lines(datei);
//	Studi tmp;
//
//	vector<Studi>Studenten;

	return 0;
}

