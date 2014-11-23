#include "CatchRabbitBehaviour.h"


CatchRabbitBehaviour::CatchRabbitBehaviour(Character* character) : CharacterBehaviour(character)
{
}


CatchRabbitBehaviour::~CatchRabbitBehaviour()
{
}

Node* CatchRabbitBehaviour::move()
{
	/*Node* from = character->getLocation();
	Node* to = from->graph->rabbit->getLocation();

	Node* location = Graph::CreatePath(from, to).top();

	character->setLocation(location);

	return character->getLocation();*/

	return nullptr;
}