/*
 * Fahrzeug.h
 *
 *  Created on: 14.06.2019
 *      Author: swt
 */

#ifndef FAHRZEUG_H_
#define FAHRZEUG_H_

#include <iostream>

class Fahrzeug
{
public:
	virtual ~Fahrzeug(){};
	virtual void fahren()=0;
};

class Rennwagen : public Fahrzeug
{
	void fahren() override
	{
		std::cout << "neeeeau" << std::endl;
	}
};

class Traktor : public Fahrzeug
{
	void fahren() override
	{
		std::cout << "Ich bin ein Traktor" << std::endl;
	}
};




#endif /* FAHRZEUG_H_ */
