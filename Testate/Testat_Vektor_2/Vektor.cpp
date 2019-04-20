// Name:
// Marikelnummer: 
#include "Vektor.h"
#include <iostream>
using namespace std;

Vektor::Vektor(unsigned len) {
  _len = len;
  _vek = new double[_len];
  for (unsigned i = 0; i < _len; ++i) {
    _vek[i] = 0;
  }
}

// Ab hier implementieren
Vektor::Vektor() {
	_len=3;
	_vek=new double[3];
	for(int i=0; i < _len; i++)
	_vek[i]=0;
}

Vektor::~Vektor() {
	delete[] _vek;
}

Vektor::Vektor(const Vektor &other) {
	_len=other._len;
	//delete _vek;
	_vek=new double[other._len];
	for(unsigned int i=0; i < other._len; i++)
		_vek[i]=other._vek[i];
}

Vektor &Vektor::operator=(const Vektor &other) {

	_len=other._len;
	if(this==&other)
	{
		return *this;
	}
	delete [] _vek;
	double * newvec=new double[other._len];
	for(unsigned int i=0; i < other._len; i++)
	{
		newvec[i]=other._vek[i];
	}
	_vek=newvec;
	//other.~Vektor();
	return *this;
}

Vektor operator+(Vektor left, Vektor right) {
if(left.getlen() != right.getlen())
	{
	throw runtime_error("Fehler");
	}
	else
	{
		Vektor erg(left.getlen());
		for(unsigned int i=0; i < erg.getlen(); i++)
		{
			erg.set_vek((left.getvec(i)+right.getvec(i)),i);
		}
		return erg;
	}
}

void Vektor::resize(unsigned l) {

	double* newvec = new double[l];

	for(unsigned int i=0; i < l; i++)
	{
		if( i<_len)
		{
			newvec[i]=_vek[i];
		}
		else
		{
			newvec[i]=0;
		}
	}
	delete [] _vek;
	_vek=newvec;
	_len=l;

}
