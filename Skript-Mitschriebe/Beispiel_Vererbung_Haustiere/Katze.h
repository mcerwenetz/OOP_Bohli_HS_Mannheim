/*
 * Katze.h
 *
 *  Created on: 04.06.2019
 *      Author: swt
 */

#ifndef KATZE_H_
#define KATZE_H_
#include <iostream>
#include "Haustier.h"

namespace std {
#include "Haustier.h"

class Katze : public Haustier {
public:
	Katze(const string &name) : Haustier(name){}
	string gibLaut() const override {return "miau";}
	string gibLautBasis() const {
		return Haustier::gibLaut();
	}
};

} /* namespace std */

#endif /* KATZE_H_ */
