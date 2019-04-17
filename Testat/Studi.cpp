#include "Studi.h"
using namespace std;

Studi::Studi() {
	_matnr=0;
}

Studi::Studi(long matnr, string vorname, string nachname) {
	_matnr=matnr;
	_vorname=vorname;
	_nachname=nachname;
}

Studi::Studi(const Studi &other) {
}

Studi::~Studi() {
}

long Studi::matnr() const {
	return _matnr;
}

string Studi::vorname() const {
	return _vorname;
}

string Studi::nachname() const {
	return _nachname;
}

bool Studi::set_matnr(long matnr) {
	if(this->matnr() < 1000000.0)
	{
		_matnr=matnr;
		return 1;
	}
	else return 0;
}

void Studi::set_image(char *img, int size) {
}
