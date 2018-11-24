/*
 * NodeClass.hpp
 *
 *  Created on: 25 но€б. 2018 г.
 *      Author: AMD
 */

#ifndef NODECLASS_HPP_
#define NODECLASS_HPP_

#include <iostream>
#include <typeinfo>
#include <string>
#include <vector>

using namespace std;

enum DataType
{
	_TYPE_INT,
	_TYPE_FLOAT,
	_TYPE_STRING,
	_TYPE_NULL
};

	class Node
	{
	public:

		DataType dataType;
		void *pData;
		Node *pChild[3];
		vector<Node*> vecChild;

		Node(const string &teg, const string &val)
		{
			if(teg == teg_int)
			{
				int d = stoi(val, 0);
				dataType = _TYPE_INT;
				pData = new int(d);
			}
			else if(teg == teg_float)
			{
				float d = atof(val.c_str());
				dataType = _TYPE_FLOAT;
				pData = new float(d);
			}
			else if(teg == teg_string)
			{
				pData = new string(teg);
				dataType = _TYPE_STRING;
			}
		}

		Node(DataType dt, void *pData)
		{
		    dataType = dt;

		    if(dt == _TYPE_INT)
			{
				int i = *(int*)(pData);
				this->pData = new int(i);
			}
			else if(dt == _TYPE_FLOAT)
			{
				float f = *(float*)(pData);
				this->pData = new float(f);
			}
			else if(dt == _TYPE_FLOAT)
			{
				string s = *(string*)(pData);
				this->pData = new string(s);
			}
		}

		~Node(){}

		string getVal(void)
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
				res = teg_string;
			}

			return res;
		}

		string getTeg(void)
		{
			string res = "";

			switch(dataType)
			{
			case _TYPE_INT:
				res = teg_int;
				break;
			case _TYPE_FLOAT:
				res = teg_float;
				break;
			case _TYPE_STRING:
				res = teg_string;
				break;
			default:
				break;
			}

			return res;
		}

	private:


		const string teg_int = "int";
		const string teg_float = "float";
		const string teg_string = "string";

		DataType ConvertTegToDataType(const string &teg)
		{
			DataType type = _TYPE_NULL;

			if(teg_int == teg)
			{
				return _TYPE_INT;
			}
			else if(teg_float == teg)
			{
				return _TYPE_FLOAT;
			}
			else if(teg_string == teg)
			{
				return _TYPE_STRING;
			}
			return _TYPE_NULL;
		}

	};


#endif /* NODECLASS_HPP_ */
