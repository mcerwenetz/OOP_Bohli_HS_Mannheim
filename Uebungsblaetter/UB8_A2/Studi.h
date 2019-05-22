/*
 * Studi.h
 *
 *  Created on: 22.05.2019
 *      Author: swt
 */

#ifndef STUDI_H_
#define STUDI_H_
#include <iostream>
#include <fstream>
using namespace std;

class Studi {
public:
	Studi();
	virtual ~Studi();

private:
	long matnr;
	string vorname;
	string nachname;
};

#endif /* STUDI_H_ */
