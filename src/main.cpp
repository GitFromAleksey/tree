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

// ------ string -------

    Parser prsr(strFromFile);
    prsr.CheckBracketsCount(strFromFile);
    prsr.getRootsFromString(strFromFile);
    prsr.CountNodes(strFromFile);
    s = prsr.getDataStringFromRoot(strFromFile);
    cout << s << endl;
    prsr.getTegFromDataString(s);
    prsr.getValFromDataString(s);

    vector<string> vStr = prsr.getSubNodesFromString(strFromFile);

    for(int i = 0; i < vStr.size(); i++)
    {
    	cout << "vStr[" << i << "] = " << vStr[i] << endl;
    }


	return 0;
}

