#include "CatchRabbitBehaviour.h"
#include "WanderingBehaviour.h"
#include "DeadBehaviour.h"
#include "Character.h"
#include "Graph.h"

CatchRabbitBehaviour::CatchRabbitBehaviour(Character* character) : CharacterBehaviour(character)
{
	SDL_Texture* texture = character->LoadTexture();
	SDL_SetTextureColorMod(texture, 0, 0, 100);
	character->SetTexture(texture);
}

CatchRabbitBehaviour::~CatchRabbitBehaviour()
{
}

Node* CatchRabbitBehaviour::move()
{
	Node* from = character->getLocation();
	Node* to = from->graph->rabbit->getLocation();

	Node* location = Graph::CreatePath(from, to).top();

	character->setLocation(location);

	return character->getLocation();
}

void CatchRabbitBehaviour::checkState()
{
	if (character->getLocation() == character->getLocation()->graph->rabbit->getLocation())
	{
		character->setBehaviour(new WanderingBehaviour(character));

		Rabbit* rabbit = character->getLocation()->graph->rabbit;
		rabbit->setBehaviour(new DeadBehaviour(rabbit));

		character->setBored(0);
		delete this;
	}
}