#pragma once
#include "Node.h"

class PathNode
{
public:
	PathNode(Node* node, int g, int h, PathNode* from);
	~PathNode();
	Node* node;
	PathNode* from;
	int g, h;
	int F();
};

