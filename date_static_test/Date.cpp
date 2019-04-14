/*
 * Date.cpp
 *
 *  Created on: 03.04.2019
 *      Author: swt
 */

#include "Date.h"
Date Date::default_date(1,1,1970);

Date::Date() {
	// TODO Auto-generated constructor stub

}

Date::Date(int day, int month, int year) {
	// TODO Auto-generated constructor stub
	_day=default_date._day;
	_month=default_date._month;
	_year=year=default_date._year;
}

Date::~Date() {
	// TODO Auto-generated destructor stub
}

void Date::set_default_date(int d, int m, int y)
{
Date::default_date._day= d;
Date::default_date._month=m;
Date::default_date._year=y;
}
