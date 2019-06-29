/*
 * BinaryTrees.h
 *
 *  Created on: 23.06.2019
 *      Author: swt
 */

#ifndef BINARYTREES_H_
#define BINARYTREES_H_

#include <iostream>

struct node {
	node *left;
	const char* val;
	node *right;
	node(node *l, const char* v, node *r)
	: left(l), val(v), right(r) {}
};

void inorder(node *n)
{
	if(n==nullptr)
	{
		return;
	}
	else
	{
		inorder(n->left);
		std::cout << n->val << std::endl;
		inorder(n->right);
	}
}

void preorder(node *n)
{
	if(n==nullptr)
	{
		return;
	}
	else
	{
		std::cout << n->val << std::endl;
		preorder(n->left);
		preorder(n->right);
	}
}

void postorder(node *n)
{
	if(n==nullptr)
	{
		return;
	}
	else
	{
		postorder(n->left);
		postorder(n->right);
		std::cout << n->val << std::endl;
	}
}

#endif /* BINARYTREES_H_ */
