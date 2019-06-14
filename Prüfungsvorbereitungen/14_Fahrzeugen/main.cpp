/*
 * main.cpp
 *
 *  Created on: 14.06.2019
 *      Author: swt
 */




#include "Fahrzeug.h"
#include <list>

using namespace std;
int main()
{
	Traktor t1, t2;
	Rennwagen r1,r2;
	list<Fahrzeug *> Fahrzeugliste{&t1,&t2,&r1,&r2};
	for(auto it:Fahrzeugliste)
	{
		it->fahren();
	}

}
