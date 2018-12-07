/*
 * TreeClass.hpp
 *
 *  Created on: 8 ����. 2018 �.
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

	void Deserialization(Node *pNode, const string str);

	string Serialization(Node *node);

	// ����� ������
	void BFS(void *rootNode)
	{

	}

private:

	const string tag_int = "int";
	const string tag_float = "float";
	const string tag_string = "string";

	Node *rootNode;

};


#endif /* TREECLASS_HPP_ */
