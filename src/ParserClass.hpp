/*
 * ParserClass.h
 *
 *  Created on: 17 нояб. 2018 г.
 *      Author: AMD
 */

#ifndef PARSERCLASS_HPP_
#define PARSERCLASS_HPP_

#include <iostream>
//#include <fstream>
//#include <typeinfo>
#include <string>

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
        else
        {
        	cout << "string NOT OK!" << endl;
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
            		nodesCnt++;
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

    string getDataStringFromRoot(const string &parseStr)
    {
    	string str_loc = parseStr;
    	string rootDataStr = "";
    	int pos = -1;

    	cout << "-> getDataStringFromRoot" << endl;

    	if( !CheckParseString(parseStr) ) return rootDataStr;

    	if(str_loc.substr(0, 1) == leftBracket)
    	{
    		str_loc.erase(0,1);

    		pos = str_loc.find(leftBracket, 0);
    		if(pos > -1)
    		{
    			rootDataStr = str_loc.substr(0, pos);
    			cout << "rootDataStr = " << rootDataStr << endl;
    		}
    	}

    	cout << "<- getDataStringFromRoot" << endl;

    	return rootDataStr;
    }

    string getTagFromDataString(const string &dataStr)
    {
    	int pos = -1;
    	string str_loc = dataStr;
    	string resTag = "";

    	pos = str_loc.find(teg, 0);
    	if(pos > -1)
    	{
    		pos = str_loc.find("=")+1;

    		str_loc.erase(0, pos);

    		pos = str_loc.find(",",0);

    		resTag = str_loc.substr(0, pos);
    		cout << "resTag = " << resTag << endl;
    	}

    	return resTag;
    }

    string getValFromDataString(const string &dataStr)
    {
    	int pos = -1;
    	string str_loc = dataStr;
    	string resVal = "";

    	pos = str_loc.find(val,0);

    	if(pos > -1)
    	{
    		str_loc.erase(0, pos);

    		pos = str_loc.find("=",0);

    		str_loc.erase(0,pos+1);

    		resVal = str_loc;

    		cout << "resVal = " << resVal << endl;
    	}

    	return resVal;
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
        else {cout << "ok data string!!!" << endl;}

        cout << "<- CheckParseString" << endl;

        return res;
    }

private:
    string parseStr;
    const string leftBracket = "[";
    const string rightBracket = "]";

    const string teg = "teg";
    const string val = "val";
};


#endif /* PARSERCLASS_HPP_ */
