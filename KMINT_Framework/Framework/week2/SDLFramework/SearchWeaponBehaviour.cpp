#include "SearchWeaponBehaviour.h"
#include "Character.h"
#include "Graph.h"

SearchWeaponBehaviour::SearchWeaponBehaviour(Character* character) : CharacterBehaviour(character)
{
}


SearchWeaponBehaviour::~SearchWeaponBehaviour()
{
}

Node* SearchWeaponBehaviour::move()
{
	Node* from = character->getLocation();
	Node* to = from->graph->weapon->getLocation();

	Node* location = Graph::CreatePath(from, to).top();

	character->setLocation(location);

	return character->getLocation();
}
