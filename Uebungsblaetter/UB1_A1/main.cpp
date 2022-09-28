/*
 * main.cpp
 *
 *  Created on: 14.03.2019
 *      Author: swt
 */

#include <iostream>
#include <stdio.h>
#include "ooptool.h"


int main(int argc, const char* argv[])
{
	argsp_t argsp(argc, argv);
	double radizent = argsp.double_pos(0, 10.0);
	double soll_abstand = argsp.double_pos(1, 1e-6);
	double abstand = 1.0;
	double heron = 0.0;
	double heron_plus_one=1;

	for(int i=0; abstand > soll_abstand; i++)
	{
		/* Im ersten Durchlauf wird das erste heron-glied noch anders berechnet.
		 * Spätere Heron-Glieder bauen auf dem ersten auf.
		 * Umsetzung als Rekursiver Algorithmus bietet sich hier an. Hatte aber keinen Bock drauf.
		 */
		if(i==0)
		{
			heron=(1+radizent)/2;
		}
		else
		{
			/*
			 * Für spätere Heron-Glieder gilt das dieser Else-Case.
			 * Wichtig ist hier die Reihenfolge:
			 * 1.Heronglied berechnen
			 * 2.Abstand berechnen zum vorherigen berechnen.
			 * 3.Nächstes Heronglied bekommt den Wert des Aktuellen.
			 * Berechnet man zuletzt den Abstand ist dieser immer 0, weil man vom heron-glied einfach das aktuelle heron-glied abzieht.
			 */
			heron=((heron+(radizent/heron))/2);
			abstand=heron_plus_one-heron;
		}
	heron_plus_one=heron;
	}
	//Ausgabe als float.
	printf("%lf",heron);
	return 0;
}

