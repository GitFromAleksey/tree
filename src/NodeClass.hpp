/*
 * NodeClass.hpp
 *
 *  Created on: 25 нояб. 2018 г.
 *      Author: AMD
 */

#ifndef NODECLASS_HPP_
#define NODECLASS_HPP_

#include <iostream>
#include <typeinfo>
#include <string>
#include <vector>

using namespace std;

enum DataType
{
	_TYPE_INT,
	_TYPE_FLOAT,
	_TYPE_STRING,
	_TYPE_NULL
};

	class Node
	{
	public:

		// TODO: убрать в private
		DataType dataType;	// идентификатор хранимого типа данных
		// TODO: убрать в private
		void *pData;	// указатель на хранимые данные
		// TODO: убрать в private
		Node *pParent; // указатель на родителя
		// TODO: убрать в private
		vector<Node*> subNodes;	// список указателей на подноды

		Node(){}
		Node(const string &tag, const string &val);
		Node(const Node *pParent, const string &tag, const string &val);
		~Node(){}

		void AddParent(Node *pParent)
		{
			this->pParent = pParent;
		}

		void AddSubNode(Node *node)
		{
			subNodes.push_back(node);
		}

		vector<Node*> getSubNodes(void)
		{
			return subNodes;
		}

		int getSubNodesCount(void)
		{
			return subNodes.size();
		}

		string getVal(void);

		string getTag(void);

	private:

		const string tag_int = "int";
		const string tag_float = "float";
		const string tag_string = "string";

		DataType ConvertTagToDataType(const string &tag);

	};


#endif /* NODECLASS_HPP_ */
