/*
 * ParserClass.h
 *
 *  Created on: 17 нояб. 2018 г.
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

    // проверка количества скобок
    // TODO: недоделанный метод
    void CheckBracketsCount(const string &parseStr);

    // извлекает все roots корни из строки
    vector<string> getRootsFromString(const string &parseStr);

    // извлекает из корня поле с данными
    string getDataStringFromRoot(const string &parseStr);

    // возвращает поле "tag" из поля данных
    string getTagFromDataString(const string &dataStr);

    // возвращает поле "val" из поля данных
    // TODO: найден баг. Если отправить не строку с выделенными данными, астроку целиком,
    // то возвращает строку со всеми нодами до конца строки
    string getValFromDataString(const string &dataStr);

    // возвращает список под нодов
    vector<string> getSubNodesFromString(const string &parseStr);

    // подсчитывает корневые Node-ы в строке
//    unsigned int CountNodes(const string &parseStr);
    size_t CountNodes(const string &parseStr);

    // проверка правильности формата строки
    // TODO: пока проверка только на крайние скобки
    // нужно сделать проверку на количество скобок
    bool CheckParseString(const string &parseStr);

private:
    string parseStr;
    const string leftBracket = "[";
    const string rightBracket = "]";

    const string tag = "tag";
    const string val = "val";
};


#endif /* PARSERCLASS_HPP_ */
