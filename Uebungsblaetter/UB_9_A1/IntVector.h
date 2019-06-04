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
	class Iterator
	{
		friend class IntVector;
	public:
		int &operator*()
		{
			return *cur;
		}
		Iterator &operator++(){
			cur+=1;
			return *this;
		}
		bool operator==(const Iterator &other)
		{
			return cur == other.cur;
		}
		bool operator!=(const Iterator &other)
		{
			return cur != other.cur;
		}
	private:
		Iterator(int* cur) :
		cur(cur){}
		int* cur;
	};
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

	Iterator begin()
	{
		return Iterator(_zahlenarray);
	}
	Iterator end()
	{
		return Iterator(_zahlenarray+_laenge);
	}
};
#endif /* INTVECTOR_H_ */
