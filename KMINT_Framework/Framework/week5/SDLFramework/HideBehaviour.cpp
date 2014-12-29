#include "HideBehaviour.h"
#include "Cow.h"

HideBehaviour::HideBehaviour(Cow* character) :CharacterBehaviour(character)
{
	this->character = character;

	character->velocity = Vector2();
	name = "Hide";
}


HideBehaviour::~HideBehaviour()
{
}

Vector2* HideBehaviour::move()
{
	return character->getLocation();
}

void HideBehaviour::checkState()
{
	if (character->collideWith(character->getField()->getRabbit()))
	{
		character->getField()->restart();
	}
}