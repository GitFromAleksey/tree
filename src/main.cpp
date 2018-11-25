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
	string str_loc = str;
	Parser parser;

	if(pNode == nullptr)
	{
		string dataStr = parser.getDataStringFromRoot(str_loc);
		cout << dataStr << endl;
		string teg = parser.getTegFromDataString(dataStr);
		string val = parser.getValFromDataString(dataStr);
		cout << "teg = " << teg << ", val = " << val << endl;

		Node *node = new Node(teg, val);

		cout << "node->getTeg() = " << node->getTeg() << endl;
		cout << "node->getVal() = " << node->getVal() << endl;

		Deserialization(node, str_loc);
	}
	else
	{
		vector<string> subNodesStr = parser.getSubNodesFromString(str_loc);

		for(int i = 0; i < subNodesStr.size(); i++)
		{
			cout << "subNodesStr[" << i << "] = " << subNodesStr[i] << endl;

			string dataStr = parser.getDataStringFromRoot(subNodesStr[i]);
			cout << dataStr << endl;
			string teg = parser.getTegFromDataString(dataStr);
			string val = parser.getValFromDataString(dataStr);

			Node *subNode = new Node(teg,val);
			pNode->AddSubNode(subNode);

			vector<string> subSubNodes = parser.getSubNodesFromString(subNodesStr[i]);
			if(subNodesStr.size() > 0)
			{
				for(int j = 0; j < subNodesStr.size(); j++)
				{
					Deserialization(subNode, subNodesStr[j]);
				}
			}
		}

		cout << "getSubNodesCount = " << pNode->getSubNodesCount() << endl;
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

