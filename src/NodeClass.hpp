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

static const std::string tag_null = "";
static const std::string tag_int = "int";
static const std::string tag_float = "float";
static const std::string tag_string = "string";

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

        Node(){}
		Node(const std::string &tag, const std::string &val);
		Node(const Node *pParent, const std::string &tag, const std::string &val);
		~Node(){}

		void AddParent(Node *pParent)
		{
			this->pParent = pParent;
		}

		void AddSubNode(Node *node)
		{
			subNodes.push_back(node);
		}

		std::vector<Node*> getSubNodes() const
		{
			return subNodes;
		}

		size_t getSubNodesCount() const
		{
			return subNodes.size();
		}

		std::string getVal() const;

		const std::string &getTag() const;

	private:

//		const std::string tag_int = "int";
//		const std::string tag_float = "float";
//		const std::string tag_string = "string";

        DataType dataType;  // идентификатор хранимого типа данных
        void *pData;    // указатель на хранимые данные
        Node *pParent; // указатель на родителя
        std::vector<Node*> subNodes; // список указателей на подноды

		DataType ConvertTagToDataType(const std::string &tag);
	};


#endif /* NODECLASS_HPP_ */
