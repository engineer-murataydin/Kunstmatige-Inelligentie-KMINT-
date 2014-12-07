#include "SearchPillBehaviour.h"
#include "SearchWeaponBehaviour.h"
#include "Character.h"
#include "Graph.h"

SearchPillBehaviour::SearchPillBehaviour(Character* character) : CharacterBehaviour(character)
{
	SDL_Texture* texture = character->LoadTexture();
	SDL_SetTextureColorMod(texture, 0, 100, 0);
	character->SetTexture(texture);
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
		character->setBehaviour(new SearchWeaponBehaviour(character));
		character->getLocation()->graph->pill->setLocation(Node::getRandomConnectedNode(character->getLocation(), 100));

		delete this;
	}
}
