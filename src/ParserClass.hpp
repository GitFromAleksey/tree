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


class Parser
{
public:
	Parser(){}
    Parser(const std::string &parseStr)
    {
        if(CheckParseString(parseStr))
        {
            this->parseStr = parseStr;
        }
    }
    ~Parser(){}

    // �������� ���������� ������
    // TODO: ������������ �����
    void CheckBracketsCount(const std::string &parseStr);

    // ��������� ��� roots ����� �� ������
    std::vector<std::string> getRootsFromString(const std::string &parseStr);

    // ��������� �� ����� ���� � �������
    std::string getDataStringFromRoot(const std::string &parseStr);

    // ���������� ���� "tag" �� ���� ������
    std::string getTagFromDataString(const std::string &dataStr);

    // ���������� ���� "val" �� ���� ������
    // TODO: ������ ���. ���� ��������� �� ������ � ����������� �������, ������� �������,
    // �� ���������� ������ �� ����� ������ �� ����� ������
    std::string getValFromDataString(const std::string &dataStr);

    // ���������� ������ ��� �����
    std::vector<std::string> getSubNodesFromString(const std::string &parseStr);

    // ������������ �������� Node-� � ������
//    unsigned int CountNodes(const string &parseStr);
    size_t CountNodes(const std::string &parseStr);

    // �������� ������������ ������� ������
    // TODO: ���� �������� ������ �� ������� ������
    // ����� ������� �������� �� ���������� ������
    bool CheckParseString(const std::string &parseStr);

private:
    std::string parseStr;
    const std::string leftBracket = "[";
    const std::string rightBracket = "]";

    const std::string tag = "tag";
    const std::string val = "val";
};


#endif /* PARSERCLASS_HPP_ */
