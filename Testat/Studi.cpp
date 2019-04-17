#include "Studi.h"
#include <cstring>
using namespace std;

Studi::Studi() {
	_matnr=0;
	_image_size=0;
	_image=NULL;
}

Studi::Studi(long matnr, string vorname, string nachname) {
	_matnr=matnr;
	_vorname=vorname;
	_nachname=nachname;
	_image_size=0;
	_image=NULL;
}

//Kopierkonstruktor
Studi::Studi(const Studi &other) {

	_image_size=other._image_size;
	_vorname=other._vorname;
	_nachname=other._nachname;
	this->_matnr=0;
	_image = new char[_image_size];
	for(int i=0; i < _image_size; i++)
		_image[i]=other._image[i];

}

Studi::~Studi() {
	delete [] _image;
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
	if(matnr < 10000000 && matnr > 999999)
	{
		_matnr=matnr;
		return 1;
	}
	else return 0;
}

void Studi::set_image(char *img, int size) {
	_image_size=size;
	_image = new char[_image_size];
	for(int i=0; i < _image_size; i++)
		_image[i]=img[i];
}
