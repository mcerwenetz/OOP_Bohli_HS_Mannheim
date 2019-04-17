/*
 * Bruch.h
 *
 *  Created on: 10.04.2019
 *      Author: swt
 */

#ifndef BRUCH_H_
#define BRUCH_H_

class Bruch {
private:
	int _zaehler;
	int _nenner;
public:
	explicit Bruch(int zaehler, int nenner);
	Bruch(int zahl);
	Bruch();
	virtual ~Bruch();
	int zaehler(){
		return _zaehler;
	}

	int nenner()
	{
		return _nenner;
	}

	void setNenner(int nenner) {
		_nenner = nenner;
	}

	void setZaehler(int zaehler) {
		_zaehler = zaehler;
	}
	void normalize();
	void operator*=(Bruch b);
};

bool operator==(Bruch a, Bruch b);
bool operator!=(Bruch a, Bruch b);
Bruch operator*(Bruch a, Bruch b);
int ggT(int a, int b);
#endif /* BRUCH_H_ */
