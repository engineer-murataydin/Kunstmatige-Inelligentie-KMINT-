#include "FleeBehaviour.h"
#include "Character.h"
#include "Rabbit.h"
#include "Graph.h"

FleeBehaviour::FleeBehaviour(Rabbit* character) : CharacterBehaviour(character)
{
	this->character = character;
	name = "Flee";
}

FleeBehaviour::~FleeBehaviour()
{
}

Node* FleeBehaviour::move()
{
	Node* location = character->getLocation();
	Node* avoid = location->graph->cow->getLocation();

	vector<Node*> connected = location->getConnectedNodes();

	while (connected.size() > 1)
	{
		uniform_int_distribution<int> dist(0, connected.size() - 1);
		int random = dist(FWApplication::GetInstance()->dre);

		Node* found = connected[random];
		if (found == avoid)
		{
			connected.erase(connected.begin() + random);
		}
		else
		{
			character->setLocation(location);
			break;
		}
	}

	return character->getLocation();
}

void FleeBehaviour::checkState()
{

}