/*
 * NodeClass.cpp
 *
 *  Created on: 7 дек. 2018 г.
 *      Author: user1
 */

#include "NodeClass.hpp"


Node::Node(const std::string &tag, const std::string &val)
{
    if(tag == tag_int)
    {
        int d = stoi(val, 0);
        dataType = _TYPE_INT;
        pData = new int(d);
    }
    else if(tag == tag_float)
    {
        float d = atof(val.c_str());
        dataType = _TYPE_FLOAT;
        pData = new float(d);
    }
    else if(tag == tag_string)
    {
        pData = new std::string(val);
        dataType = _TYPE_STRING;
    }
}

Node::Node(const Node *pParent, const std::string &tag, const std::string &val)
{
    if(tag == tag_int)
    {
        int d = stoi(val, 0);
        dataType = _TYPE_INT;
        pData = new int(d);
    }
    else if(tag == tag_float)
    {
        float d = atof(val.c_str());
        dataType = _TYPE_FLOAT;
        pData = new float(d);
    }
    else if(tag == tag_string)
    {
        pData = new std::string(val);
        dataType = _TYPE_STRING;
    }
}

std::string Node::getVal()
{
    std::string res = "";

    if(dataType == _TYPE_INT)
    {
        int i = *(int*)pData;
        res = std::to_string(i);
    }
    else if(dataType == _TYPE_FLOAT)
    {
        float f = *(float*)pData;
        res = std::to_string(f);
    }
    else if(dataType == _TYPE_STRING)
    {
        std::string s = *(std::string*)pData;
        res = s;
    }

    return res;
}

std::string Node::getTag()
{
    std::string res = "";

    switch(dataType)
    {
    case _TYPE_INT:
        res = tag_int;
        break;
    case _TYPE_FLOAT:
        res = tag_float;
        break;
    case _TYPE_STRING:
        res = tag_string;
        break;
    default:
        break;
    }

    return res;
}

DataType Node::ConvertTagToDataType(const std::string &tag)
{
    if(tag_int == tag)
    {
        return _TYPE_INT;
    }
    else if(tag_float == tag)
    {
        return _TYPE_FLOAT;
    }
    else if(tag_string == tag)
    {
        return _TYPE_STRING;
    }
    return _TYPE_NULL;
}
