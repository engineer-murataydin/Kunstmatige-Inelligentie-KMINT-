#include "Character.h"


Character::Character(Node* location)
{
	setLocation(location);
}


Character::~Character()
{
}

void Character::setLocation(Node* location)
{
	this->location = location;
	SetOffset(location->x, location->y);
}

Node* Character::getLocation()
{
	return location;
}

void Character::setBehaviour(CharacterBehaviour* behaviour)
{
	this->behaviour = behaviour;
}
