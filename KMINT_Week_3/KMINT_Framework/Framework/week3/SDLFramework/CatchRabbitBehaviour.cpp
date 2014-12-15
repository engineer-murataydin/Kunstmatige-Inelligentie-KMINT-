#include "CatchRabbitBehaviour.h"
#include "WanderingBehaviour.h"
#include "DeadBehaviour.h"
#include "SleepingBehaviour.h"
#include "Character.h"
#include "Graph.h"


CatchRabbitBehaviour::CatchRabbitBehaviour(Character* character) : CharacterBehaviour(character)
{
	SDL_Texture* texture = character->LoadTexture();
	//SDL_SetTextureColorMod(texture, 0, 0, 100);
	character->SetTexture(texture);
	name = "CatchRabbit";
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
		if (character->getLocation()->graph->rabbit->pill)
		{
			character->setBehaviour(new SleepingBehaviour(character));
			Rabbit* rabbit = character->getLocation()->graph->rabbit;
			rabbit->setBehaviour(new WanderingBehaviour(rabbit));
			rabbit->pill->setLocation(Node::getRandomConnectedNode(character->getLocation(), 100));
			rabbit->pill = nullptr;
		}
		else
		{
			Rabbit* rabbit = character->getLocation()->graph->rabbit;
			rabbit->setBehaviour(new WanderingBehaviour(rabbit));
			character->setLocation(Node::getRandomConnectedNode(character->getLocation(), 100));
		}
	}
}