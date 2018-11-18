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

using namespace std;


void Deserialization(Tree *pTree, Parser *pPrsr, const string &str)
{

	int cntRootNodes = pPrsr->CountNodes(str);
//	cout << "cntRootNodes = " << cntRootNodes << endl;

	vector<string> rootStr = pPrsr->getRootsFromString(str);
	for(int i = 0; i < rootStr.size(); i++)
	{
		cout << "rootStr[" << i << "]: " << rootStr[i] << endl;
		vector<string> subNodes = pPrsr->getSubNodesFromString(rootStr[i]);
		string dataStr = pPrsr->getDataStringFromRoot(rootStr[i]);
		string teg = pPrsr->getTegFromDataString(dataStr);
		string val = pPrsr->getValFromDataString(dataStr);
//		cout << "rootTeg: " << teg << "; tegVal: " << val << endl;
		for(int j = 0; j < subNodes.size(); j++)
		{
			cout << "subNodes[" << j << "]: " << subNodes[j] << endl;
			if(subNodes[j].size() > 0)
			{
				Deserialization(pTree, pPrsr, subNodes[j]);
			}
		}
	}

}

int main()
{
	Tree tree;
	Parser prsr;

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

	Deserialization(&tree, &prsr, strFromFile);

	return 0;
}

