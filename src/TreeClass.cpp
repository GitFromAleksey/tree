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
		cout << "Create Node: teg = " << teg << ", val = " << val << endl;

		this->rootNode = new Node(teg, val);

//		cout << "rootNode->getTeg() = " << this->rootNode->getTeg() << endl;
//		cout << "rootNode->getVal() = " << this->rootNode->getVal() << endl;

		Deserialization(this->rootNode, str_loc);
	}
	else
	{
		vector<string> subNodesStr = parser.getSubNodesFromString(str_loc);

		for(int i = 0; i < subNodesStr.size(); i++)
		{
			cout << "subNodesStr[" << i << "] = " << subNodesStr[i] << endl;

			string dataStr = parser.getDataStringFromRoot(subNodesStr[i]);
			string teg = parser.getTegFromDataString(dataStr);
			string val = parser.getValFromDataString(dataStr);

			cout << "Create Node: teg = " << teg << ", val = " << val << endl;
			Node *subNode = new Node(teg,val);
//			cout << "subNode->getTeg() = " << subNode->getTeg() << endl;
//			cout << "subNode->getVal() = " << subNode->getVal() << endl;
			pNode->AddSubNode(subNode);

			vector<string> subSubNodes = parser.getSubNodesFromString(subNodesStr[i]);
			if(subNodesStr.size() > 0)
			{
				for(int j = 0; j < subNodesStr.size(); j++)
				{
					Deserialization(subNode, subNodesStr[j]);
				}
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
	for(int i = 0; i < subNodes.size(); i++)
	{
		str_res += Serialization(subNodes[i]);
	}

	str_res += "]";

	return str_res;
}
