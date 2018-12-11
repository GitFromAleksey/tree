/*
 * TreeClass.cpp
 *
 *  Created on: 25 ����. 2018 �.
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
		string tag = parser.getTagFromDataString(dataStr);
		string val = parser.getValFromDataString(dataStr);

//		this->rootNode = new Node(tag, val);
		this->rootNode = new Node(nullptr, tag, val);

		Deserialization(this->rootNode, str_loc);
	}
	else
	{
		vector<string> subNodesStr = parser.getSubNodesFromString(str_loc);

		for(unsigned int i = 0; i < subNodesStr.size(); i++)
		{
			string dataStr = parser.getDataStringFromRoot(subNodesStr[i]);
			string tag = parser.getTagFromDataString(dataStr);
			string val = parser.getValFromDataString(dataStr);

//			Node *subNode = new Node(tag,val);
			Node *subNode = new Node(pNode, tag, val);
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

	str_res += "[tag=" + node->getTag() + ",val=" + node->getVal();

	cout << "Serialization: " << str_res << endl;

	vector<Node*> subNodes = node->getSubNodes();
	for(unsigned int i = 0; i < subNodes.size(); i++)
	{
		str_res += Serialization(subNodes[i]);
	}

	str_res += "]";

	return str_res;
}

string Tree::PrintTree(void)
{
    string res = "";
    if(rootNode == nullptr)
    {
        return res;
    }

    res = TreeTraversal(this->rootNode, 0);

    return res;
}

// ����� ������
string Tree::TreeTraversal(Node *rootNode, int nestingLevel)
{
    string res = "";
    string indent = "";

    while(nestingLevel > 0)
    {
        indent += " ";
        nestingLevel--;
    }

    if(rootNode == nullptr){return res;}

    res = rootNode->getTag() + ";";
    res += rootNode->getVal() + "\n";

    if(rootNode->getSubNodesCount() > 0)
    {
        vector<Node*> subNodes = rootNode->getSubNodes();

        for(unsigned int i = 0; i < subNodes.size(); i++)
        {
            res += " " + TreeTraversal(subNodes[i], nestingLevel+1);
        }
    }

    return res;
}
