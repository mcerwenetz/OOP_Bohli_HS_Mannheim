/*
 * IntVector.h
 *
 *  Created on: 01.04.2019
 *      Author: swt
 */

#ifndef INTVECTOR_H_
#define INTVECTOR_H_
#include <vector>
class IntVector {
private:
	size_t _laenge;
	int* _zahlenarray;
	void normalize();
public:
	IntVector(size_t laenge);
	IntVector();
	virtual ~IntVector();
	void out();
	int &at(int idx);
	IntVector &operator=(const IntVector& anderervector);
	int& operator[](int idx);
	int* getZahlenarray() const {
		return _zahlenarray;
	}

	void setZahlenarray(int* zahlenarray) {
		_zahlenarray = zahlenarray;
	}

	int getLaenge() const {
		return (_laenge);
	}

	void setLaenge(size_t laenge) {
		_laenge=laenge;
	}
};
#endif /* INTVECTOR_H_ */
