#include "CatchRabbitBehaviour.h"
#include "WanderingBehaviour.h"
#include "DeadBehaviour.h"
#include "SleepingBehaviour.h"
#include "Character.h"
#include "Rabbit.h"
#include "Cow.h"
#include "Field.h"

#include <iostream>
using namespace std;

CatchRabbitBehaviour::CatchRabbitBehaviour(Cow* character) : CharacterBehaviour(character)
{
	SDL_Texture* texture = character->LoadTexture();
	//SDL_SetTextureColorMod(texture, 0, 0, 100);
	this->character = character;
	character->SetTexture(texture);
	name = "CatchRabbit";
}

CatchRabbitBehaviour::~CatchRabbitBehaviour()
{
}

Vector2* CatchRabbitBehaviour::move()
{
	Vector2 rabbit = moveToRabbit();
	Vector2 group = stayInGroup();

	Vector2 move = rabbit + group;
	move.normalize(character->maxForce);

	character->applyForce(move);
	return character->getLocation();
}

Vector2 CatchRabbitBehaviour::stayInGroup()
{
	vector<Cow*> cowsInRange = character->getCowsInRange();
	Vector2 center;
	if (cowsInRange.size() > 0)
	{
		for (size_t i = 0; i < cowsInRange.size(); i++)
		{
			Vector2 dif = *cowsInRange[i]->getLocation() - *character->getLocation();
			Vector2 dist = dif*-1;
			dist.normalize(character->minDistance);
			dif = dist - dif;

			center = center + dif;
		}
		center = center / cowsInRange.size();
		center.normalize(character->maxForce);
	}
	return center;
}

Vector2 CatchRabbitBehaviour::moveToRabbit()
{
	int steps = 10;
	Rabbit* goal = character->getField()->getRabbit();
	Vector2 target = *goal->getLocation();
	for (int i = 0; i < steps; i++)
	{
		target = target + goal->velocity;
		FWApplication::GetInstance()->DrawRect(target.getX(), target.getY(), 10, 10, true);
	}
	target = target - *character->getLocation();

	Vector2 move(target);
	move.normalize(character->maxTurnRate);
	return move;
}

void CatchRabbitBehaviour::checkState()
{

}