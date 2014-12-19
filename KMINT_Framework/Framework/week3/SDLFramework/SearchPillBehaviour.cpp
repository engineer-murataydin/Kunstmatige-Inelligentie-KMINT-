#include "SearchPillBehaviour.h"
#include "SearchWeaponBehaviour.h"
#include "WanderingBehaviour.h"
#include "Character.h"
#include "Rabbit.h"
#include "Graph.h"

SearchPillBehaviour::SearchPillBehaviour(Rabbit* character) : CharacterBehaviour(character)
{
	this->character = character;
	SDL_Texture* texture = character->LoadTexture();
	SDL_SetTextureColorMod(texture, 0, 100, 0);
	character->SetTexture(texture);
	this->character = character;
	name = "SearchPill";
}

SearchPillBehaviour::~SearchPillBehaviour()
{
}

Node* SearchPillBehaviour::move()
{
	Node* from = character->getLocation();
	Node* to = from->graph->pill->getLocation();

	Node* location = Graph::CreatePath(from, to).top();

	character->setLocation(location);

	return character->getLocation();
}

void SearchPillBehaviour::checkState()
{
	if (character->getLocation() == character->getLocation()->graph->pill->getLocation())
	{
		character->setBehaviour(new WanderingBehaviour(character));

		character->pill = character->getLocation()->graph->pill;
		character->pill->setLocation(character->getLocation()->graph->outOfscreen);
		character->getLocation()->graph->pill = nullptr;

		delete this;
	}
}