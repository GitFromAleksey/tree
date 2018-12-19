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

const string logo = "\n   ___\n\
 /'___`\\           __            \n\
/\\_\\ /\\ \\     __  /\\_\\     ____  \n\
\\/_/// /__  /'_ `\\\\/\\ \\   /',__\\ \n\
   // /_\\ \\/\\ \\L\\ \\\\ \\ \\ /\\__, `\\\n\
  /\\______/\\ \\____ \\\\ \\_\\\\/\\____/\n\
  \\/_____/  \\/___L\\ \\\\/_/ \\/___/ \n\
              /\\____/            \n\
              \\/___/             \n\n";

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
    cout << logo << endl;

    Tree tree;
	Parser prsr;
// --------------------------------------------

	// им€ файла дл€ чтени€
	string inFilename = "";
	// им€ файла дл€ вывода
	string outFilename = "";

	// переменна дл€ хранени€ содержимого входного файла
	string strFromFile = "";

	// проверка корректронсти параметров командной строки
	if(argc == 3)
	{
        inFilename = argv[1];
        outFilename = argv[2];

        cout << "Input file name: " << inFilename << endl;
        cout << "Output file name: " << outFilename << endl;
	}


	while(1)
	{
	    bool quit = false;
	    int choice = 0;

	    cout << "(1)read from input file and deserealization" << endl;
	    cout << "(2)serealization and write to output file" << endl;
	    cout << "(3)print tree" << endl;
	    cout << "(0)quit" << endl;

	    cin >> choice;

	    switch(choice)
	    {
	    case 0:
	        quit = true;
	        break;
	    }

	    if(quit)break;
	}

//	if(ReadFromFile(inFilename, strFromFile))
//	{
//	    cout << "strFromFile: " << strFromFile << endl;
//
//	    if(strFromFile.length() > 0)
//	    {
//	        tree.Deserialization(nullptr, strFromFile);
//	        string outData = tree.Serialization(tree.getRootNodePtr());
//	        cout << "tree.Serialization = " << outData << endl;
//	        SaveToFile(outFilename, outData);
//
//	        cout << tree.PrintTree() << endl;
//	    }
//	}

	// --------------------------------------------

	cout << "Close program" << endl;

	return 0;
}

