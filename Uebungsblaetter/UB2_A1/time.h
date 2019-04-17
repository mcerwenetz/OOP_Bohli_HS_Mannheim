/*
 * date.h
 *
 *  Created on: 20.03.2019
 *      Author: swt
 */

#ifndef TIME_H_
#define TIME_H_

#include <iostream>

class Time
{
	int _hour;
	int _minute;
	int _second;
	void normalize();
public:
	Time(int hour=0, int minute=0, int second=0);
	void sethour(int h);
	void setmin(int m);
	void setsec(int s);
	int gethour();
	int getmin();
	int getsec();
	void add(int h=0, int m=0, int s=0);
	void add_hour(int h);
	void add_minute(int m);
	void add_second(int s);
	int justseconds();
	void print_time();
};

int diff(int first_sec, int second_sec);
#endif /* TIME_H_ */
