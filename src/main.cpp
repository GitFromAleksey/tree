/*
 * main.cpp
 *
 *  Created on: 5 нояб. 2018 г.
 *      Author: AMD
 */
#include <iostream>
#include <fstream>
//#include <typeinfo>
#include <string>

#include "TreeClass.hpp"
#include "ParserClass.hpp"
#include "NodeClass.hpp"

//#include <windows.h>

using namespace std;

const string logo = "\n   ___\n\
 /'___`\\           __            \n\
/\\_\\ /\\ \\     __  /\\_\\     ____  \n\
\\/_/// /__  /'_ `\\\\/\\ \\   /',__\\ \n\
   // /_\\ \\/\\ \\L\\ \\\\ \\ \\ /\\__, `\\\n\
  /\\______/\\ \\____ \\\\ \\_\\\\/\\____/\n\
  \\/_____/  \\/___L\\ \\\\/_/ \\/___/ \n\
              /\\____/            \n\
              \\/___/             \n";

bool SaveToFile(string fileName, string data)
{
	ofstream outputFile;

	if(fileName.size() == 0){return false;}

	outputFile.open(fileName.c_str(), ios::out);

	if(outputFile.is_open())
	{
	    outputFile.write((char*)data.c_str(), data.length());
	    outputFile.close();
	    return true;
	}
	else
	{
	    return false;
	}

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

	// имя файла для чтения
	string inFilename = "";
	// имя файла для вывода
	string outFilename = "";

	// переменна для хранения содержимого входного файла
	string strFromFile = "";

    // буфер для вывода информации на экран
	string displayedData = "";

	// простая проверка корректронсти параметров командной строки
	if(argc == 2)
	{
        inFilename = argv[1];
        displayedData += "\nInput file name: " + inFilename;
        displayedData += "\nPleas enter output file names.\n";
	}
	else if(argc == 3)
	{
        inFilename = argv[1];
        outFilename = argv[2];

        displayedData += "\nInput file name: " + inFilename;
        displayedData += "\nOutput file name: " + outFilename;
	}
	else
	{
	    displayedData += "\nInput and output file names are not specified.";
	    displayedData += "\nPleas enter input and output file names.\n";
	}

	while(1)
	{
	    bool quit = false;
	    char choice = 0;
	    string temp = "";

	    system("cls");

	    cout << logo << endl;

	    cout << "\n(i) set input file name" << endl;
	    cout << "(o) set output file name" << endl;
	    cout << "(r) read from input file and deserialization" << endl;
	    cout << "(s) serialization and write to output file" << endl;
	    cout << "(p) print tree" << endl;
	    cout << "(q) quit" << endl;

	    cout << "\n" << displayedData << endl;
	    displayedData = "";

	    cout << "\nYour choice?" << endl;

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
                else
                {
                    displayedData += "\nInput file contains no data.";
                }
            }
            else
            {
                displayedData += "\nFile reading error.";
            }
            break;
        case 'p':
            displayedData += "\nPrint tree: \n";
            temp = tree.PrintTree();
            if(temp.size() == 0)
            {
                displayedData += "\nNothing to print.";
            }
            else
            {
//                displayedData += "\n" + tree.PrintTree();
                displayedData += "\n" + temp;
            }
            break;
        case 's':
            temp = tree.Serialization(tree.getRootNodePtr());

            if(temp.size() > 0)
            {
                displayedData += "\nSerialization string:";
                displayedData += "\n" + temp;
                displayedData += "\nSerialization ok.";

                if(SaveToFile(outFilename, temp))
                {
                    displayedData += "\nSerialization. Save to file ok";
                }
                else
                {
                    displayedData += "\nSerialization. Save to file error";
                }
            }
            else
            {
                displayedData += "\nNothing to serialize";
            }
            break;
	    case 'q':
	        quit = true;
	        break;
	    }

	    if(quit)break;
	}

	// --------------------------------------------


	cout << "\nClose program\n" << endl;
//	system("pause");

	return 0;
}

