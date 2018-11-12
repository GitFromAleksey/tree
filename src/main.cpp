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

    void getRootFromString(const string &parseStr)
    {
        cout << "-> getRootFromString" << endl;

        int posRightBr = -1;
        int posLeftBr = -1;
        string str_loc = parseStr;
        string ret_str = "";

        posLeftBr = str_loc.find(leftBracket, 0);
        posRightBr = str_loc.rfind(rightBracket, str_loc.size());

        // TODO: вставить сюда CheckParseString
        if(posLeftBr > 0)
        { cout << "Bad data, posLeftBr > 0" << endl; return; }
        if( (posRightBr+1) < str_loc.size() )
        { cout << "Bad data, posRightBr < str_loc.size()" << endl; return; }

        str_loc.erase(posRightBr,1);
        str_loc.erase(posLeftBr,1);

        cout << "str_loc = " << str_loc << endl;

        posLeftBr = str_loc.find(leftBracket, 0);

        ret_str = str_loc.substr( 0, posLeftBr);

        cout << "ret_str = " << ret_str << endl;

        cout << "<- getRootFromString" << endl;
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

//	cout << "strFromFile.size() = " << strFromFile.size() << endl;
//	cout << "strFromFile.length() = " << strFromFile.length() << endl;
//	cout << "strFromFile.empty() = " << strFromFile.empty() << endl;
//	const char *charStr = strFromFile.c_str();
//	cout << "charStr = " << charStr << endl;
//	cout << "strFromFile.substr(1, 5) = " << strFromFile.substr(1, 5) << endl;
//
//	string::size_type found = strFromFile.find("[");
//	cout << "found = " << found << endl;
//
//	found = strFromFile.find("[", found+1);
//	cout << "found = " << found << endl;
////	found = strFromFile.find("[", found+1);
////	cout << "found = " << found << endl;
//
//	cout << "strFromFile.substr(found, 5) = " << strFromFile.substr(found, 5) << endl;
//	cout << "strFromFile.substr(found) = " << strFromFile.substr(found) << endl;
//
//	cout << "strFromFile.rfind(\"[\") = " << strFromFile.rfind("[") << endl;
//
////	cout << "strFromFile.erase(found, 10) = " << strFromFile.erase(found, 10) << endl;


    Parser prsr(strFromFile);
    prsr.CheckBracketsCount(strFromFile);
    prsr.getRootFromString(strFromFile);
    prsr.CountNodes(strFromFile);



	return 0;
}

