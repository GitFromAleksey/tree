/*
 * TreeClass.hpp
 *
 *  Created on: 8 нояб. 2018 г.
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

	void *CreateNode()
	{

	}

	bool AddData(const string &tegPrnt, const string &valPrnt, const string &tegChild, const string &valChild)
	{
		bool res = false;

		if(tegChild == "int")
		{
			int d = stoi(valChild, 0);
			// convert string to int
			Node *newNode = new Node(_TYPE_INT, &d);
			this->rootNode = newNode;
			res = true;
		}
		else if(tegChild == "float")
		{
			float d = atof(valChild.c_str());
			// convert string to float
			Node *newNode = new Node(_TYPE_FLOAT, &d);
			this->rootNode = newNode;
			res = true;
		}
		else if(tegChild == "string")
		{// TODO: нужно разобраться как получить адрес ссылки, или решить как-то иначе
			string d = valChild;
			cout << "d = " << valChild << endl;
			//Node *newNode = new Node(_TYPE_STRING, d);
			//this->rootNode = newNode;
			res = true;
		}

		return res;
	}

	void BFS(void *rootNode)
	{

	}

	string getType()
	{
		string ret = string("null");
		if(rootNode == nullptr)
		{
		    return("null");
		}

		if(rootNode->dataType == _TYPE_INT)
		{
			return("int");
		}
		else if(rootNode->dataType == _TYPE_FLOAT)
		{
			return("float");
		}
		else if(rootNode->dataType == _TYPE_STRING)
		{
			return("string");
		}
		else
		{
			return(" ");
		}
	}

	bool CheckData(const string &teg, const string &val)
	{
		if(CompareNodeData(rootNode, teg, val))
		{
			return true;
		}
		else
		{
			return false;
		}
	}

	DataType ConvertTegToDataType(const string &teg)
	{
		if(teg_int == teg)
		{
			return _TYPE_INT;
		}
		else if(teg_float == teg)
		{
			return _TYPE_FLOAT;
		}
		else if(teg_string == teg)
		{
			return _TYPE_STRING;
		}
		return _TYPE_NULL;
	}

private:

	const string teg_int = "int";
	const string teg_float = "float";
	const string teg_string = "string";

	Node* FindNode(Node *root, const string &teg, const string &val)
	{
		Node *pRes = nullptr;

		return pRes;
	}

	bool CompareNodeData(Node *pNode, const string &teg, const string &val)
	{
		bool res = false;

		DataType dType = ConvertTegToDataType(teg);

		if(pNode->dataType == dType)
		{
			if(CompareData(pNode, dType, val))
			{res = true; }
		}

		return res;
	}

	bool CompareData(Node *pNode, DataType dType, const string &val)
	{
		bool res = false;

		if(pNode->pData == nullptr) return false;

		if(dType == _TYPE_INT)
		{
			int data = *(int*)pNode->pData;
			if(data == ConvertToInt(val))
			{
				res = true;
			}
		}
		else if(dType == _TYPE_FLOAT)
		{
			float data = *(float*)pNode->pData;
			if(data == ConverttoFloat(val))
			{
				res = true;
			}
		}
		else if(dType == _TYPE_STRING)
		{
			string data = *(string*)pNode->pData;
			if(data == val)
			{
				res = true;
			}
		}

		return res;
	}

	int ConvertToInt(const string &val)
	{
		int d = stoi(val, 0);
		return d;
	}

	float ConverttoFloat(const string &val)
	{
		float d = atof(val.c_str());
		return d;
	}

	Node *rootNode;

};


#endif /* TREECLASS_HPP_ */
