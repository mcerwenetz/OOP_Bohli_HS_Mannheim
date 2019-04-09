/*
 * participants.cpp
 *
 *  Created on: 27.03.2019
 *      Author: swt
 */

#include "participants.h"

Participant::Participant(int startnummer, Time zeit,std::string name)
{
	setStartnummer(startnummer);
	setName(name);
	setZeit(zeit);
}

