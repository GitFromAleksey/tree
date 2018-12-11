/*
 * NodeClass.cpp
 *
 *  Created on: 7 дек. 2018 г.
 *      Author: user1
 */

#include "NodeClass.hpp"

Node::Node(const string &tag, const string &val)
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
        pData = new string(val);
        dataType = _TYPE_STRING;
    }
}

Node::Node(const Node *pParent, const string &tag, const string &val)
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
        pData = new string(val);
        dataType = _TYPE_STRING;
    }
}

string Node::getVal()
{
    string res = "";

    if(dataType == _TYPE_INT)
    {
        int i = *(int*)pData;
        res = to_string(i);
    }
    else if(dataType == _TYPE_FLOAT)
    {
        float f = *(float*)pData;
        res = to_string(f);
    }
    else if(dataType == _TYPE_STRING)
    {
        string s = *(string*)pData;
        res = s;
    }

    return res;
}

string Node::getTag(void)
{
    string res = "";

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

DataType Node::ConvertTagToDataType(const string &tag)
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
