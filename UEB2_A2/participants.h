/*
 * participants.h
 *
 *  Created on: 27.03.2019
 *      Author: swt
 */

#ifndef PARTICIPANTS_H_
#define PARTICIPANTS_H_

#include "time.h"
#include <cstring>


class Participant
{
private:
	int _startnummer;
	Time _zeit;
	std::string _name;

public:
	Participant(int startnummer, Time zeit,std::string name);
	Participant();
	~Participant();

	const std::string& getName() const {
		return _name;
	}

	void setName(const std::string& name) {
		_name = name;
	}

	int getStartnummer() const {
		return _startnummer;
	}

	void setStartnummer(int startnummer) {
		_startnummer = startnummer;
	}

	const Time& getZeit() const {
		return _zeit;
	}

	void setZeit(const Time& zeit) {
		_zeit = zeit;
	}
};



#endif /* PARTICIPANTS_H_ */
