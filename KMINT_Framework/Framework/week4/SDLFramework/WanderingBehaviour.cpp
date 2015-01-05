#include "WanderingBehaviour.h"
#include "SearchPillBehaviour.h"
#include "SearchWeaponBehaviour.h"
#include "FleeBehaviour.h"
#include "Character.h"
#include "Rabbit.h"
#include "Field.h"
#include "Cow.h"
#include "Utill.h"
#include <iostream>

WanderingBehaviour::WanderingBehaviour(Rabbit* character) : CharacterBehaviour(character)
{
	this->character = character;
	chanse = uniform_int_distribution<int>(0, 100);
	SDL_Texture* texture = character->LoadTexture();
	//SDL_SetTextureColorMod(texture, 0, 0, 0);
	character->SetTexture(texture);
	name = "Wandering";
}

WanderingBehaviour::~WanderingBehaviour()
{
	onExit();
}

Vector2* WanderingBehaviour::move()
{
	uniform_int_distribution<int> dist(0, 360);
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
	vector<Cow*> cows = character->getField()->getCows();
	for (size_t i = 0; i < cows.size(); i++)
	{
		if (Utill::distanceBewteenPoints(*cows[i]->getLocation(), *character->getLocation()) < character->viewDistance)
		{
			character->setBehaviour(new FleeBehaviour(character));
			delete this;
			break;
		}
	}
}

void WanderingBehaviour::onExit()
{

}