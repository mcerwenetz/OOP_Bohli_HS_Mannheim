/*
 * Person.h
 *
 *  Created on: 03.04.2019
 *      Author: swt
 */

#ifndef PERSON_H_
#define PERSON_H_
#include <iostream>
#include "Punkte.h"

class Person {
private:
	const int _id;
	std::string _name;
	Punkte _punkte;
public:
	Person(int id, const std::string &name, int p=0)
		: _id(id), _name(name), _punkte(p)
	{

	}
	Person()
	: _id(0), _punkte(0)
	{
		_name = "nobody";
	}
	Person(int id)
	: Person(id, "nobody", 17)
	{

	}
	//int id() {return _id;}
	//std::string name() { return _name;}
	//Punkte &punkte(){return _punkte;}
};

#endif /* PERSON_H_ */
