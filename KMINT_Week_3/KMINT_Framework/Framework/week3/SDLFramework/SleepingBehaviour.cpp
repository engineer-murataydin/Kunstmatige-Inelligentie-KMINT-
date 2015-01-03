#include "SleepingBehaviour.h"
#include "CatchRabbitBehaviour.h"
#include "Character.h"
#include "Graph.h"

SleepingBehaviour::SleepingBehaviour(Character* character) : CharacterBehaviour(character)
{
	count = 5;
}

SleepingBehaviour::~SleepingBehaviour()
{
}

Node* SleepingBehaviour::move()
{
	return character->getLocation();
}

void SleepingBehaviour::checkState()
{
	count--;

	if (count <= 0)
	{
		character->setBehaviour(new CatchRabbitBehaviour(character));
	}
}