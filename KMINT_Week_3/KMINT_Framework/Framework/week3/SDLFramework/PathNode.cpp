#include "PathNode.h"


PathNode::PathNode(Node* node, int g, int h, PathNode* from)
{
	this->node = node;
	this->from = from;
	this->g = g;
	this->h = h;
}

PathNode::~PathNode()
{
}

int PathNode::F()
{
	return g + h;
}