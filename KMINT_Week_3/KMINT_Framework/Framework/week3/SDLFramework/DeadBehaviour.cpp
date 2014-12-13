#include "DeadBehaviour.h"
#include "WanderingBehaviour.h"
#include "Character.h"
#include "Rabbit.h"
#include "Graph.h"

DeadBehaviour::DeadBehaviour(Rabbit* character) : CharacterBehaviour(character)
{
	this->character = character;
	SDL_Texture* texture = character->LoadTexture();
	SDL_SetTextureColorMod(texture, 50, 50, 50);
	character->SetTexture(texture);

	stepsLeft = 4;
}

DeadBehaviour::~DeadBehaviour()
{
}

Node* DeadBehaviour::move()
{
	--stepsLeft;
	return character->getLocation();
}

void DeadBehaviour::checkState()
{
	if (stepsLeft <= 0)
	{
		character->setLocation(Node::getRandomConnectedNode(character->getLocation(), 100));
		character->setBehaviour(new WanderingBehaviour(character));
	}
}
