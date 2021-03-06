#include "SearchPillBehaviour.h"
#include "SearchWeaponBehaviour.h"
#include "WanderingBehaviour.h"
#include "Character.h"
#include "Cow.h"
#include <SDL.h>

SearchPillBehaviour::SearchPillBehaviour(Cow* character) : CharacterBehaviour(character)
{
	this->character = character;
	name = "SearchPill";
}

SearchPillBehaviour::~SearchPillBehaviour()
{
}

Vector2* SearchPillBehaviour::move()
{
	if (!character->pill)
	{
		Vector2 target = *character->getField()->getPill()->getLocation() - *character->getLocation();
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

void SearchPillBehaviour::checkState()
{
	if (character->collideWith(character->getField()->getRabbit()))
	{
		if (character->pill)
		{
			character->addScore(1);
		}
		else
		{
			character->getField()->getRabbit()->addScore(10);
		}
		character->getField()->restart();
	}
	else if (character->collideWith(character->getField()->getPill()))
	{
		character->pill = character->getField()->getPill();
		uniform_int_distribution<int> widthDist(0, character->getField()->width);
		uniform_int_distribution<int> heigthDist(0, character->getField()->height);
		character->pill->setLocation(Vector2(heigthDist(FWApplication::GetInstance()->dre), widthDist(FWApplication::GetInstance()->dre)));
	}
}