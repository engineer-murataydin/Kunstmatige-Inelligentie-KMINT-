#include "Item.h"
#include "FWApplication.h"

Item::Item(Vector2* location)
{
	setLocation(location);
}


Item::~Item()
{
}

void Item::Update(float deltatime)
{

}

Vector2* Item::getLocation()
{
	return location;
}

void Item::setLocation(Vector2* location)
{
	this->location = location;
	SetOffset(location->getX(), location->getY());
}