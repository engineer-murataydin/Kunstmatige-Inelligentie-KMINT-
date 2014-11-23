#include "WanderingBehaviour.h"
#include "Character.h"

WanderingBehaviour::WanderingBehaviour(Character* character) : CharacterBehaviour(character)
{
}


WanderingBehaviour::~WanderingBehaviour()
{
}

Node* WanderingBehaviour::move()
{
	Node* location = character->getLocation();
	location = location->getRandomConnectedNode();
	character->setLocation(location);
	return character->getLocation();
}
