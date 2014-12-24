#include "SleepingBehaviour.h"
#include "CatchRabbitBehaviour.h"
#include "Character.h"

SleepingBehaviour::SleepingBehaviour(Character* character) : CharacterBehaviour(character)
{
	count = 5;
	name = "Sleeping";
}

SleepingBehaviour::~SleepingBehaviour()
{
}

Vector2* SleepingBehaviour::move()
{
	count--;
	return character->getLocation();
}

void SleepingBehaviour::checkState()
{
	if (count <= 0)
	{
		character->setBehaviour(new CatchRabbitBehaviour(character));
		delete this;
	}
}