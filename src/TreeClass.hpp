/*
 * TreeClass.hpp
 *
 *  Created on: 8 но€б. 2018 г.
 *      Author: AMD
 */

#ifndef TREECLASS_HPP_
#define TREECLASS_HPP_

#include <iostream>
#include <typeinfo>
#include <string>
#include "NodeClass.hpp"
#include "ParserClass.hpp"

using namespace std;

class Tree
{
public:
	Tree()
	{
		this->rootNode = nullptr;
	}
	~Tree(){}

	Node *getRootNodePtr(void)
	{
		return this->rootNode;
	}

	// TODO: сделать булевую дл€ возврата результата серилиализации
	void Deserialization(Node *pNode, const string str);

	string Serialization(Node *node);

	// печать дерева
	string PrintTree(void);

	// обход дерева
	string TreeTraversal(Node *rootNode, unsigned int nestingLevel);

private:

	const string tag_int = "int";
	const string tag_float = "float";
	const string tag_string = "string";

	Node *rootNode;

};


#endif /* TREECLASS_HPP_ */
