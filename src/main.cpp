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
	else
	{
	    cout << "Pleas enter input and output file names.\n" << endl;
	}


	string displayedData = "";

	while(1)
	{
	    bool quit = false;
	    char choice = 0;
	    string temp = "";

	    system("cls");

	    cout << logo << endl;

	    cout << "\n(i)set input file name" << endl;
	    cout << "(o)set output file name" << endl;
	    cout << "(r)read from input file and deserealization" << endl;
	    cout << "(s)serealization and write to output file" << endl;
	    cout << "(p)print tree" << endl;
	    cout << "(q)quit" << endl;

	    cout << "\n" << displayedData << endl;
	    displayedData = "";

	    cin >> choice;

	    switch(choice)
	    {
	    case 'i':
	        cout << "Enter input file name:" << endl;
	        cin >> inFilename;
	        displayedData += "\nInput file name is: " + inFilename;
	        break;
        case 'o':
            cout << "Enter output file name:" << endl;
            cin >> outFilename;
            displayedData += "\nOutput file name is: " + outFilename;
            break;
        case 'r':
            if(ReadFromFile(inFilename, strFromFile))
            {
                displayedData += "\nInput file content: \n" + strFromFile;

                if(strFromFile.length() > 0)
                {
                    tree.Deserialization(nullptr, strFromFile);
                    displayedData += "\nDeserialization ok";
                }
            }
            break;
        case 'p':
            displayedData += "\n" + tree.PrintTree();
            break;
        case 's':
            temp = tree.Serialization(tree.getRootNodePtr());
            displayedData += "\nSerialization ok";
            displayedData += "\nSerialization string";
            displayedData += "\n" + temp;
            SaveToFile(outFilename, temp);
            displayedData += "\nSerialization save to file ok";
            break;
	    case 'q':
	        quit = true;
	        break;
	    }

	    if(quit)break;
	}

	// --------------------------------------------

	cout << "Close program" << endl;

	return 0;
}

