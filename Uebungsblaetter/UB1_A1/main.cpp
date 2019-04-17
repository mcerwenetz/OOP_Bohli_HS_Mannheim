/*
 * main.cpp
 *
 *  Created on: 14.03.2019
 *      Author: swt
 */

#include <iostream>
#include <stdio.h>


int main(int argc, char* argv[])
{
	//Deklaration
	double soll_abstand, radizent,heron;
	double heron_plus_one=1;
	/*abstand wird auf 1 gesetzt, damit die Schleife überhaup durchläuft.
	 * Bessere Lösung wäre eine do_while Schleife. Aber es geht auch so.
	 */
	double abstand = 1;

	//Radizent ist die Zahl aus der die Wurzel gezogen wird
	radizent=atof(argv[1]);
	//Abstand wird automatisch auf 10^-6 gestellt, sollte er nicht mit angegeben sein.
	if(argc < 2)
	{
		soll_abstand=1e-06;
	}
	else
	{
		soll_abstand=atof(argv[2]);
	}
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

