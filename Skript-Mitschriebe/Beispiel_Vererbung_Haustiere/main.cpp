/*
 * main.cpp
 *
 *  Created on: 04.06.2019
 *      Author: swt
 */

#include "Haustier.h"
#include "Katze.h"
#include "Hund.h"
#include <vector>

using namespace std;

int main()
{
	//Einstieg
//	Haustier htier("???");
//	Hund waldi("waldi", "waldorf");
//	Katze mimi("mimi");
//	cout << htier.name() << " " << htier.gibLaut() << endl;
//	cout << waldi.name() << " " << waldi.gibLaut() << endl;
//	cout << mimi.name() << " " << mimi.gibLaut() << endl;
//
//	htier = waldi;
//	cout << htier.name() << " " << htier.gibLaut() << endl;

	//Up, Down and Sidecast
//	Haustier htier("???");
//	Hund waldi("waldi", "waldorf");
//	Katze mimi("mimi");
//
//	Hund* hundptr = &waldi;
//	cout << hundptr->name() << " " << hundptr->gibLaut() << endl;
//	Haustier* haustierptr=hundptr;
//	cout << haustierptr->name() << " " << haustierptr->gibLaut() << endl; //Upcast
//	Hund* hund2ptr=(Hund*) haustierptr;
//	cout << hund2ptr->name() << " " << hund2ptr->gibLaut() << endl; //Explicit Downcast in Hund
//	Katze* katzeptr=(Katze*) haustierptr;
//	cout << katzeptr->name() << " " << katzeptr->gibLaut() << endl; //Explicit Downcast in Katze
//	Katze* katze2ptr=(Katze*) hundptr;
//	cout << katze2ptr->name() << " " << katze2ptr->gibLaut() << endl; //"Sidecast"

	//casten mit c++
//	Haustier htier("???");
//	Hund waldi("waldi", "waldorf");
//	Katze mimi("mimi");
//
//	Katze* katzenptr=&mimi;
//
//	Haustier* hptr=&waldi;
//	Hund* h2ptr=static_cast<Hund*>(hptr); //Explizite umwandlung, wie h2ptr= (Hund*) hptr;
//	cout << hptr->name() << " " << hptr->gibLaut() << endl;
//	cout << h2ptr->name() << " " << h2ptr->gibLaut() << endl;
//	//Geht nicht
//	//Hund* h3ptr=static_cast<Hund*>(katzenptr);
//	Hund* h3ptr=reinterpret_cast<Hund*>(&mimi);

	//Polymorphie
	Haustier htier("???");
	Hund waldi("waldi", "waldorf");
	Katze mimi("mimi");
	vector<Haustier *> zoo = {&htier, &waldi, &mimi};
	for(Haustier* h : zoo)
	{
		cout << h->name()<< ":" << h->gibLaut() << endl;
	}
	return 0;
}

