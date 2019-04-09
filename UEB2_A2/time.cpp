/*
 * time.cpp
 *
 *  Created on: 20.03.2019
 *      Author: swt
 */


#include "time.h"


Time::Time(int hour, int minute, int second)
{
	_hour=hour;
	_minute=minute;
	_second=second;
	normalize();
}

void Time::sethour(int h)
{
	_hour=h;
}
void Time::setmin(int m)
{
	_minute=m;
}
void Time::setsec(int s)
{
	_second=s;
}

int Time::gethour()
{
	return _hour;
}
int Time::getmin()
{
	return _minute;
}
int Time::getsec()
{
	return _second;
}

void Time::normalize()
{
	if(_second-59!=0)
	{
		int rest = _second%60;
		_minute+=(_second/60);
		_second=rest;
	}
	if(_minute-59!=0)
	{
		int rest = _minute%60;
		_hour+=+(_minute/60);
		_minute=rest;
	}
	if(_hour < 0)
	{
		_minute+=_hour*60;
		_hour=0;
	}
	if(_minute < 0)
	{
		_second+=_minute*60;
		_minute=0;
	}
	if(_second < 0)
	{
		std::cout << "Fehler. Zeit kann nicht kleiner als null sein." << std::endl;
		_hour=0;
		_minute=0;
		_second=0;
	}
}

void Time::add_hour(int h)
{
	sethour(gethour()+h);
}
void Time::add_minute(int m)
{
	setmin(getmin()+m);
	normalize();
}
void Time::add_second(int s)
{
	setsec(getsec()+s);
	normalize();
}

void Time::add(int h, int m, int s)
{
	sethour(gethour()+h);
	setmin(getmin() +m);
	setsec(getsec()+s);
	normalize();
}

int Time::justseconds()
{
	int time;
	time=gethour()*3600;
	time+=getmin()*60;
	time+=getsec();



	return time;
}

int diff(int first_sec, int second_sec)
{
	int difference = second_sec-first_sec;
	return difference;

}

void Time::print_time()
{
	std::cout << "Stunde(n):" << gethour() << std::endl;
	std::cout << "Minute(n):" << getmin()<<std::endl;
	std::cout << "Sekunde(n):" << getsec()<<std::endl;

}

