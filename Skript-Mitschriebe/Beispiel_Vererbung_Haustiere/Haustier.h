/*
 * Haustier.h
 *
 *  Created on: 04.06.2019
 *      Author: swt
 */

#ifndef HAUSTIER_H_
#define HAUSTIER_H_

#include <iostream>

namespace std {

class Haustier {
public:
	Haustier(const string &name) : _name(name){};
	virtual ~Haustier(){};
	string name(){return _name;}
	virtual string gibLaut() const {return "#";}

private:
	string _name;
};

} /* namespace std */

#endif /* HAUSTIER_H_ */
