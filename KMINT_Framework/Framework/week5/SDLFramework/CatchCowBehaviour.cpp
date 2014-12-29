#include "CatchCowBehaviour.h"
#include "Character.h"
#include "Rabbit.h"
#include "Cow.h"
#include "WanderingBehaviour.h"

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
	int steps = 10;
	Cow* goal = character->getField()->getCow();
	Vector2 target = *goal->getLocation();
	for (int i = 0; i < steps; i++)
	{
		target = target + goal->velocity;
		FWApplication::GetInstance()->DrawRect(target.getX(), target.getY(), 10, 10, true);
	}
	target = target - *character->getLocation();

	Vector2 move(target);
	if (move.getLength()>character->maxForce)
	{
		move.normalize(character->maxTurnRate);
	}

	character->applyForce(move);

	return character->getLocation();
}

void CatchCowBehaviour::checkState()
{
}

void CatchCowBehaviour::onExit()
{
}
