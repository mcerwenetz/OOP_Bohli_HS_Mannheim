/*
 * Matrix.h
 *
 *  Created on: 20.04.2019
 *      Author: swt
 */

#ifndef MATRIX_H_
#define MATRIX_H_

class Matrix {
public:
	Matrix();

	Matrix(int zahl);

	Matrix(int spaltenanzahl, int zeilenanzahl);

	Matrix(int* vector, int spaltenanzahl, int zeilenanzahl);

	Matrix(Matrix& other);

	virtual ~Matrix();


	Matrix& operator= (const Matrix &other);

	Matrix operator+ (Matrix &other);

	Matrix operator- (Matrix &other);

	Matrix operator* (Matrix &other);


	int getSpalten() const {
		return _spalten;
	}

	void setSpalten(int spalten) {
		_spalten = spalten;
	}

	int* getVec() const {
		return _vec;
	}

	void setVec(int* vec) {
		_vec = vec;
	}

	int getZeilen() const {
		return _zeilen;
	}

	void setZeilen(int zeilen) {
		_zeilen = zeilen;
	}


	void out();

	int at(int zeile, int spalte);

	int* p_at(int zeile, int spalte);

	void fun(int a);


private:
	int* _vec;
	int _spalten;
	int _zeilen;
};

void matrix_einlesen(int* vektor, int spaltenanzahl, int zeilenanzahl);

#endif /* MATRIX_H_ */
