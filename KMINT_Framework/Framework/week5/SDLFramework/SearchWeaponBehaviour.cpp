#include "SearchWeaponBehaviour.h"
#include "CatchCowBehaviour.h"
#include "Character.h"
#include "Cow.h"
#include <SDL.h>

SearchWeaponBehaviour::SearchWeaponBehaviour(Cow* character) : CharacterBehaviour(character)
{
	this->character = character;
	name = "SearchWeapon";
}


SearchWeaponBehaviour::~SearchWeaponBehaviour()
{
}

Vector2* SearchWeaponBehaviour::move()
{
	if (!character->weapon)
	{
		Vector2 target = *character->getField()->getWeapon()->getLocation() - *character->getLocation();
		if (target.getLength() > 100)
		{
			Vector2 avoid = (*character->getField()->getRabbit()->getLocation() - *character->getLocation()) * -1;

			target.normalize();
			avoid.normalize();
			Vector2 move = target + avoid;
			move.normalize(character->maxTurnRate);

			character->applyForce(move);
		}
		else
		{
			target.normalize(character->maxTurnRate);
			character->applyForce(target);
		}
	}
	else
	{
		character->velocity = Vector2();
	}
	return character->getLocation();
}

void SearchWeaponBehaviour::checkState()
{
	if (character->collideWith(character->getField()->getRabbit()))
	{
		if (!character->weapon)
		{
			character->getField()->getRabbit()->addScore(10);
		}
		else
		{
			character->weapon = nullptr;
		}
		character->getField()->restart();
	}
	else if (character->collideWith(character->getField()->getWeapon()))
	{
		character->weapon = character->getField()->getWeapon();
		uniform_int_distribution<int> widthDist(0, character->getField()->width);
		uniform_int_distribution<int> heigthDist(0, character->getField()->height);
		character->weapon->setLocation(Vector2(heigthDist(FWApplication::GetInstance()->dre), widthDist(FWApplication::GetInstance()->dre)));
	}
}
