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
		string teg = parser.getTegFromDataString(dataStr);
		string val = parser.getValFromDataString(dataStr);
		cout << "Create Node: teg = " << teg << ", val = " << val << endl;

		Node *pNode = new Node(teg, val);

		cout << "node->getTeg() = " << pNode->getTeg() << endl;
		cout << "node->getVal() = " << pNode->getVal() << endl;

		Deserialization(pNode, str_loc);
	}
	else
	{
		vector<string> subNodesStr = parser.getSubNodesFromString(str_loc);

		for(int i = 0; i < subNodesStr.size(); i++)
		{
			cout << "subNodesStr[" << i << "] = " << subNodesStr[i] << endl;

			string dataStr = parser.getDataStringFromRoot(subNodesStr[i]);
			string teg = parser.getTegFromDataString(dataStr);
			string val = parser.getValFromDataString(dataStr);

			cout << "Create Node: teg = " << teg << ", val = " << val << endl;
			Node *subNode = new Node(teg,val);
			cout << "subNode->getTeg() = " << subNode->getTeg() << endl;
			cout << "subNode->getVal() = " << subNode->getVal() << endl;
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
	}
}

void Serialization(Node *rootNode)
{
	string str_loc = "";

	if(rootNode == nullptr)cout << "rootNode == nullptr" << endl;

//	str_loc += "teg=" + rootNode->getTeg() + "," + "val=" + rootNode->getVal();

//	cout << "Serialization: " << str_loc << endl;


}

int main()
{
	Tree tree;
	Parser prsr;

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

	tree.Deserialization(nullptr, strFromFile);

//	tree.Serialization(tree.getRootNodePtr());

//	cout << "tree.getRootNodePtr()->getTeg() = " << tree.getRootNodePtr()->getTeg() << endl;
//	cout << "tree.getRootNodePtr()->getVal() = " << tree.getRootNodePtr()->getVal() << endl;
//
//	vector<Node*> subNodes = tree.getRootNodePtr()->getSubNodes();
//	for(int i = 0; i < subNodes.size(); i++)
//	{
//		cout << "subNodes[" << i << "]->getTeg() = " << subNodes[i]->getTeg() << endl;
//		cout << "subNodes[" << i << "]->getVal() = " << subNodes[i]->getVal() << endl;
//
//		vector<Node*> subNodes1 = subNodes[i]->getSubNodes();
//
//		if(subNodes1.size() > 0)
//		for(int j = 0; j < subNodes.size(); j++)
//		{
//			cout << "subNodes1[" << j << "]->getTeg() = " << subNodes1[j]->getTeg() << endl;
//			cout << "subNodes1[" << j << "]->getVal() = " << subNodes1[j]->getVal() << endl;
//		}
//	}
//
//	cout << "tree.getRootNodePtr()->getSubNodesCount() = " << tree.getRootNodePtr()->getSubNodesCount() << endl;



	cout << "tree.Serialization = " << tree.Serialization(tree.getRootNodePtr()) << endl;


//	Serialization(tree.getRootNodePtr());

	return 0;
}

