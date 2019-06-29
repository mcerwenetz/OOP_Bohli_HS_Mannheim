/*
 * DoubleLinkedList.h
 *
 *  Created on: 29.06.2019
 *      Author: swt
 */

#ifndef DOUBLELINKEDLIST_H_
#define DOUBLELINKEDLIST_H_
#include <iostream>
#include <ios>

template<typename T>
struct _node
	{
		T val;
		_node *next;
		_node *prev;
	};

template<typename T>
class DoubleLinkedList
{
public:
	DoubleLinkedList();
	~DoubleLinkedList();
	int size() const;
	bool is_empty() const;
	T& operator[](int pos);
	const T& operator[](int pos) const;
	void insert(int pos, const T &ele);
	void push_back(const T& ele);
	void push_front(const T& ele);
	T pop_back();
	T pop_front();
	void remove(int pos);
	bool remove_ele(const T& ele);
	void show();
private:
	_node<T>* head;
	_node<T>* tail;
};

template<typename T>
DoubleLinkedList<T>::DoubleLinkedList()
{
	head = new _node<T>;
	tail = new _node<T>;
	head->prev=nullptr;
	tail->next=nullptr;
	head->next=tail;
	tail->prev=head;
}

template<typename T>
DoubleLinkedList<T>::~DoubleLinkedList()
{
	_node<T>* todel=tail;
	while(todel->prev != nullptr)
	{
		todel = todel->prev;
		delete todel->next;
	}
	delete head;
}

template<typename T>
int DoubleLinkedList<T>::size() const
{
	int size=0;
	_node<T>* counter = head;
	while(counter->next!=tail)
	{
		counter=counter->next;
		size++;
	}
	return size;
}

template<typename T>
bool DoubleLinkedList<T>::is_empty() const
{
	return head->next==tail;
}

template<typename T>
T& DoubleLinkedList<T>::operator[](int pos)
{
	if(this->size() < pos) {throw std::runtime_error("Node nicht enthalten");}
	_node<T>* help=head;
	run(help,pos);
	return help->val;
}

template<typename T>
void DoubleLinkedList<T>::push_back(const T& element)
{
	_node<T>* pushin = new _node<T>;
	pushin->val = element;
	pushin->prev=tail->prev;
	pushin->next=tail;
	tail->prev->next=pushin;
	tail->prev=pushin;
}

template<typename T>
void DoubleLinkedList<T>::push_front(const T& element)
{
	_node<T>* pushin = new _node<T>;
	pushin->val=element;
	pushin->next=head->next;
	pushin->prev=head;
	head->next->prev=pushin;
	head->next=pushin;
}

template<typename T>
void DoubleLinkedList<T>::insert(int pos, const T& element)
{
	if(pos > this->size()){throw std::runtime_error("Index nicht vorhanden");}
	_node<T>* help=head;
	run(help,pos);
	_node<T>* toinsert = new _node<T>;
	toinsert->val=element;
	toinsert->next=help;
	toinsert->prev=help->prev;
	help->prev->next=toinsert;
	help->prev=toinsert;
}

template<typename T>
void DoubleLinkedList<T>::remove(int pos)
{
	if(pos > this->size()){throw std::runtime_error("Index nicht vorhanden");}
	_node<T>* help=head;
	run(help,pos);
	help->prev->next=help->next;
	help->next->prev=help->prev;
	delete help;
}

template<typename T>
void DoubleLinkedList<T>::show()
{
	_node<T>* help = head;
	while(help->next!=tail)
	{
		step(help);
		std::cout << " [" <<help->val << "] " << std::endl;;
	}
}


template<typename T>
bool DoubleLinkedList<T>::remove_ele(const T& ele)
{
	_node<T>* help = head;
	int i=0;
	while(help->val!=ele && help->next!=tail)
	{
		step(help);
		i++;
	}
	if(help->next==tail)
	{
		return 0;
	}
	this->remove(i);
	return 1;
}

template<typename T>
void run(_node<T>*& help, int pos)
{
	int i=0;
	while(i<pos)
	{
		step(help);
		i++;
	}
}

template<typename T>
void step(_node<T>*& help)
{
	help=help->next;
}


#endif /* DOUBLELINKEDLIST_H_ */
