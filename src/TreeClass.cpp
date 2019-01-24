/*
 * TreeClass.cpp
 *
 *  Created on: 25 нояб. 2018 г.
 *      Author: AMD
 */

#include "TreeClass.hpp"


void Tree::Deserialization(Node *pNode, const std::string &str)
{
    std::string str_loc = str;
	Parser parser;

	if(this->rootNode == nullptr)
	{
	    std::string dataStr = parser.getDataStringFromRoot(str_loc);
	    std::string tag = parser.getTagFromDataString(dataStr);
	    std::string val = parser.getValFromDataString(dataStr);

		this->rootNode = new Node(nullptr, tag, val);

		Deserialization(this->rootNode, str_loc);
	}
	else
	{
	    std::vector<std::string> subNodesStr = parser.getSubNodesFromString(str_loc);

		for(size_t i = 0; i < subNodesStr.size(); i++)
		{
		    std::string dataStr = parser.getDataStringFromRoot(subNodesStr[i]);
		    std::string tag = parser.getTagFromDataString(dataStr);
		    std::string val = parser.getValFromDataString(dataStr);

			Node *subNode = new Node(pNode, tag, val);
			pNode->AddSubNode(subNode);

			if(parser.getSubNodesFromString(subNodesStr[i]).size() > 0)
			{
				Deserialization(subNode, subNodesStr[i]);
			}
		}
	}
}

std::string Tree::Serialization(Node *node)
{
    std::string str_res = "";

	if(node == nullptr)return str_res;

	str_res += "[tag=" + node->getTag() + ",val=" + node->getVal();

	std::vector<Node*> subNodes = node->getSubNodes();

	delete node; // освобождение памяти

	for(size_t i = 0; i < subNodes.size(); i++)
	{
		str_res += Serialization(subNodes[i]);
	}

	str_res += "]";

	return str_res;
}

std::string Tree::PrintTree()
{
    std::string res = "";

    if(rootNode == nullptr)
    {
        return res;
    }

    res = TreeTraversal(this->rootNode, "");

    return res;
}

// обход дерева(рекурсивно)
std::string Tree::TreeTraversal(Node *rootNode, std::string indent)
{
    std::string res = "";

    //
    if(rootNode == nullptr){ return res; }

    // вывод содержимого узла
    res = "dataType=" + rootNode->getTag() + ", ";
    res += "data=" + rootNode->getVal() + "\n";

    // проверка наличия SubNodes
    if(rootNode->getSubNodesCount() > 0)
    {
        std::vector<Node*> subNodes = rootNode->getSubNodes();

        indent += "|";

        for(size_t i = 0; i < subNodes.size(); i++)
        {
            res += indent + "->" + TreeTraversal(subNodes[i], (indent+"  "));
        }
    }

    return res;
}

void Tree::ClearTree(Node *pNode)
{
    if(pNode == nullptr)
    {
        if(rootNode != nullptr)
        {
            ClearTree(rootNode);
        }
    }
    else
    {
        std::vector<Node*> subNodes = pNode->getSubNodes();
        std::cout << "pNode.Tag = " << pNode->getTag() << "; pNode.Val = " << pNode->getVal() << std::endl;
        delete pNode;
        for(size_t i = 0; i < pNode->getSubNodesCount(); i++)
        {
            ClearTree(subNodes[i]);
        }

    }
}
