#include "SearchWeaponBehaviour.h"
#include "CatchCowBehaviour.h"
#include "Character.h"
#include "Rabbit.h"
#include "Graph.h"

SearchWeaponBehaviour::SearchWeaponBehaviour(Rabbit* character) : CharacterBehaviour(character)
{
	this->character = character;
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
		character->setBehaviour(new CatchCowBehaviour(character));
		character->weapon = character->getLocation()->graph->weapon;
		delete this;
	}
}
