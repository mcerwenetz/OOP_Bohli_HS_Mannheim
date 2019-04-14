/*
 * Punkte.h
 *
 *  Created on: 03.04.2019
 *      Author: swt
 */

#ifndef PUNKTE_H_
#define PUNKTE_H_

class Punkte {
private:
	int _p;
public:
	Punkte();
	Punkte(int p){_p=p;}
	int &p(){return _p;}
};

#endif /* PUNKTE_H_ */
