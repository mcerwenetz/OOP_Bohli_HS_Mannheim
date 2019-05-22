/*
 * main.cpp
 *
 *  Created on: 17.05.2019
 *      Author: swt
 */

#include <iostream>
#include <vector>
#include "ooptool.h"

using namespace std;

void marge_sort(vector<int> &unsortierter_vektor, vector<int> &sortierter_vektor, size_t linker_index, size_t rechter_index);
void abmargen(vector<int> &unsortierter_vektor, vector<int> &sortierter_vektor, size_t linker_index, size_t ende_links, size_t rechter_index, size_t ende_rechts);
void mycopy(vector<int> &zielvektor, vector<int> &quellvektor, size_t startposition, size_t endposition);
void abmargen(vector<int> &unsortierter_vektor);


int main()
{
	vector<int> unsortierter_vektor(10);

	return 0;
}

//Todo: Irgendein Bart-zitat einbauen
void marge_sort(vector<int> &unsortierter_vektor, vector<int> &sortierter_vektor, size_t linker_index, size_t rechter_index)
{
	if(linker_index == rechter_index)
	{
		return ;
	}
	else
	{
		size_t mitte = linker_index+(rechter_index-linker_index)/2;
		marge_sort(unsortierter_vektor, sortierter_vektor, linker_index, mitte);
		marge_sort(unsortierter_vektor, sortierter_vektor, mitte+1,rechter_index);
		abmargen(unsortierter_vektor, sortierter_vektor, linker_index, mitte, mitte+1, rechter_index);
	}
}

void abmargen(vector<int> &unsortierter_vektor, vector<int> &sortierter_vektor, size_t linker_index, size_t ende_links, size_t rechter_index, size_t ende_rechts)
{
	size_t start = linker_index;
	size_t end = ende_rechts;
	size_t i = linker_index;
	while(linker_index <= ende_links && rechter_index <= ende_rechts)
	{
		if(unsortierter_vektor[linker_index] <= unsortierter_vektor[rechter_index])
		{
			sortierter_vektor[i++]=unsortierter_vektor[linker_index++];
		}
		else
		{
			sortierter_vektor[i++]=unsortierter_vektor[rechter_index++];
		}
	}
	while(linker_index <= ende_links)
	{
		sortierter_vektor[i++]=unsortierter_vektor[linker_index++];
	}
	while(rechter_index < ende_rechts)
	{
		sortierter_vektor[i++]=unsortierter_vektor[rechter_index++];
	}
	mycopy(unsortierter_vektor, sortierter_vektor, start, end+1);
}

void mycopy(vector<int> &zielvektor, vector<int> &quellvektor, size_t startposition, size_t endposition)
{
	for(int i = startposition; i < endposition; i++)
	{
		zielvektor[i]=quellvektor[i];
	}
}

void abmargen(vector<int> &unsortierter_vektor)
{
	vector<int> sortierer_vektor(unsortierter_vektor.size());
	marge_sort(unsortierter_vektor,sortierer_vektor, 0, unsortierter_vektor.size()-1);
}
