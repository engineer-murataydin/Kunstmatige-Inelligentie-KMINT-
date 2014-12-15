#include "CatchCowBehaviour.h"
#include "Character.h"
#include "Rabbit.h"
#include "Graph.h"
#include "WanderingBehaviour.h"

CatchCowBehaviour::CatchCowBehaviour(Rabbit* character) : CharacterBehaviour(character)
{
	this->character = character;
	name = "CatchCow";
}

CatchCowBehaviour::~CatchCowBehaviour()
{

}

Node* CatchCowBehaviour::move()
{
	Node* from = character->getLocation();
	Node* to = from->graph->cow->getLocation();

	Node* location = Graph::CreatePath(from, to).top();

	character->setLocation(location);

	return character->getLocation();
}

void CatchCowBehaviour::checkState()
{
	vector<Edge*> edges = character->getLocation()->edges;
	Cow* cow = character->getLocation()->graph->cow;
	for (int i = 0; i < edges.size(); i++)
	{
		if (edges[i]->getOtherNode(character->getLocation()) == cow->getLocation())
		{
			cow->setLocation(Node::getRandomConnectedNode(character->getLocation(), 100));

			character->setBehaviour(new WanderingBehaviour(character));

			delete this;
			break;
		}
	}
}

void CatchCowBehaviour::onExit()
{
	Graph* graph = character->getLocation()->graph;
	graph->weapon = character->weapon;
	graph->weapon->setLocation(Node::getRandomConnectedNode(character->getLocation(), 100));
	character->weapon = nullptr;
}
