/*
 * Bruch.cpp
 *
 *  Created on: 10.04.2019
 *      Author: swt
 */

#include "Bruch.h"
#include "math.h"
#include <iostream>

Bruch::Bruch(int zahl) {
	setNenner(1);
	setZaehler(zahl);
}
Bruch::Bruch(int zaehler, int nenner)
{
	setZaehler(zaehler);
	setNenner(nenner);
	normalize();
}

Bruch::~Bruch() {
	// TODO Auto-generated destructor stub
}

void Bruch::normalize()
{
	if(_nenner <0)
	{
		_nenner=_nenner*(-1);
		_zaehler=zaehler()*(-1);

	}
	int ggt=ggT(_zaehler, _nenner);
	setNenner(_nenner/ggt);
	setZaehler(_zaehler/ggt);
}

void Bruch::operator*=(Bruch b)
{
	_zaehler=_zaehler*(b.zaehler());
	_nenner=_nenner*(b.nenner());
	normalize();
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

Bruch operator*(Bruch a, Bruch b)
{
	Bruch erg(0,1);
	erg.setZaehler(a.zaehler()*b.zaehler());
	erg.setNenner(a.nenner()*b.nenner());
	erg.normalize();
	return erg;
}

int ggT(int a, int b)
{
	while (a!=0)
	{
		std::swap(a,b);
		a%=b;
	}
	return b;
}
