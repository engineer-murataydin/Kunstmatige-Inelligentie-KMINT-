#include "Edge.h"
#include "Utill.h"
#include <math.h>

Edge::Edge(Node* from, Node* to)
{
	this->from = from;
	this->to = to;

	from->addEdge(this);
	to->addEdge(this);
	int dX = from->x - to->x;
	int dY = from->y - to->y;
	cost = Utill::distanceBewteenPoints(from->x, from->y, to->x, to->y);
}


Edge::~Edge()
{
	if (from)
	{
		from->delEdge(this);
	}
	if (to)
	{
		to->delEdge(this);
	}
}

Node* Edge::getOtherNode(Node* node)
{
	if (node == from)
	{
		return to;
	}
	else if (node == to)
	{
		return from;
	}
	return NULL;
}
