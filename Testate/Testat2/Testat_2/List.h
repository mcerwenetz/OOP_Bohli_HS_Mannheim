/*
 * List.h
 *
 *  Created on: 22.05.2019
 *      Author: swt
 */

#ifndef LIST_H_
#define LIST_H_
#include <iostream>

class List {
public:
	List(size_t size);
	virtual ~List();
	int size();
	void remove_all(int value);

private:
	struct _node
	{
		int val;
		_node *next;
		_node *prev;
	};
	_node *_dummy;
};

#endif /* LIST_H_ */
