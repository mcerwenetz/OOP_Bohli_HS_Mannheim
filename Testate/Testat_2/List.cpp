/*
 * List.cpp
 *
 *  Created on: 22.05.2019
 *      Author: swt
 */

#include "List.h"

List::List(size_t size) {

	_dummy = new _node;
	_dummy->next=_dummy;
	_dummy->prev=_dummy;


	if(size!=0)
	{
		for(int i=0; i < size; i++)
		{
			_node* j=_dummy;


			while(j->next!= _dummy )
				j=j->next;
			_node* n = new _node;
			n->val=3;

			j->next=n;
			n->prev=j;
			n->next=_dummy;
			_dummy->prev=n;


		}
	}
}

List::~List() {
	// TODO Auto-generated destructor stub
}

int List::size()
{
	int i=0;
	if(_dummy->next==_dummy)
	{
		return 0;
	}
	else
	{
		_node* j=_dummy;
		while(j->next!=_dummy)
		{
			i++;
			j=j->next;
		}
		return i;
	}
}

void List::remove_all(int value)
{
	if(_dummy->next==_dummy)
	{
		//Liste leer, kann nix löschen
		return;
	}
	else
	{
		_node* j=_dummy->next;
		while(j!=_dummy)
		{
			if(j->val==value)
			{
				j->prev->next=j->next;
				j->next->prev=j->prev;
				delete[] j;
			}
			j=j->next;
		}
	}
}

