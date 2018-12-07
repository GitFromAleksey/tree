/*
 * ParserClass.cpp
 *
 *  Created on: 7 дек. 2018 г.
 *      Author: user1
 */

#include "ParserClass.hpp"




// извлекает все roots корни из строки
vector<string> Parser::getRootsFromString(const string &parseStr)
{
    int bracketsCnt = 0;
    int nodesCnt = 0;
    string str_loc = parseStr;
    int openPos = -1;
    int closePos = -1;
    string node = "";
    vector<string> vStr;

    if( !CheckParseString(parseStr) ) return vStr;

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
                vStr.push_back(node);
                nodesCnt++;

                openPos = -1;
                closePos = -1;
                node = "";
            }
        }
    }

    return vStr;
}

// извлекает из корня поле с данными
string Parser::getDataStringFromRoot(const string &parseStr)
{
    string str_loc = parseStr;
    string rootDataStr = "";
    int pos = -1;

    if( !CheckParseString(parseStr) ) return rootDataStr;

    if(str_loc.substr(0, 1) == leftBracket)
    {
        str_loc.erase(0,1);

        // это случай когда в root есть под ноды
        pos = str_loc.find(leftBracket, 0);
        if(pos > -1)
        {
            rootDataStr = str_loc.substr(0, pos);
        }// этот случай, когда нет поднодов
        else
        {
            pos = str_loc.find(rightBracket, 0);
            if(pos > -1)
            {
                rootDataStr = str_loc.substr(0, pos);
            }
        }
    }

    return rootDataStr;
}

// возвращает поле "tag" из поля данных
string Parser::getTagFromDataString(const string &dataStr)
{
    int pos = -1;
    string str_loc = dataStr;
    string resTag = "";

    pos = str_loc.find(tag, 0);
    if(pos > -1)
    {
        pos = str_loc.find("=")+1;

        str_loc.erase(0, pos);

        pos = str_loc.find(",",0);

        resTag = str_loc.substr(0, pos);
    }

    return resTag;
}

// возвращает поле "val" из поля данных
// TODO: найден баг. Если отправить не строку с выделенными данными, астроку целиком,
// то возвращает строку со всеми нодами до конца строки
string Parser::getValFromDataString(const string &dataStr)
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
    }

    return resVal;
}

// возвращает список под нодов
vector<string> Parser::getSubNodesFromString(const string &parseStr)
{
    int pos = -1;
    int bracketsCnt = 0;
    string str_loc = parseStr;
    string nodaStr = "";
    vector<string> vectorRes;

    if( !CheckParseString(parseStr) )return vectorRes;

    // удаляем внешние скобки
    str_loc.erase(0, 1);
    str_loc.erase(str_loc.length()-1, 1);

    // ищем первую открывающуюся скобку с начала строки
    pos = str_loc.find(leftBracket, 0);
    // удаляем всё до этой скобки
    str_loc.erase(0, pos);

    pos = -1;
    for(unsigned int i = 0; i < str_loc.length(); i++)
    {
        // считаем открывающиеся и закрывающиеся скобки
        if(str_loc.substr(i, 1) == leftBracket)
        {
            bracketsCnt++;
            if(pos == -1)
            {pos = i;}
        }
        if(str_loc.substr(i, 1) == rightBracket)
        {bracketsCnt--;}

        // если количество скобок сравнялось, то это закрылась скобка нода
        if(bracketsCnt == 0)
        {
            nodaStr = str_loc.substr(pos, (i+1)-pos);
            pos = -1;

            vectorRes.push_back(nodaStr);
        }
    }

    return vectorRes;
}

// подсчитывает корневые Node-ы в строке
int Parser::CountNodes(const string &parseStr)
{
    int bracketsCnt = 0;
    int nodesCnt = 0;
    string str_loc = parseStr;

    if( !CheckParseString(parseStr) ) return 0;

    for(unsigned int i = 0; i < str_loc.length(); i++)
    {
        if(str_loc.substr(i, 1) == leftBracket)
        { bracketsCnt++; }
        else if(str_loc.substr(i, 1) == rightBracket)
        { bracketsCnt--; }

        if(bracketsCnt == 0)
        { nodesCnt++; }
    }

    return nodesCnt;
}

// проверка правильности формата строки
// TODO: пока проверка только на крайние скобки
// нужно сделать проверку на количество скобок
bool Parser::CheckParseString(const string &parseStr)
{
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

    return res;
}

// TODO: недоделанный метод
// проверяет количество открывающихся и закрывающихся скобок
void Parser::CheckBracketsCount(const string &parseStr)
{
    int pos = -1;
    int bracketsCnt = 0;
    int leftBracketsCnt = 0;
    int rightBracketsCnt = 0;

    string str_loc = parseStr;

    while( (pos = str_loc.find(leftBracket, 0)) != -1 )
    {
        bracketsCnt++;
        leftBracketsCnt++;
        str_loc.erase(pos,1);
    }

    while( (pos = str_loc.find(rightBracket, 0)) != -1 )
    {
        bracketsCnt--;
        rightBracketsCnt++;
        str_loc.erase(pos,1);
    }

    if(bracketsCnt == 0)
    {
        cout << "string OK!" << endl;
    }
    else
    {
        cout << "string NOT OK!" << endl;
    }

    //        cout << "<- CheckBracketsCount" << endl;
}
