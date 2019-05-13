/*
 * main.cpp
 *
 *  Created on: 12.05.2019
 *      Author: swt
 */

#include "CommonVector.h"
#include <cmath>
#include <cstring>

using namespace std;

int main()

{

	// Double Common Vector Teil

//	CommonVector<double, 10> doublevector;
//	for(int i=0; i < 10; i++)
//	{
//		doublevector[i]=pow(i,2);
//	}
//	doublevector.out();
	/*
	CommonVector<char, 25> charvector;
	string tofill = "Hallo tolle C++ Welt";
	for(int i=0; i<25; i++)
	{
		charvector[i]=tofill[i];
	}
	charvector.out();
	*/

	CommonVector<string, 4> stringvector;
	string tofill[4]={"Hallo", "tolle","C++","Welt"};
	for(int i=0; i< 4; i++)
	{
		stringvector[i]=tofill[i];
	}
	stringvector.out();

}



