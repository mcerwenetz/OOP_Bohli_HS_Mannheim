/*
 * Date.h
 *
 *  Created on: 03.04.2019
 *      Author: swt
 */

#ifndef DATE_H_
#define DATE_H_

class Date {
private:
	int _day;
	int _month;
	int _year;
public:
	Date();
	Date(int day, int month, int year);
	virtual ~Date();
	void add_year(int n);
	void add_month(int m);
	void add_day(int d)
	{
		_day+=d;
	}
	int day() const
	{
		return _day;
	}
	int month() const
	{
		return _month;
	}
	int year() const
	{
		return _year;
	}
};

#endif /* DATE_H_ */
