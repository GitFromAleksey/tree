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

    // проверка количества скобок
    // TODO: недоделанный метод
    void CheckBracketsCount(const std::string &parseStr);

    // извлекает все roots корни из строки
    std::vector<std::string> getRootsFromString(const std::string &parseStr);

    // извлекает из корня поле с данными
    std::string getDataStringFromRoot(const std::string &parseStr);

    // возвращает поле "tag" из поля данных
    std::string getTagFromDataString(const std::string &dataStr);

    // возвращает поле "val" из поля данных
    // TODO: найден баг. Если отправить не строку с выделенными данными, астроку целиком,
    // то возвращает строку со всеми нодами до конца строки
    std::string getValFromDataString(const std::string &dataStr);

    // возвращает список под нодов
    std::vector<std::string> getSubNodesFromString(const std::string &parseStr);

    // подсчитывает корневые Node-ы в строке
//    unsigned int CountNodes(const string &parseStr);
    size_t CountNodes(const std::string &parseStr);

    // проверка правильности формата строки
    // TODO: пока проверка только на крайние скобки
    // нужно сделать проверку на количество скобок
    bool CheckParseString(const std::string &parseStr);

private:
    std::string parseStr;
    const std::string leftBracket = "[";
    const std::string rightBracket = "]";

    const std::string tag = "tag";
    const std::string val = "val";
};


#endif /* PARSERCLASS_HPP_ */
