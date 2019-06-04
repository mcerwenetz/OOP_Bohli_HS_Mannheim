/*
 * Hund.h
 *
 *  Created on: 04.06.2019
 *      Author: swt
 */

#ifndef HUND_H_
#define HUND_H_

#include "Haustier.h"

namespace std {

class Hund : public Haustier {
public:
	Hund(const string &name, const string &schule) : Haustier(name), _hundeschule(schule){}
	string gibLaut() const override {return "wau";}
	string hundeschule() const {return _hundeschule;}
private:
	string _hundeschule;
};

} /* namespace std */

#endif /* HUND_H_ */
