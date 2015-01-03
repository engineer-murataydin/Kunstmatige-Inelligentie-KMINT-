#include "WanderingBehaviour.h"
#include "SearchPillBehaviour.h"
#include "SearchWeaponBehaviour.h"
#include "HideBehaviour.h"
#include "FleeBehaviour.h"
#include "Character.h"
#include "Rabbit.h"
#include "Field.h"
#include "Cow.h"
#include "Utill.h"
#include <iostream>

WanderingBehaviour::WanderingBehaviour(Cow* character) : CharacterBehaviour(character)
{
	this->character = character;
	chanse = uniform_int_distribution<int>(1, 100);
	name = "Wandering";
}

WanderingBehaviour::~WanderingBehaviour()
{
	onExit();
}

Vector2* WanderingBehaviour::move()
{
	uniform_int_distribution<int> dist(-360, 360);
	int rotate = dist(FWApplication::GetInstance()->dre) * (M_PI / 180);


	Vector2 move(character->velocity);
	move.rotate(rotate);

	if (move.getLength() > character->maxForce)
	{
		move.normalize(character->maxForce);
	}

	character->applyForce(move);

	return character->getLocation();
}

void WanderingBehaviour::checkState()
{
	if (character->CheckCollision(character->getField()->getRabbit()))
	{
		character->getField()->getRabbit()->addScore(10);
		character->getField()->restart();
		return;
	}
	else if (Utill::distanceBewteenPoints(*character->getLocation(), *character->getField()->getRabbit()->getLocation()) < 300)
	{
		int  result = chanse(FWApplication::GetInstance()->dre);
		double* dna = character->dna.getDna();
		if (result <= dna[0])
		{
			character->setBehaviour(new FleeBehaviour(character));
		}
		else if (result <= dna[0] + dna[1])
		{
			character->setBehaviour(new SearchPillBehaviour(character));
		}
		else if (result <= dna[0] + dna[1] + dna[2])
		{
			character->setBehaviour(new HideBehaviour(character));
		}
		else if (result <= dna[0] + dna[1] + dna[2] + dna[3])
		{
			character->setBehaviour(new SearchWeaponBehaviour(character));
		}
	}
}

void WanderingBehaviour::onExit()
{

}