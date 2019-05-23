#include "Bild.h"
#include <iostream>

using namespace std;

Bild::Bild(unsigned int breite, unsigned int hoehe) {
	width=breite;
	height=hoehe;
	img=new unsigned char[breite*hoehe];
	for(unsigned i=0; i <(breite*hoehe); i++)
	{
		img[i]=0;
	}
}

Bild::Bild(const Bild &other) {
	width=other.width;
	height=other.height;
	img=new unsigned char[width*height];
	for(int i=0; i < (width*height); i++)
		*(img+i)= *(other.img+i);
}

Bild::~Bild() {
	delete [] img;
}

Bild &Bild::operator=(const Bild &other) {
	if(img==other.img && width==other.width && height==other.height)
	{
		return *this;
	}
	else
	{
		height=other.height;
		width=other.width;
		delete [] img;
		img=new unsigned char[width*height];
		for(unsigned int i=0; i< (width*height); i++)
		{
			*(img+i)=*(other.img+i);
		}
		return *this;
	}
}

unsigned int Bild::size() const {
	return (width*height);
}

double Bild::aspect_ratio() const {
	double erg=((double)width/(double)height);
	return(erg);
}

unsigned char &Bild::at(unsigned int zeile, unsigned int spalte) {
	if(zeile>width || spalte > height)
	{
		return *img;
	}
	else
	{
		return *(img+zeile*width+spalte);
	}
}

unsigned char Bild::at(unsigned int zeile, unsigned int spalte) const {
	if(zeile > height || spalte > width)
	{
		return 0;
	}
	else
	{
		//return img[zeile][spalte];
		return *(img+zeile*width+spalte);
		//return *(img+zeile*spalte);
	}
}

void Bild::fuelle(unsigned char gray) {
	for(unsigned int i=0; i < (width*height); i++)
		*(img+i)=gray;
}

void Bild::zeile(unsigned int row, unsigned char gray) {
	for(int i=0; i<width; i++)
		*(img+row*width+i)=gray;
}

void Bild::spalte(unsigned int col, unsigned char gray) {
	for(int i=0; i<height; i++)
		//img[i][col]=gray;
		*(img+i*width+col)=gray;
		//*(img+row*width+i)=gray;
}

void Bild::breiter(unsigned char gray) {
	int neue_breite=width+1;
	unsigned char* newimg = new unsigned char[neue_breite*height];
	for(int i=0; i < height; i++)
	{
		for(int j=0; j < neue_breite; j++)
		{
			if(j == width)
			{
				*(newimg+i*neue_breite+j)=gray;
				//newimg[i][j]=gray;
			}
			else
			{
				*(newimg+i*neue_breite+j)=*(img+i*neue_breite+j);
				//newimg[i][j]=img[i][j];
			}
		}
	}
	delete[] img;
	width=neue_breite;
	img=newimg;
}

void Bild::flip(Bild &bild) {
	Bild zwischen(*this);
	*this=bild;
	bild=zwischen;
}

