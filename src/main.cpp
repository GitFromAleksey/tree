/*
 * main.cpp
 *
 *  Created on: 5 нояб. 2018 г.
 *      Author: AMD
 */
#include <iostream>
#include <fstream>
#include <typeinfo>
#include <string>

#include "TreeClass.hpp"

using namespace std;

// test comment
class Parser
{
public:
    Parser(const string &parseStr)
    {
        if(CheckParseString(parseStr))
        { this->parseStr = parseStr; }
    }
    ~Parser(){}

    void CheckBracketsCount(const string &parseStr)
    {
        int pos = -1;
        int bracketsCnt = 0;
        int leftBracketsCnt = 0;
        int rightBracketsCnt = 0;

        string str_loc = parseStr;

        cout << "-> CheckBracketsCount" << endl;
        cout << "str_loc = " << str_loc << endl;

        while( (pos = str_loc.find(leftBracket, 0)) != -1 )
        {
            bracketsCnt++;
            leftBracketsCnt++;
            str_loc.erase(pos,1);
//            cout << "str_loc = " << str_loc << endl;
        }

        while( (pos = str_loc.find(rightBracket, 0)) != -1 )
        {
            bracketsCnt--;
            rightBracketsCnt++;
            str_loc.erase(pos,1);
//            cout << "str_loc = " << str_loc << endl;
        }

        cout << "leftBracketsCnt = "<< leftBracketsCnt << endl;
        cout << "rightBracketsCnt = "<< rightBracketsCnt << endl;

        if(bracketsCnt == 0)
        {
            cout << "string OK!" << endl;
        }

        cout << "<- CheckBracketsCount" << endl;
    }


    void getRootsFromString(const string &parseStr)
    {
        int bracketsCnt = 0;
        int nodesCnt = 0;
        string str_loc = parseStr;
        int openPos = -1;
        int closePos = -1;
        string node = "";

        cout << "-> getRootFromString" << endl;

        if( !CheckParseString(parseStr) ) return;

        for(unsigned int i = 0; i < str_loc.length(); i++)
        {
            if(str_loc.substr(i, 1) == leftBracket)
            {
            	if( openPos == -1 )
            		{ openPos = i; }
            	bracketsCnt++;
            }
            else if(str_loc.substr(i, 1) == rightBracket)
            {
            	bracketsCnt--;
            	if(bracketsCnt == 0)
            	{
            		closePos = i+1;
            		node = str_loc.substr(openPos, closePos - openPos);
            		cout << "node = " << node << endl;

            		openPos = -1;
            		closePos = -1;
            		node = "";
            	}
            }
        }

        cout << "nodesCnt = " << nodesCnt << endl;

        cout << "<- getRootFromString" << endl;
    }

    // TODO: нужно сделать поиск поднодов
    void getSubNodesFromString(const string &parseStr)
    {

    }

    // подсчитывает корневые Node-ы
    void CountNodes(const string &parseStr)
    {
        int bracketsCnt = 0;
        int nodesCnt = 0;
        string str_loc = parseStr;

        cout << "-> CountNodes" << endl;

        if( !CheckParseString(parseStr) ) return;

        for(unsigned int i = 0; i < str_loc.length(); i++)
        {
            if(str_loc.substr(i, 1) == leftBracket)
            { bracketsCnt++; }
            else if(str_loc.substr(i, 1) == rightBracket)
            { bracketsCnt--; }

            if(bracketsCnt == 0)
            { nodesCnt++; }
        }

        cout << "nodesCnt = " << nodesCnt << endl;

        cout << "<- CountNodes" << endl;
    }

    // проверка правильности формата строки
    // TODO: пока проверка только на крайние скобки
    // нужно сделать проверку на количество скобок
    bool CheckParseString(const string &parseStr)
    {
        cout << "-> CheckParseString" << endl;

        bool res = true;

        int bracketsCnt = 0;
        int posRightBr = -1;
        int posLeftBr = -1;
        string str_loc = parseStr;

        posLeftBr = str_loc.find(leftBracket, 0);
        posRightBr = str_loc.rfind(rightBracket, str_loc.size());

        if(posLeftBr > 0)
        { res = false; }
        if( (posRightBr+1) < str_loc.size() )
        { res = false; }

        for(unsigned int i = 0; i < str_loc.length(); i++)
        {
            if(str_loc.substr(i, 1) == leftBracket)
            { bracketsCnt++; }
            else if(str_loc.substr(i, 1) == rightBracket)
            { bracketsCnt--; }
        }
        if(bracketsCnt != 0)
        { res = false; }

        if(res == false){cout << "Bad data string!!!" << endl;}

        cout << "<- CheckParseString" << endl;

        return res;
    }

private:
    string parseStr;
    const string leftBracket = "[";
    const string rightBracket = "]";
};

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



	return 0;
}

