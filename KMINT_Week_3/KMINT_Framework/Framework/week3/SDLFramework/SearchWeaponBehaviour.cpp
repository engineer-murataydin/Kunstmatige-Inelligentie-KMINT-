#include "SearchWeaponBehaviour.h"
#include "CatchRabbitBehaviour.h"
#include "Character.h"
#include "Graph.h"

SearchWeaponBehaviour::SearchWeaponBehaviour(Character* character) : CharacterBehaviour(character)
{
	SDL_Texture* texture = character->LoadTexture();
	SDL_SetTextureColorMod(texture, 100, 0, 0);
	character->SetTexture(texture);
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

void SearchWeaponBehaviour::checkState()
{
	if (character->getLocation() == character->getLocation()->graph->weapon->getLocation())
	{
		character->setBehaviour(new CatchRabbitBehaviour(character));
		character->getLocation()->graph->weapon->setLocation(Node::getRandomConnectedNode(character->getLocation(), 100));
		delete this;
	}
}
