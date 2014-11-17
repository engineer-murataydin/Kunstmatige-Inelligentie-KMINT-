#include "Node.h"
#include "Edge.h"


Node::Node(float x, float y)
{
	this->x = x;
	this->y = y;

	dre = default_random_engine(random_device()());
}


Node::~Node()
{
	for (int i = 0; i < edges.size(); i++)
	{
		delete edges[i];
	}
}

void Node::addEdge(Edge* edge)
{
	edges.push_back(edge);
}

bool Node::delEdge(Edge* edge)
{
	for (int i = 0; i < edges.size(); i++)
	{
		if (edges[i] == edge)
		{
			edges[i] = NULL;
			return true;
		}
	}
	return false;
}


Node* Node::getRandomConnectedNode()
{
	uniform_int_distribution<int> arrayDist = uniform_int_distribution<int>(0, edges.size() - 1);
	int pos = arrayDist(dre);
	return edges[pos]->getOtherNode(this);
	return NULL;
}


Node* Node::getRandomConnectedNode(Node* node, int times)
{
	if (times > 1)
	{
		return getRandomConnectedNode(node->getRandomConnectedNode(), --times);
	}
	else
	{
		return node;
	}
}