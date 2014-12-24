#include "CharacterBehaviour.h"
#include "Character.h"

CharacterBehaviour::CharacterBehaviour(Character* character)
{
	this->character = character;
	name = "?";
	onEnter();
}

CharacterBehaviour::~CharacterBehaviour()
{
	onExit();
}

string CharacterBehaviour::getName()
{
	return name;
}

void CharacterBehaviour::onEnter()
{

}

void CharacterBehaviour::onExit()
{

}

Vector2* CharacterBehaviour::move()
{
	return character->getLocation();
}