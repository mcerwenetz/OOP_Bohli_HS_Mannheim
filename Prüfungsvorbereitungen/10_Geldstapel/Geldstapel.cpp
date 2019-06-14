/*
 * Geldstapel.cpp
 *
 *  Created on: 14.06.2019
 *      Author: swt
 */

#include <iostream>

class Geldstapel
{
	//Konstanten an die erste Stelle
	const double schein_dicke=(0.15/1000);
	int schein_wert;
	int anzahl;
	double height;
public:
	Geldstapel(int _betrag, int _schein_wert)
	: schein_wert(_schein_wert),
	  anzahl(_betrag/_schein_wert),
	  height(anzahl*schein_dicke)
	{}
double get_height(){return height;}
};

int main()
{
	Geldstapel s(1000000, 10);
}


