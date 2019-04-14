/*
 * Noisy.h
 *
 *  Created on: 03.04.2019
 *      Author: swt
 */

#ifndef NOISY_H_
#define NOISY_H_

#include <iostream>
static int ids=0;
using namespace std;

class Noisy {
public:
	Noisy(const char *s)
	: _id(++ids), _name(s)
	{
		cout << "Erstellt(" << _id << ", "<< _name << ")" << endl;
	}
	Noisy()
	: _id(++ids)
	{
		cout << "Erstellt(" << _id << ", " << " namenlos)" << endl;
	}
	virtual ~Noisy()
	{
		cout << "Zerstört(" << _id << ", "<< _name << ")" << endl;
	}
private:
	int _id;
	string _name;
};

//Noisy global("global");
void f()
{
	static Noisy statisch("static");
}
void g()
{
	static Noisy a("a"),b("b");
}
#endif /* NOISY_H_ */
