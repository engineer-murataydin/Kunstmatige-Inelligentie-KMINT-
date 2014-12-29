#include "FleeBehaviour.h"
#include "WanderingBehaviour.h"
#include "Character.h"
#include "Rabbit.h"
#include "Cow.h"
#include "Utill.h"

#include <iostream>

FleeBehaviour::FleeBehaviour(Cow* character) : CharacterBehaviour(character)
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
	Vector2 avoid = (*character->getField()->getRabbit()->getLocation() - *character->getLocation()) * -1;

	avoid.normalize(character->maxTurnRate);

	character->applyForce(avoid);

	return character->getLocation();
}

void FleeBehaviour::checkState()
{
	if (character->collideWith(character->getField()->getRabbit()))
	{
		Field* field = character->getField();
		field->getRabbit()->addScore(10);
		field->restart();
	}
}
void FleeBehaviour::onExit()
{

}

void FleeBehaviour::onEnter()
{

}