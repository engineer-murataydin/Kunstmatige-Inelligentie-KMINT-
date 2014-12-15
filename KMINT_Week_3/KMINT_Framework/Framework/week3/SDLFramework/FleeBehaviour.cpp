#include "FleeBehaviour.h"
#include "Character.h"
#include "Rabbit.h"
#include "Graph.h"

FleeBehaviour::FleeBehaviour(Rabbit* character) : CharacterBehaviour(character)
{
	this->character = character;
	name = "Flee";
}

FleeBehaviour::~FleeBehaviour()
{
}

Node* FleeBehaviour::move()
{
	Node* location = character->getLocation();
	Node* avoid = location->graph->cow->getLocation();

	do
	{
		location = character->getLocation()->getRandomConnectedNode();
	} while (location != avoid && location->edges.size() > 1);
	character->setLocation(location);

	return character->getLocation();
}

void FleeBehaviour::checkState()
{

}