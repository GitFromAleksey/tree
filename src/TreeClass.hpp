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


class Tree
{
public:
	Tree()
	{
		this->rootNode = nullptr;
	}
	~Tree(){}

	Node *getRootNodePtr() const
	{
		return this->rootNode;
	}

	void Deserialization(Node *pNode, const std::string &str);

	std::string Serialization(Node *node);

	// ������ ������
	std::string PrintTree();

	// ����� ������
	std::string TreeTraversal(Node *rootNode, std::string indent);

	void ClearTree(Node *pNode);

private:

	const std::string tag_int = "int";
	const std::string tag_float = "float";
	const std::string tag_string = "string";

	Node *rootNode;

};


#endif /* TREECLASS_HPP_ */
