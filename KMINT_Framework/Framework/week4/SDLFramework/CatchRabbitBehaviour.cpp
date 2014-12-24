#include "CatchRabbitBehaviour.h"
#include "WanderingBehaviour.h"
#include "DeadBehaviour.h"
#include "SleepingBehaviour.h"
#include "Character.h"
#include "Rabbit.h"
#include "Field.h"

#include <iostream>
using namespace std;

CatchRabbitBehaviour::CatchRabbitBehaviour(Character* character) : CharacterBehaviour(character)
{
	SDL_Texture* texture = character->LoadTexture();
	//SDL_SetTextureColorMod(texture, 0, 0, 100);
	character->SetTexture(texture);
	name = "CatchRabbit";
}

CatchRabbitBehaviour::~CatchRabbitBehaviour()
{
}

Vector2* CatchRabbitBehaviour::move()
{
	Vector2 rabbit = moveToRabbit();

	character->applyForce(rabbit);
	return character->getLocation();
}

Vector2 CatchRabbitBehaviour::moveToRabbit()
{

	Rabbit* goal = character->getField()->getRabbit();
	Vector2 target = *goal->getLocation() - *character->getLocation();
	Vector2 move;
	if (target.getX() > 0)
	{
		move.setX(character->maxTurnRate);
	}
	else if (target.getX() < 0)
	{
		move.setX(-character->maxTurnRate);
	}
	if (target.getY() > 0)
	{
		move.setY(character->maxTurnRate);
	}
	else if (target.getY() < 0)
	{
		move.setY(-character->maxTurnRate);
	}
	return move;
}

void CatchRabbitBehaviour::checkState()
{

}