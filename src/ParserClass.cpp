/*
 * ParserClass.cpp
 *
 *  Created on: 7 ���. 2018 �.
 *      Author: user1
 */

#include "ParserClass.hpp"


// ��������� ��� roots ����� �� ������
std::vector<std::string> Parser::getRootsFromString(const std::string &parseStr)
{
    int bracketsCnt = 0;
    int nodesCnt = 0;
    std::string str_loc = parseStr;
    int openPos = -1;
    int closePos = -1;
    std::string node = "";
    std::vector<std::string> vStr;

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

// ��������� �� ����� ���� � �������
std::string Parser::getDataStringFromRoot(const std::string &parseStr)
{
    std::string str_loc = parseStr;
    std::string rootDataStr = "";
    int pos = -1;

    if( !CheckParseString(parseStr) ) return rootDataStr;

    if(str_loc.substr(0, 1) == leftBracket)
    {
        str_loc.erase(0,1);

        // ��� ������ ����� � root ���� ��� ����
        pos = str_loc.find(leftBracket, 0);
        if(pos > -1)
        {
            rootDataStr = str_loc.substr(0, pos);
        }// ���� ������, ����� ��� ��������
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

// ���������� ���� "tag" �� ���� ������
std::string Parser::getTagFromDataString(const std::string &dataStr)
{
    int pos = -1;
    std::string str_loc = dataStr;
    std::string resTag = "";

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

// ���������� ���� "val" �� ���� ������
// TODO: ������ ���. ���� ��������� �� ������ � ����������� �������, ������� �������,
// �� ���������� ������ �� ����� ������ �� ����� ������
std::string Parser::getValFromDataString(const std::string &dataStr)
{
    int pos = -1;
    std::string str_loc = dataStr;
    std::string resVal = "";

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

// ���������� ������ ��� �����
std::vector<std::string> Parser::getSubNodesFromString(const std::string &parseStr)
{
    int pos = -1;
    int bracketsCnt = 0;
    std::string str_loc = parseStr;
    std::string nodaStr = "";
    std::vector<std::string> vectorRes;

    if( !CheckParseString(parseStr) )return vectorRes;

    // ������� ������� ������
    str_loc.erase(0, 1);
    str_loc.erase(str_loc.length()-1, 1);

    // ���� ������ ������������� ������ � ������ ������
    pos = str_loc.find(leftBracket, 0);
    // ������� �� �� ���� ������
    str_loc.erase(0, pos);

    pos = -1;
    for(unsigned int i = 0; i < str_loc.length(); i++)
    {
        // ������� ������������� � ������������� ������
        if(str_loc.substr(i, 1) == leftBracket)
        {
            bracketsCnt++;
            if(pos == -1)
            {pos = i;}
        }
        if(str_loc.substr(i, 1) == rightBracket)
        {bracketsCnt--;}

        // ���� ���������� ������ ����������, �� ��� ��������� ������ ����
        if(bracketsCnt == 0)
        {
            nodaStr = str_loc.substr(pos, (i+1)-pos);
            pos = -1;

            vectorRes.push_back(nodaStr);
        }
    }

    return vectorRes;
}

// ������������ �������� Node-� � ������
//unsigned int Parser::CountNodes(const string &parseStr)
size_t Parser::CountNodes(const std::string &parseStr)
{
    int bracketsCnt = 0;
    size_t nodesCnt = 0;
    std::string str_loc = parseStr;

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

// �������� ������������ ������� ������
// TODO: ���� �������� ������ �� ������� ������
bool Parser::CheckParseString(const std::string &parseStr)
{
    bool res = true;

    int bracketsCnt = 0;
    int posRightBr = -1;
    int posLeftBr = -1;
    std::string str_loc = parseStr;

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

// TODO: ������������ �����
// ��������� ���������� ������������� � ������������� ������
void Parser::CheckBracketsCount(const std::string &parseStr)
{
    int pos = -1;
    int bracketsCnt = 0;
    int leftBracketsCnt = 0;
    int rightBracketsCnt = 0;

    std::string str_loc = parseStr;

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
        std::cout << "string OK!" << std::endl;
    }
    else
    {
        std::cout << "string NOT OK!" << std::endl;
    }
}
