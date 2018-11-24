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
#include "ParserClass.hpp"
#include "NodeClass.hpp"

using namespace std;


void Deserialization(Node *pNode, const string str)
{
	string str_log = str;
	Parser parser;

	if(pNode == nullptr)
	{
		string dataStr = parser.getDataStringFromRoot(str_log);
		cout << dataStr << endl;
		string teg = parser.getTegFromDataString(dataStr);
		string val = parser.getValFromDataString(dataStr);
		cout << "teg = " << teg << ", val = " << val << endl;

		Node *node = new Node(teg, val);

		cout << "node->getTeg() = " << node->getTeg() << endl;
		cout << "node->getVal() = " << node->getVal() << endl;
	}
	else
	{

	}

}

int main()
{
	Tree tree;
	Parser prsr;

//	int a = 10;
//	float b = 3.14;
	string s = "abc";

//	tree.AddData("", "", "int", "10");
//	cout << "type=" << tree.getType() << endl;
//
//
//
//	tree.AddData("", "", "float", "3.14");
//	cout << "type=" << tree.getType() << endl;
//
//	tree.AddData("", "", "string", "string_");
//	cout << "type=" << tree.getType() << endl;
//
//	if(tree.CheckData("string", "string"))
//	{
//		cout << "CheckData = true" << endl;
//	}

// --------------------------------------------

	string filename = "tree.ser";

	fstream inputFile("tree.ser");

	string strFromFile;

	if(inputFile)
	{
	    if(inputFile.is_open())
	    {
	        getline(inputFile, strFromFile);

	        cout << "Read data from file = " << strFromFile << endl;
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

	// --------------------------------------------

	Deserialization(tree.getRootNodePtr(), strFromFile);

	return 0;
}

