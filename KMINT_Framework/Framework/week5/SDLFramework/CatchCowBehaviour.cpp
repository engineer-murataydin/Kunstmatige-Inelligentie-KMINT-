#include "CatchCowBehaviour.h"
#include "SleepingBehaviour.h"
#include "Character.h"
#include "Rabbit.h"
#include "WanderingBehaviour.h"
#include "DeadBehaviour.h"

CatchCowBehaviour::CatchCowBehaviour(Rabbit* character) : CharacterBehaviour(character)
{
	this->character = character;
	name = "CatchCow";
}

CatchCowBehaviour::~CatchCowBehaviour()
{
	onExit();
}

Vector2* CatchCowBehaviour::move()
{
	return character->getLocation();
}

void CatchCowBehaviour::checkState()
{
}

void CatchCowBehaviour::onExit()
{
}
