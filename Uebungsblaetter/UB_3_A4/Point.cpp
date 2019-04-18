/*
 * Point.cpp
 *
 *  Created on: 18.04.2019
 *      Author: swt
 */

#include "Point.h"

Point::Point() {
	// TODO Auto-generated constructor stub
	_x=0;
	_y=0;
}

Point::Point(int x, int y)
{
	_x=x;
	_y=y;
}

Point::~Point() {
	// TODO Auto-generated destructor stub
}

int Point::get_x()
{
	return _x;
}

int Point::get_y()
{
	return _y;
}

void Point::operator+=(Point &other)
{
	this->_x+=other.get_x();
	this->_y+=other.get_y();
}

bool Point::operator==(Point &other)
{
	if(_x==other._x && _y == other._y)
	{
		return 1;
	}
	else
		return 0;
}
