#include "Character.h"
#include "CharacterBehaviour.h"

Character::Character(Node* location)
{
	setLocation(Node::getRandomConnectedNode(location, 100));
	name = "?";
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

string Character::getState()
{
	return behaviour->getName();
}

string Character::getName()
{
	return name;
}