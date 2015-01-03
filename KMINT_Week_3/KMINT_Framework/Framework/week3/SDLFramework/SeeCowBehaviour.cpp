#include "SeeCowBehaviour.h"
#include "CharacterBehaviour.h"
#include "Character.h"
#include "Rabbit.h"

SeeCowBehaviour::SeeCowBehaviour(Rabbit* character) : CharacterBehaviour(character)
{
	this->character = character;
}

SeeCowBehaviour::~SeeCowBehaviour()
{
}

Node* SeeCowBehaviour::move()
{
	return character->getLocation();
}

void SeeCowBehaviour::checkState()
{
	
}
