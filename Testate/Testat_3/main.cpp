/*
 * main.cpp
 *
 *  Created on: 20.04.2019
 *      Author: swt
 */

#include <iostream>
#include "Matrix.h"

using namespace std;

int main()
{
	//Einführungstest
	int spaltenanzahl=2;
	int zeilenanzahl=2;
	//cout << "Spaltenanzahl eingeben:" << endl;
	//cin >> spaltenanzahl;
	//cout << "Zeilenanzahl eingeben:" << endl;
	//cin >> zeilenanzahl;
	int* vektor = new int[zeilenanzahl*spaltenanzahl]{1,2,3,4};
	//matrix_einlesen(vektor, spaltenanzahl, zeilenanzahl);
	Matrix a(vektor, spaltenanzahl, zeilenanzahl);
	//a.out();

	//Kopierkonstruktor Test
	//Matrix b(a);
	//b.out();

	//Zuweisungsoperator Test
	//Matrix b;
	//b=a;
	//b.out();

	//at-Test
	//cout << a.at(2,2);
	}
