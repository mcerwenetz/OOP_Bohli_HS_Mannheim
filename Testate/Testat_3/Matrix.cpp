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

Matrix::Matrix(int zahl){
	_zeilen=1;
	_spalten=1;
	_vec=new int[1];
	*(_vec)=zahl;
}

Matrix::Matrix(int zeilenanzahl , int spaltenanzahl) {
	_zeilen=zeilenanzahl;
	_spalten=spaltenanzahl;
	_vec=new int[spaltenanzahl*zeilenanzahl];
	for(int i=0; i < (zeilenanzahl*spaltenanzahl); i++)
	{
		_vec[i]=0;
	}
}

Matrix::Matrix(int* vector, int zeilenanzahl, int spaltenanzahl) {
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

Matrix& Matrix::operator=(const Matrix &other) {
	_zeilen=other._zeilen;
	_spalten=other._spalten;
	int* vektor=new int[other._zeilen * other._spalten];
	for(int i =0; i < (other._zeilen * other._spalten); i++)
	{
		*(vektor+i)=*(other._vec+i);
	}
	delete[] _vec;
	_vec=vektor;
	return *this;
}

void Matrix::out() {
	for(int i = 0 ; i < _zeilen; i++)
	{
		cout << endl;
		for(int j =0 ; j < _spalten; j++)
			cout  << *(_vec+(i*_spalten+j)) << " ";
	}
}

void matrix_einlesen(int* vektor, int zeilenanzahl, int spaltenanzahl) {
	//int einlesewert;
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


Matrix Matrix::operator +(Matrix& other) {
	Matrix erg(_zeilen,_spalten);


	if(other._spalten==1 && other._zeilen==1)
	{
		for(int i=0; i<(_zeilen*_spalten); i++)
		{
			erg._vec[i]=_vec[i]*(*other._vec);
		}
		return erg;
	}
	else if(other._spalten != _spalten || other._zeilen != _zeilen)
	{
		throw runtime_error("Addition nicht möglich. Unterschiedliche Dimension");
	}
	else
	{
		for(int i=0; i<(_zeilen*_spalten); i++)
		{
			erg._vec[i]=_vec[i]+other._vec[i];
		}
		return erg;
	}
}

Matrix Matrix::operator -(Matrix& other) {
	Matrix erg(_zeilen,_spalten);


	if(other._spalten==1 && other._zeilen==1)
	{
		for(int i=0; i<(_zeilen*_spalten); i++)
		{
			erg._vec[i]=_vec[i]/(*other._vec);
		}
		return erg;
	}
	else if(other._spalten != _spalten || other._zeilen != _zeilen)
	{
		throw runtime_error("Addition nicht möglich. Unterschiedliche Dimension");
	}
	else
	{
		for(int i=0; i<(_zeilen*_spalten); i++)
		{
			erg._vec[i]=_vec[i]-other._vec[i];
		}
		return erg;
	}
}

Matrix Matrix::operator* (Matrix &other){
	if(_spalten != other._zeilen)
	{
		throw runtime_error("Falsche Dimension. Kann kein Kreuzprodukt ausführen.");
	}
	else
	{
		Matrix erg(_zeilen,other._spalten);
		for(int i=0; i < erg._zeilen; i++)
		{
			for(int j=0; j < erg._spalten; j++)
			{
				for(int k=0; k < _spalten; k++)
				{
					//erg._vec[i][j]+=_vec[i][k]*other._vec[k][j];
					*(erg._vec+i*erg._spalten+j)+=(*(_vec+i*_spalten+k))*(*(other._vec+k*other._spalten+j));
				}
			}
		}
		return erg;
	}
}

int Matrix::at(int zeile, int spalte) {
	if(zeile >_zeilen  || spalte > _spalten || zeile <=0 || spalte <= 0)
		throw runtime_error("Position nicht gefunden");
	else{
	zeile--;
	spalte--;
	return(*(_vec+zeile*_spalten+spalte));
	//return _vec[zeile][spalte];
	}
}

int* Matrix::p_at(int zeile, int spalte) {
	if(zeile >_zeilen  || spalte > _spalten || zeile <=0 || spalte <= 0)
			throw runtime_error("Position nicht gefunden");
	else{
		zeile--;
		spalte--;
		return(_vec+((zeile*_spalten)+spalte));
	}
}

void Matrix::fun(int a) {
	for(int i=0; i < _zeilen; i++)
	{
		for(int j=0; j < _spalten; j++)
		{
			if(i==j)
			{
				*(_vec+i*_spalten+j)*=a;
			}
		}
	}
}
