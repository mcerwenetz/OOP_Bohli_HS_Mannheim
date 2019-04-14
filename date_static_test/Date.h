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
	static Date default_date;
public:
	Date();
	Date(int day, int month, int year);
	virtual ~Date();
	static void set_default_date(int d, int m, int y);

	int getDay() const {
		return _day;
	}

	int getMonth() const {
		return _month;
	}

	int getYear() const {
		return _year;
	}
};

#endif /* DATE_H_ */
