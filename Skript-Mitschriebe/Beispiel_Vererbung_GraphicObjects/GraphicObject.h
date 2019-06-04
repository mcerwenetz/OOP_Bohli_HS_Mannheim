/*
 * GraphicObject.h
 *
 *  Created on: 04.06.2019
 *      Author: swt
 */

#ifndef GRAPHICOBJECT_H_
#define GRAPHICOBJECT_H_

#include <iostream>

namespace std {

class GraphicObject {
public:
	virtual ~GraphicObject() { };
	virtual void paint() = 0;
	virtual bool is_in(int x, int y) const = 0;
};

class Square: public GraphicObject
{
public:
	Square(int top, int left, int width){};
	void paint() override;
	bool is_in(int x, int y) const override;
protected:
	int top, left, width;
};

class Circle : public GraphicObject
{
public:
	Circle(int x, int y, int r):center_x(x),center_y(y),radius(r){};
	void paint() override {};
	bool is_in(int x, int y) const override {return 0;};
protected:
	int center_x, center_y, radius;
};


} /* namespace std */

#endif /* GRAPHICOBJECT_H_ */
