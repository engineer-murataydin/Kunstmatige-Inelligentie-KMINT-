#include "FleeBehaviour.h"
#include "Character.h"
#include "Rabbit.h"
#include "Graph.h"

FleeBehaviour::FleeBehaviour(Rabbit* character) : CharacterBehaviour(character)
{
	this->character = character;
}

FleeBehaviour::~FleeBehaviour()
{
}

Node* FleeBehaviour::move()
{
	Node* from = character->getLocation();
	Node* to = from->getRandomConnectedNode(); 

	Node* location = Graph::CreatePath(from, to).top();

	character->setLocation(location);

	return character->getLocation(); 
}

void FleeBehaviour::checkState()
{

}