/*
 * main.cpp
 *
 *  Created on: 5 но€б. 2018 г.
 *      Author: AMD
 */
#include <iostream>
#include <fstream>
#include <typeinfo>
#include <string>

#include "TreeClass.hpp"

using namespace std;


//class Tree
//{
//public:
//	Tree()
//	{
//		this->rootNode = nullptr;
//	}
//	~Tree(){}
//
//	bool AddData(const string &tegPrnt, const string &valPrnt, const string &tegChild, const string &valChild)
//	{
//		bool res = false;
//
//		if(tegChild == "int")
//		{
//			int d = stoi(valChild, 0);
//			// convert string to int
//			Node *newNode = new Node(_TYPE_INT, &d);
//			this->rootNode = newNode;
//			res = true;
//		}
//		else if(tegChild == "float")
//		{
//			float d = atof(valChild.c_str());
//			// convert string to float
//			Node *newNode = new Node(_TYPE_FLOAT, &d);
//			this->rootNode = newNode;
//			res = true;
//		}
//		else if(tegChild == "string")
//		{
//			string d = valChild;
//			Node *newNode = new Node(_TYPE_STRING, &d);
//			this->rootNode = newNode;
//			res = true;
//		}
//
//		return res;
//	}
//
//	void BFS(void *rootNode)
//	{
//
//	}
//
//	string getType()
//	{
//		string ret = string("null");
//		if(rootNode == nullptr)
//		{
//		    return("null");
//		}
//
//		if(rootNode->dataType == _TYPE_INT)
//		{
//			return("int");
//		}
//		else if(rootNode->dataType == _TYPE_FLOAT)
//		{
//			return("float");
//		}
//		else if(rootNode->dataType == _TYPE_STRING)
//		{
//			return("string");
//		}
//		else
//		{
//			return(" ");
//		}
//	}
//
//private:
//
//	const string teg_int = "int";
//	const string teg_float = "float";
//	const string teg_string = "string";
//
//	enum DataType
//	{
//		_TYPE_INT,
//		_TYPE_FLOAT,
//		_TYPE_STRING,
//		_TYPE_NULL
//	};
//
//	class Node
//	{
//	public:
//		DataType dataType;
//		void *pData;
//		Node *pChild[3];
//
//		Node(DataType dt, void *pData)
//		{
//		    dataType = dt;
//
//		    if(dt == _TYPE_INT)
//			{
//				int i = *(int*)(pData);
//				this->pData = new int(i);
//			}
//			else if(dt == _TYPE_FLOAT)
//			{
//				float f = *(float*)(pData);
//				this->pData = new float(f);
//			}
//			else if(dt == _TYPE_FLOAT)
//			{
//				string s = *(string*)(pData);
//				this->pData = new string(s);
//			}
//		}
//		~Node(){}
//	private:
//	};
//
//	Node* FindNode(Node *root, const string &teg, const string &val)
//	{
//		Node *pRes = nullptr;
//
////		if()
//		{
//
//		}
//		return pRes;
//	}
//
//	bool CompareNodeData(Node *pNode, const string &teg, const string &val)
//	{
//		bool res = false;
//
//		DataType dType = ConvertTegToDataType(teg);
//
//		if(pNode->dataType == dType)
//		{
//			if(CompareData(pNode, dType, val))
//			{res = true; }
//		}
//
//		return res;
//	}
//
//	bool CompareData(Node *pNode, DataType dType, const string &val)
//	{
//		bool res = false;
//
//		if(dType == _TYPE_INT)
//		{
//			int data = *(int*)pNode->pData;
//			if(data == ConvertToInt(val))
//			{
//				res = true;
//			}
//		}
//		else if(dType == _TYPE_FLOAT)
//		{
//			float data = *(float*)pNode->pData;
//			if(data == ConverttoFloat(val))
//			{
//				res = true;
//			}
//		}
//		else if(dType == _TYPE_STRING)
//		{
//			string data = *(string*)pNode->pData;
//			if(data == val)
//			{
//				res = true;
//			}
//		}
//
//		return res;
//	}
//
//	int ConvertToInt(const string &val)
//	{
//		int d = stoi(val, 0);
//		return d;
//	}
//
//	float ConverttoFloat(const string &val)
//	{
//		float d = atof(val.c_str());
//		return d;
//	}
//
//	DataType ConvertTegToDataType(const string &teg)
//	{
//		if(teg_int == teg)
//		{
//			return _TYPE_INT;
//		}
//		else if(teg_float == teg)
//		{
//			return _TYPE_FLOAT;
//		}
//		else if(teg_string == teg)
//		{
//			return _TYPE_STRING;
//		}
//		return _TYPE_NULL;
//	}
//
//	Node * rootNode;
//
//};

int main()
{
	Tree tree;

//	int a = 10;
//	float b = 3.14;
	string s = "abc";

	tree.AddData("", "", "int", "10");
	cout << "type=" << tree.getType() << endl;



	tree.AddData("", "", "float", "3.14");
	cout << "type=" << tree.getType() << endl;

	tree.AddData("", "", "string", "string_");
	cout << "type=" << tree.getType() << endl;

	if(tree.CheckData("string", "string"))
	{
		cout << "CheckData = true" << endl;
	}


// --------------------------------------------

	string filename = "tree.ser";

	fstream inputFile("tree.ser");

	if(inputFile)
	{
	    if(inputFile.is_open())
	    {
	        getline(inputFile, s);

	        cout << s << endl;
	    }
	    else
	    {
	        cout << "is_open() = false" << endl;
	    }
	}
	else
	{
	    cout << "File not open" << endl;
	}

	inputFile.close();

// ------ string -------


	return 0;
}
