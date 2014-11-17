#pragma once
#include "Node.h"

class Edge
{
public:
	Edge(Node* from, Node* to);
	~Edge();
	Node* getOtherNode(Node* node);

	Node* from;
	Node* to;

	int cost;
};

