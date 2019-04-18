/*
 * Point.h
 *
 *  Created on: 18.04.2019
 *      Author: swt
 */

#ifndef POINT_H_
#define POINT_H_

class Point {
public:
	Point();
	Point(int x, int y);
	virtual ~Point();
	int get_x();
	int get_y();
	void operator+=(Point &other);
	bool operator==(Point &other);
private:
int _x;
int _y;

};

#endif /* POINT_H_ */
