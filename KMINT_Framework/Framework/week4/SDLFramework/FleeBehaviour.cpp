#include "FleeBehaviour.h"
#include "WanderingBehaviour.h"
#include "Character.h"
#include "Rabbit.h"
#include "Cow.h"
#include "Utill.h"

#include <iostream>

FleeBehaviour::FleeBehaviour(Rabbit* character) : CharacterBehaviour(character)
{
	this->character = character;
	name = "Flee";
	onEnter();
}

FleeBehaviour::~FleeBehaviour()
{
	onExit();
}

Vector2* FleeBehaviour::move()
{
	Vector2 avoid;
	vector<Cow*> cowsInRange = character->getCowsInRange();
	if (cowsInRange.size() > 0)
	{
		for (size_t i = 0; i < cowsInRange.size(); i++)
		{
			avoid = avoid + *cowsInRange[i]->getLocation();
		}

		avoid = avoid / cowsInRange.size();
		FWApplication::GetInstance()->DrawRect(avoid.getX(), avoid.getY(), 10, 10, true);

		Vector2 move = (avoid - *character->getLocation()) * -1;
		move.normalize();

		move = move * character->maxTurnRate;

		character->applyForce(move);
	}
	return character->getLocation();
}

void FleeBehaviour::checkState()
{
	if (character->getCowsInRange().size() == 0)
	{
		character->setBehaviour(new WanderingBehaviour(character));
		delete this;
	}
}

void FleeBehaviour::onExit()
{
	character->viewDistance /= 2;
	character->maxSpeed /= 2;
	character->maxForce /= 2;
}

void FleeBehaviour::onEnter()
{
	character->viewDistance *= 2;
	character->maxSpeed *= 2;
	character->maxForce *= 2;
}