#include "FleeBehaviour.h"
#include "Character.h"

FleeBehaviour::FleeBehaviour(Character* character) : CharacterBehaviour(character)
{
	this->character = character;
}

FleeBehaviour::~FleeBehaviour()
{
}

Node* FleeBehaviour::move()
{
	return character->getLocation();//todo change
}

void FleeBehaviour::checkState()
{

}