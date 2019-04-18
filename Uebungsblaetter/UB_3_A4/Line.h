/*
 * Line.h
 *
 *  Created on: 18.04.2019
 *      Author: swt
 */

#ifndef LINE_H_
#define LINE_H_
#include "Point.h"

class Line {
public:
	Line();
	explicit Line(Point start, Point stop);
	virtual ~Line();
	Point get_start();
	Point get_end();
	void operator+=(Point &other);
	bool operator==(Line &other);

private:
	Point _start;
	Point _end;
};

#endif /* LINE_H_ */
