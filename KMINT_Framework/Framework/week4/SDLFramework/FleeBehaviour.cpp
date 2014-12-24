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
	vector<Cow*> cowsInRange = getCowsInRange();
	if (cowsInRange.size() > 0)
	{
		for (size_t i = 0; i < cowsInRange.size(); i++)
		{
			avoid = avoid + *cowsInRange[i]->getLocation();
		}

		avoid = avoid / cowsInRange.size();

		Vector2 move = (avoid - *character->getLocation()) * -1;
		move.normalize();

		move = move * character->maxTurnRate;

		std::cout << move.getX() << ',' << move.getY() << endl;

		character->applyForce(move);
	}
	return character->getLocation();
}

vector<Cow*> FleeBehaviour::getCowsInRange()
{
	vector<Cow*> cowsInRange;
	vector<Cow*> cows = character->getField()->getCows();

	for (size_t i = 0; i < cows.size(); i++)
	{
		if (Utill::distanceBewteenPoints(*cows[i]->getLocation(), *character->getLocation()) < character->viewDistance)
		{
			cowsInRange.push_back(cows[i]);
		}
	}
	return cowsInRange;
}


void FleeBehaviour::checkState()
{
	if (getCowsInRange().size() == 0)
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