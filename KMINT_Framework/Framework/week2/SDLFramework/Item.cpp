#include "Item.h"


Item::Item(Node* location)
{
	this->location = location;
	SetOffset(location->x, location->y);
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
}