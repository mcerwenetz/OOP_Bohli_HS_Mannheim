/*
 * Bruch.cpp
 *
 *  Created on: 10.04.2019
 *      Author: swt
 */

#include "Bruch.h"

Bruch::Bruch() {
 this->setNenner(0);
 this->setZaehler(0);
}
Bruch::Bruch(int zahl) {
	setNenner(1);
	setZaehler(zahl);
}
Bruch::Bruch(int zaehler, int nenner)
{
	setZaehler(zaehler);
	setNenner(nenner);
}

Bruch::~Bruch() {
	// TODO Auto-generated destructor stub
}

bool operator==(Bruch a, Bruch b)
{
	if(a.nenner() == b.nenner() and a.zaehler() == b.zaehler())
	{
		return true;
	}
	else return false;
}
bool operator!=(Bruch a, Bruch b)
{
	if(a.nenner() != b.nenner() or a.zaehler() != b.zaehler())
		{
			return true;
		}
	else return false;
}

void operator*=(Bruch a, Bruch b)
{
	a.setNenner(a.nenner()*b.nenner());
	a.setZaehler(a.zaehler()*b.zaehler());
}
Bruch operator*(Bruch a, Bruch b)
{
	Bruch erg;
	erg.setZaehler(a.zaehler()*b.zaehler());
	erg.setNenner(a.nenner()*b.nenner());
	return erg;
}
