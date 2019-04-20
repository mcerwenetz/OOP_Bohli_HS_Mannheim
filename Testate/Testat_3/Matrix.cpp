/*
 * Matrix.cpp
 *
 *  Created on: 20.04.2019
 *      Author: swt
 */

#include "Matrix.h"
#include <iostream>


using namespace std;

Matrix::Matrix() {
	_vec=NULL;
	_spalten=0;
	_zeilen=0;

}

Matrix::~Matrix() {
	delete [] _vec;
}

Matrix::Matrix(int* vector, int spaltenanzahl, int zeilenanzahl) {
	_vec=vector;
	_spalten=spaltenanzahl;
	_zeilen=zeilenanzahl;
}

Matrix::Matrix(Matrix& other) {
	_zeilen=other._zeilen;
	_spalten=other._spalten;
	int* vektor=new int[other._zeilen * other._spalten];
	for(int i =0; i < (other._zeilen * other._spalten); i++)
	{
		*(vektor+i)=*(other._vec+i);
	}
	_vec=vektor;
}

void Matrix::operator=(Matrix& other) {
	_zeilen=other._zeilen;
	_spalten=other._spalten;
	int* vektor=new int[other._zeilen * other._spalten];
	for(int i =0; i < (other._zeilen * other._spalten); i++)
	{
		*(vektor+i)=*(other._vec+i);
	}
	delete[] _vec;
	_vec=vektor;
}

void Matrix::out() {
	for(int i = 0 ; i < _zeilen; i++)
	{
		cout << endl;
		for(int j =0 ; j < _spalten; j++)
			cout  << *(_vec+(i*_spalten+j)) << " ";
	}
}

void matrix_einlesen(int* vektor, int spaltenanzahl, int zeilenanzahl) {
	int einlesewert;
	/*
	for(int i=0; i < zeilenanzahl; i++)
	{
		cout << "Zeile " << i+1 << endl;
		for(int j=0; j < spaltenanzahl; j++)
		{
			cout << "Wert " << j+1 << endl;
			cin >> einlesewert;
			*(vektor+i*spaltenanzahl+j)=einlesewert;
		}
	}
	*/
	cout << "Bitte Zahlen hintereinander engeben" << endl;
	for(int i=0; i < (zeilenanzahl*spaltenanzahl); i++)
	{
		cin >> *(vektor+i);
	}
}

int Matrix::at(int zeile, int spalte) {
	if(zeile >_zeilen  || spalte > _spalten || zeile <=0 || spalte <= 0)
		throw runtime_error("Position nicht gefunden");
	else{
	zeile--;
	spalte--;
	return(*(_vec+zeile*_spalten+spalte));
	}
}
