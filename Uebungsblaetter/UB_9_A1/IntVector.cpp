/*
 * IntVector.cpp
 *
 *  Created on: 01.04.2019
 *      Author: swt
 */

#include "IntVector.h"
#include <vector>
#include <iostream>
#include <stdexcept>
#include <time.h>

IntVector::IntVector(size_t laenge) {
	setLaenge(laenge);
	_zahlenarray=new int[_laenge];
	//int* zahlenvector = new int[getLaenge()]{1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17};
	//setZahlenarray(zahlenvector);
	normalize();
}

IntVector::~IntVector() {
	delete []_zahlenarray;
}

void IntVector::normalize()
{
	srand(time(NULL));
	for(int i=0; i < getLaenge(); i++)
	{
		_zahlenarray[i]=rand()%10;
	}
}

void IntVector::out()
	{
		for(int i=0; i < getLaenge(); i++)
		{
			std::cout << "i:" << i  << " " << _zahlenarray[i] << std::endl;
		}
}

int& IntVector::at(int idx)
{
	//Indexe starten bei null, at fragt position ab, die bei ein startet
	if(idx <= getLaenge())
	{
		return((_zahlenarray[idx]));
	}
	else
	{
		throw std::invalid_argument("Index nicht vorhanden");
	}
}

IntVector &IntVector::operator=(const IntVector& anderervector)
{
	delete[] _zahlenarray;
	_laenge=anderervector.getLaenge();
	_zahlenarray=new int[_laenge];
	_zahlenarray=anderervector.getZahlenarray();
	//~anderervector;
	return *this;
}

int& IntVector::operator[](int idx)
{
	if(idx <= getLaenge())
	{
		return((_zahlenarray[idx]));
	}
	else
	{
		throw std::invalid_argument("Index nicht vorhanden");
	}
}

