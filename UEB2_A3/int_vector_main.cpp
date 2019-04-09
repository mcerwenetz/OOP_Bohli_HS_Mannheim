/*
 * int_vector_main.cpp
 *
 *  Created on: 01.04.2019
 *      Author: swt
 */

#include "IntVector.h"
#include "ooptool.h"
#include <iostream>
#include <cstring>

using namespace std;
void klappt();
void crash();

int main(int argc, const char* argv[])
{
/*
if(argc == 2 && strcmp(argv[1],"--crash")==0)
	{
		//crash();
	}
klappt();
*/

IntVector c(5),d(7);
cout << "c";
c.out();
cout << "d";
d.out();
c=d;
cout << "new c";
c.out();



}
void klappt()
{
	IntVector a(17);
	cout << "Ausgabe vorher" << endl;
	a.out();
	for(int i =0 ; i <a.getLaenge() ; i++)
	{
		if(i%2==0)
		{
			a.at(i)+=42;
		}
	}
	cout << "Ausgabe nachher" << endl;
	a.out();
}

void crash()
{
	IntVector b(17);
		//int* setthis = new int[17]{1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17};
		//b.setZahlenarray(setthis);
	b.at(42);
	cout << "crash wurde aufgerufen" ;
}
