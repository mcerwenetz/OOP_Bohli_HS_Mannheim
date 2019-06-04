/*
 * DoubleLinkedList.h
 *
 *  Created on: 25.05.2019
 *      Author: swt
 */
#include <iostream>
using namespace std;

#ifndef DOUBLELINKEDLIST_H_
#define DOUBLELINKEDLIST_H_
template<typename T>
class DoubleLinkedList {
public:
	DoubleLinkedList()
	{
	_head=new _node;
	_tail = new _node;
	_head->prev=nullptr;
	_head->next=_tail;
	_tail->next=nullptr;
	_tail->prev=_head;
	}
	virtual ~DoubleLinkedList()
	{
		for(_node* h = _head->next; h->next == nullptr;)
		{
			h=h->next;
			delete h->prev;
		}
	}

	size_t size() const;
	bool is_empty() const;
	T &operator[](size_t pos);
	const T& operator[] (size_t pos) const;
	void insert(size_t pos, const T &ele);
	void push_back(const T &ele)
	{
	_node* n = new _node;
	n->val=ele;
	n->next=_tail;
	n->prev=_tail->prev;

	_tail->prev->next=n;
	_tail->prev=n;
	}
	void push_front(const T & ele)
	{
		_node* n = new _node;
		n->val=ele;
		n->next=_head->next;
		n->prev=_head;

		_head->next->prev=n;
		_head->next=n;
	}
	T pop_back()
	{
		if(is_empty())
		{
			throw runtime_error("Liste leer");
		}
		_node *h = _tail->prev;
		T ret = h->val;
		_tail->prev = h->prev;
		_tail->prev->next=_tail;
		delete h;
		return ret;
	}
	T pop_front()
	{
		if(is_empty())
		{
			throw runtime_error("Liste leer");
		}
		_node * h = _head->next;
		T ret = h->val;
		_head->next = h->next;
		_head->next->prev=_head;
		delete h;
		return ret;
	}
	void remove(size_t pos);
	bool remove_ele(const T &ele);

private:
	struct _node
	{
		T val;
		_node* next;
		_node* prev;
	};
	_node *_head;
	_node * _tail;
	class Iterator
	{
		friend class DoubleLinkedList;
	public:
		T &operator*()
		{
			if(cur->next == nullptr)
			{
				throw runtime_error("Iterator end");
			}
			return cur->val;
		}
		Iterator &operator++()
		{
			if(cur->next == nullptr)
			{
				throw runtime_error("Iterator end");
			}
			cur = cur ->next;
			return *this;
		}
		bool operator==(const Iterator &other)
		{
			return cur = other.cur;
		}
		bool operator!=(const Iterator &other)
		{
			return cur != other.cur;
		}
	private:
		Iterator(_node *cur):
			cur(cur)
		{}
		_node *cur;
	};
public:
	Iterator begin() const
	{
		return Iterator(_head->next);
	}
	Iterator end() const
	{
		return Iterator(_tail);
	}
};

#endif /* DOUBLELINKEDLIST_H_ */
