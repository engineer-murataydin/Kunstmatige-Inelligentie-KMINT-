#include "Item.h"
#include "FWApplication.h"

Item::Item(Field* field, Vector2 location) : GameObject(field)
{
	setLocation(location);
}


Item::~Item()
{
}

void Item::Update(float deltatime)
{

}
