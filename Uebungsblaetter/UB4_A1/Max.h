/*
 * Max.h
 *
 *  Created on: 06.05.2019
 *      Author: swt
 */
#ifndef MAX_H_
#define MAX_H_

#include <cstring>
using namespace std;

class Max {
public:
	Max();
	virtual ~Max();
};

template <typename T>
T max(T* array, int len)
{
	char* max="";
	char* aktuelles_element="";
	for(int i =0; i < len; i++)
	{
		strcpy((*aktuelles_element),(char*)(*(array+i)));
		if(strcmp(max,aktuelles_element)<0)
		{
			strcpy(max,aktuelles_element);
		}
	}
	return (T)max;
}

#endif /* MAX_H_ */
