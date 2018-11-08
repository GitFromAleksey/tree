/*
 * main.cpp
 *
 *  Created on: 5 но€б. 2018 г.
 *      Author: AMD
 */
#include <iostream>
#include <fstream>
#include <typeinfo>

using namespace std;


class Tree
{
public:
	Tree()
	{
		this->rootNode = nullptr;
	}
	~Tree(){}

	void AddData(const string &type, const string &data)
	{
		if(type == "int")
		{
			int d = stoi(data, 0);
			// convert string to int
			Node *newNode = new Node(_INT_TYPE, &d);
			this->rootNode = newNode;
		}
		else if(type == "float")
		{
			float d = atof(data.c_str());
			// convert string to float
			Node *newNode = new Node(_FLOAT_TYPE, &d);
			this->rootNode = newNode;
		}
		else if(type == "string")
		{
			string d = data;
			Node *newNode = new Node(_STRING_TYPE, &d);
			this->rootNode = newNode;
		}
	}

	string getType()
	{
		string ret = string("null");
		if(rootNode == nullptr)
		{
		    return("null");
		}

		if(rootNode->dataType == _INT_TYPE)
		{
			return("int");
		}
		else if(rootNode->dataType == _FLOAT_TYPE)
		{
			return("float");
		}
		else if(rootNode->dataType == _STRING_TYPE)
		{
			return("string");
		}
		else
		{
			return(" ");
		}
	}

private:
	enum DataType
	{
		_INT_TYPE,
		_FLOAT_TYPE,
		_STRING_TYPE
	};

	class Node
	{
	public:
		DataType dataType;
		void *pData;

		Node(DataType dt, void *pData)
		{
		    dataType = dt;

		    if(dt == _INT_TYPE)
			{
				int i = *(int*)(pData);
				this->pData = new int(i);
			}
			else if(dt == _FLOAT_TYPE)
			{
				float f = *(float*)(pData);
				this->pData = new float(f);
			}
			else if(dt == _FLOAT_TYPE)
			{
				string s = *(string*)(pData);
				this->pData = new string(s);
			}
		}
		~Node(){}
	private:
	};

	Node * rootNode;


};

int main()
{
	Tree tree;

//	int a = 10;
//	float b = 3.14;
	string s = "abc";

	tree.AddData("int", "10");
	cout << "type=" << tree.getType() << endl;

	tree.AddData("float", "3.14");
	cout << "type=" << tree.getType() << endl;

	tree.AddData("string", "string");
	cout << "type=" << tree.getType() << endl;

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

	return 0;
}
