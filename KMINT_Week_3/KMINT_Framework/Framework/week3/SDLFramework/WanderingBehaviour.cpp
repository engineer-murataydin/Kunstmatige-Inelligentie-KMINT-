#include "WanderingBehaviour.h"
#include "SearchPillBehaviour.h"
#include "Character.h"
#include "Graph.h"

WanderingBehaviour::WanderingBehaviour(Character* character) : CharacterBehaviour(character)
{
	chanse = uniform_int_distribution<int>(0, 100);
	SDL_Texture* texture = character->LoadTexture();
	//SDL_SetTextureColorMod(texture, 0, 0, 0);
	character->SetTexture(texture);
}

WanderingBehaviour::~WanderingBehaviour()
{
}

Node* WanderingBehaviour::move()
{
	if (chanse(dre) >= 30)
	{
		Node* location = character->getLocation();
		location = location->getRandomConnectedNode();
		character->setLocation(location);
	}
	return character->getLocation();
}

void WanderingBehaviour::checkState()
{
	if (character->isBored())
	{
		character->setBehaviour(new SearchPillBehaviour(character));
		delete this;
	}
}
