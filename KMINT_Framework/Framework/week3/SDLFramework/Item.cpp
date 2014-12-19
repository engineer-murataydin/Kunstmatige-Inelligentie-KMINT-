#include "Item.h"
#include "FWApplication.h"

Item::Item(Node* location)
{
	setLocation(Node::getRandomConnectedNode(location, 100));
}


Item::~Item()
{
}

void Item::Update(float deltatime)
{

}

Node* Item::getLocation()
{
	return location;
}

void Item::setLocation(Node* location)
{
	this->location = location;
	SetOffset(location->x, location->y);
}