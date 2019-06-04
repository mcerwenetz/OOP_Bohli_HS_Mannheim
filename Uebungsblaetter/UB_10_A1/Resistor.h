/*
 * Resistor.h
 *
 *  Created on: 03.06.2019
 *      Author: swt
 */

#ifndef RESISTOR_H_
#define RESISTOR_H_



class Resistor {
public:
	Resistor() : _value(0){};
	Resistor(double value) : _value(value){};
	virtual ~Resistor(){}
	double virtual getvalue(){return _value;}
protected:
	double _value;
};

class Serial : public Resistor
{
public:
	Serial() : Resistor(){
	};
	Serial(Resistor &R1, Resistor &R2) : Resistor(R1.getvalue()+R2.getvalue()){
	}
	virtual ~Serial(){
	}
};

class Paralel : public Resistor
{
public:
	Paralel() : Resistor(0){}
	Paralel(Resistor &R1, Resistor &R2) : Resistor((R1.getvalue()*R2.getvalue())/(R1.getvalue()+R2.getvalue())){};

	virtual ~Paralel()
	{
	}
};

#endif /* RESISTOR_H_ */
