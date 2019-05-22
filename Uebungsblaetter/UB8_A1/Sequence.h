/*
 * Sequence.h
 *
 *  Created on: 20.05.2019
 *      Author: swt
 */

#ifndef SEQUENCE_H_
#define SEQUENCE_H_

#include <iostream>

using namespace std;

template<typename T> class Sequence {
public:
	Sequence(size_t cap);
	Sequence(const Sequence &);
	Sequence &operator=(const Sequence &);
	virtual ~Sequence();

	size_t size() const;
	size_t capacity() const;
	bool is_empty() const;
	bool is_full() const;
	T &operator[](size_t position);
	const T &operator[](size_t position) const;
	void insert(size_t position, const T &element);
	void push_back(const T &element);
	void remove(size_t position);
	bool remove_element(const T &element);
	void resize(size_t newsize);
private:
	T* _array;
	size_t _cap;
	size_t _size;
};

template<typename T> Sequence<T>::Sequence(size_t cap)
:_cap(cap)
{
	_array = new T[_cap];
	_size = 0;
}

template<typename T> Sequence<T>::~Sequence()
{
	delete [] _array;
}

template<typename T> Sequence<T>::Sequence(const Sequence &other)
:_cap(other._cap), _size(other._size)
 {
	_array = new T[_cap];
	for(size_t i=0; i < _size; i++)
	{
		_array[i] = other._array[i];
	}
 }

template<typename T>
Sequence <T>& Sequence<T>::operator =(const Sequence &other)
{
	Sequence tmp(other);
	swap(_cap, tmp._cap);
	swap(_size, tmp._size);
	swap(_array, tmp._array);
	return *this;
}

template<typename T> size_t Sequence<T>::size() const { return _size; }
template<typename T> size_t Sequence<T>::capacity() const { return _cap;}
template<typename T> bool Sequence<T>::is_empty() const { return _size == 0; }
template<typename T> bool Sequence<T>::is_full() const {return _size == _cap;}


template<typename T> T& Sequence<T>::operator[](size_t position)
{
	if(position > size || position < 0)
	{
		throw runtime_error("Stelle nicht vorhanden");
	}
	return _array[position];
}

template<typename T> const T& Sequence<T>::operator[](size_t position) const
{
	if(position > size || position < 0)
		{
			throw runtime_error("Stelle nicht vorhanden");
		}
	return _array;
}

template<typename T> void Sequence<T>::insert(size_t position, const T &element)
{
	if(is_full())
		throw runtime_error("Kein Platz mehr");
	if(position > _size)
		throw runtime_error("Stelle zum einfuegen existiert nicht");
	for(size_t index =_size; index > position; index--)
		_array[index]=_array[index-1];
	_size++;
	_array[position]=element;
}

template<typename T> void Sequence<T>::push_back(const T &element)
{
	insert(_size, element);
	if(this->is_full() && _size != 1)
		resize(_cap*0.5);
	if(this->is_full() && _size == 1)
	{
		resize(_cap);
	}
}

template<typename T> void Sequence<T>::remove(size_t position)
{
	if(position > _size)
		throw runtime_error("Position nicht vorhanden");
	_size--;
	for(size_t index=position; index < _size; index++)
	{
		_array[index]=_array[index++];
	}
}

template<typename T> bool Sequence<T>::remove_element(const T &element)
{
	size_t pos = 0;
	while(pos < _size && !(_array[pos]==element))
		pos++;
	if( pos < _size)
	{
		remove(pos);
		return true;
	}
	return false;
}

template<typename T> void Sequence<T>::resize(size_t newsize)
{
	if((newsize+_cap)>_cap)
	{
		T* tmparray = new T[_cap+newsize];
		for(size_t i =0 ; i < _cap; i++)
		{
			tmparray[i]=_array[i];
		}
		delete _array;
		_array=tmparray;
		_cap+=newsize;
	}
}

#endif /* SEQUENCE_H_ */
