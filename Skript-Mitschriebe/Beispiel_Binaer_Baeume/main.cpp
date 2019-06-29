/*
 * main.cpp
 *
 *  Created on: 23.06.2019
 *      Author: swt
 */

#include "BinaryTrees.h"

int main()
{
	node *a = new node(nullptr, "a", nullptr);
	node *b = new node(nullptr, "b", nullptr);
	node *root = new node(a, "root", b);

	preorder(root);
	inorder(root);
	postorder(root);
}



