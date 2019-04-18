/*
 * Line.cpp
 *
 *  Created on: 18.04.2019
 *      Author: swt
 */

#include "Line.h"

Line::Line() {
	// TODO Auto-generated constructor stub
	_start=Point();
	_end=Point();
}

Line::Line(Point start, Point end)
{
	_start=start;
	_end=end;
}

Line::~Line() {
	// TODO Auto-generated destructor stub
}

Point Line::get_start()
{
	return _start;
}
Point Line::get_end()
{
	return _end;
}

void Line::operator+=(Point &other)
{
	_start+=other;
	_end+=other;

}

bool Line::operator==(Line &other)
{
	if((_start==other._start)&&(_end==other._end))
		return 1;
	else
		return 0;
}
