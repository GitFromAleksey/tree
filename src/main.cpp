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

void SaveToFile(string fileName, string data)
{
	ofstream outputFile;

	outputFile.open(fileName.c_str(), ios::out);

	outputFile.write((char*)data.c_str(), data.length());

	outputFile.close();
}

bool ReadFromFile(string fileName, string &strFromFile)
{
    bool res = false;

    fstream inputFile(fileName);

    if(inputFile)
    {
        if(inputFile.is_open())
        {
            res = true;
            getline(inputFile, strFromFile);
        }
    }

    inputFile.close();

    return res;
}

int main(int argc, char *argv[])
{
	Tree tree;
	Parser prsr;
// --------------------------------------------
	string inFilename = argv[1];
	string outFilename = argv[2];

	string strFromFile = "";

	if(ReadFromFile(inFilename, strFromFile))
	{
	    cout << "strFromFile: " << strFromFile << endl;

	    if(strFromFile.length() > 0)
	    {
	        tree.Deserialization(nullptr, strFromFile);
	        string outData = tree.Serialization(tree.getRootNodePtr());
	        cout << "tree.Serialization = " << outData << endl;
	        SaveToFile(outFilename, outData);
	    }
	}

//	fstream inputFile(inFilename);
//
//	string strFromFile;
//
//	if(inputFile)
//	{
//	    if(inputFile.is_open())
//	    {
//	        getline(inputFile, strFromFile);
//
//	        cout << "Read data from file = " << strFromFile << endl;
//
//	    	if(strFromFile.length() > 0)
//	    	{
//				tree.Deserialization(nullptr, strFromFile);
//				string outData = tree.Serialization(tree.getRootNodePtr());
//				cout << "tree.Serialization = " << outData << endl;
//				SaveToFile(outFilename, outData);
//	    	}
//	    	else
//	    	{
//	    		cout << "file is empty" << endl;
//	    	}
//	    }
//	    else
//	    {
//	        cout << "is_open() = false" << endl;
//	    }
//	}
//	else
//	{
//	    cout << "File not open" << endl;
//	}
//
//	inputFile.close();

	// --------------------------------------------


	return 0;
}

