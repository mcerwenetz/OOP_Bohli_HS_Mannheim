/*
 * CommonVector.h
 *
 *  Created on: 12.05.2019
 *      Author: swt
 */

#ifndef COMMONVECTOR_H_
#define COMMONVECTOR_H_

#include <iostream>

using namespace std;

template<typename T, size_t len>
class CommonVector {
public:
	CommonVector();
	virtual ~CommonVector();
	size_t size() const;
	T &operator[](size_t index);
	void out(void) const;
private:
	T* elements;
};

template<typename T, size_t len>
CommonVector<T, len>::CommonVector()
{
	elements = new T[len];
}

template<typename T, size_t len>
CommonVector<T, len>::~CommonVector()
{
	delete[] elements;
}

template<typename T, size_t len>
T& CommonVector<T, len>::operator [](size_t index)
{
	if(index >= len)
	{
		throw runtime_error("index zu groß");
	}
	return elements[index];
}

template<typename T, size_t len>
void CommonVector<T, len>::out(void) const
{
	cout << "[ ";
	for(size_t i=0; i < len; i++)
	{
		if(i>0 && i%10==0)
		{
			cout << endl << " ";
		}
		cout << " "  << elements[i] << " ";
	}
	cout << " ]";
}

#endif /* COMMONVECTOR_H_ */
