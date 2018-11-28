/*
 * TreeClass.cpp
 *
 *  Created on: 25 но€б. 2018 г.
 *      Author: AMD
 */

#include "TreeClass.hpp"


void Tree::Deserialization(Node *pNode, const string str)
{
	string str_loc = str;
	Parser parser;

	cout << "Des. input str: " << str << endl;

	if(this->rootNode == nullptr)
	{
		string dataStr = parser.getDataStringFromRoot(str_loc);
		string teg = parser.getTegFromDataString(dataStr);
		string val = parser.getValFromDataString(dataStr);

		this->rootNode = new Node(teg, val);

		Deserialization(this->rootNode, str_loc);
	}
	else
	{
		vector<string> subNodesStr = parser.getSubNodesFromString(str_loc);

		for(unsigned int i = 0; i < subNodesStr.size(); i++)
		{
			string dataStr = parser.getDataStringFromRoot(subNodesStr[i]);
			string teg = parser.getTegFromDataString(dataStr);
			string val = parser.getValFromDataString(dataStr);

			Node *subNode = new Node(teg,val);
			pNode->AddSubNode(subNode);

			if(parser.getSubNodesFromString(subNodesStr[i]).size() > 0)
			{
				Deserialization(subNode, subNodesStr[i]);
			}
		}
	}
}

string Tree::Serialization(Node *node)
{
	string str_res = "";

	str_res += "[teg=" + node->getTeg() + ",val=" + node->getVal();

	cout << "Serialization: " << str_res << endl;

	vector<Node*> subNodes = node->getSubNodes();
	for(unsigned int i = 0; i < subNodes.size(); i++)
	{
		str_res += Serialization(subNodes[i]);
	}

	str_res += "]";

	return str_res;
}
