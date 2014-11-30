#include "Character.h"


Character::Character(Node* location)
{
	setLocation(Node::getRandomConnectedNode(location, 100));
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

SDL_Texture* Character::LoadTexture()
{
	return FWApplication::GetInstance()->LoadTexture(textureName);
}


bool Character::isBored()
{
	return bored >= 100;
}

void Character::setBored(int value)
{
	bored = value;
}
