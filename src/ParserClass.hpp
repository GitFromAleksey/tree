/*
 * ParserClass.h
 *
 *  Created on: 17 ����. 2018 �.
 *      Author: AMD
 */

#ifndef PARSERCLASS_HPP_
#define PARSERCLASS_HPP_

#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Parser
{
public:
	Parser(){}
    Parser(const string &parseStr)
    {
        if(CheckParseString(parseStr))
        {
            this->parseStr = parseStr;
        }
    }
    ~Parser(){}

    // �������� ���������� ������
    // TODO: ������������ �����
    void CheckBracketsCount(const string &parseStr);

    // ��������� ��� roots ����� �� ������
    vector<string> getRootsFromString(const string &parseStr);

    // ��������� �� ����� ���� � �������
    string getDataStringFromRoot(const string &parseStr);

    // ���������� ���� "tag" �� ���� ������
    string getTagFromDataString(const string &dataStr);

    // ���������� ���� "val" �� ���� ������
    // TODO: ������ ���. ���� ��������� �� ������ � ����������� �������, ������� �������,
    // �� ���������� ������ �� ����� ������ �� ����� ������
    string getValFromDataString(const string &dataStr);

    // ���������� ������ ��� �����
    vector<string> getSubNodesFromString(const string &parseStr);

    // ������������ �������� Node-� � ������
//    unsigned int CountNodes(const string &parseStr);
    size_t CountNodes(const string &parseStr);

    // �������� ������������ ������� ������
    // TODO: ���� �������� ������ �� ������� ������
    // ����� ������� �������� �� ���������� ������
    bool CheckParseString(const string &parseStr);

private:
    string parseStr;
    const string leftBracket = "[";
    const string rightBracket = "]";

    const string tag = "tag";
    const string val = "val";
};


#endif /* PARSERCLASS_HPP_ */
