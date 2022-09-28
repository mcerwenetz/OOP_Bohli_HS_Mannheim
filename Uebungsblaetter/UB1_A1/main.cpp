/*
 * main.cpp
 *
 *  Created on: 14.03.2019
 *      Author: swt
 */

#include <iostream>
#include <stdio.h>
#include "ooptool.h"

double heron_calc(double heron, double radizent, double accuracy){
	double heron_next = (heron+(radizent/heron))/2;
	if(heron- heron_next < accuracy){
		return heron;
	}
	else
	{
		return heron_calc(heron_next, radizent, accuracy);
	}
}


int main(int argc, const char* argv[])
{
	argsp_t argsp(argc, argv);
	double radizent = argsp.double_pos(0, 10.0);
	double soll_abstand = argsp.double_pos(1, 1e-6);
	double heron = 0.0;

	heron = (1 + radizent) /2;
	heron = heron_calc(heron, radizent, soll_abstand);

	//Ausgabe als float.
	printf("%lf",heron);
	return 0;

}



