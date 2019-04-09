/*
 * main.cpp
 *
 *  Created on: 18.03.2019
 *      Author: swt
 */
#include <iostream>
#include <string>
#include <vector>
#include "ooptool.h"

using namespace std;

int main(int argc, const char* argv[])
{
	argsp_t argsp(argc, argv);
	string picture_in = argsp.pos(0, "lena.pgm");
	string picture_out = argsp.pos(1, "out.pgm");
	float s = argsp.int_pos(2,50);
	vector<int> bild = read_pgm(picture_in);
	int V = bild[2];
	for(int i = 3; i < bild.size(); i++)
	{
		if(bild[i] <= (s/100)*V)
		{
			bild[i]=0;
		}else
		{
			bild[i]=V;
		}
	}
	save_pgm(picture_out, bild);
	return 0;
}

