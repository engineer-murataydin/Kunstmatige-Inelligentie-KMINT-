#include "WanderingBehaviour.h"
#include "SearchPillBehaviour.h"
#include "SearchWeaponBehaviour.h"
#include "FleeBehaviour.h"
#include "Character.h"
#include "Rabbit.h"
#include "Graph.h"
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
}

Node* WanderingBehaviour::move()
{
	if (chanse(dre) >= 30)
	{
		Node* location = character->getLocation();
		location = location->getRandomConnectedNode();
		character->setLocation(location);
	}
	return character->getLocation();
}

void WanderingBehaviour::checkState()
{
	if (!character->pill)
	{
		int random = chanse(dre);
		if (random <= character->chanseFlee)
		{
			character->setBehaviour(new FleeBehaviour(character));
			character->setChanse(&character->chanseFlee, &character->chanseSleepingPill, &character->chanseWeapon);
		}
		else if (random <= character->chanseFlee + character->chanseSleepingPill)
		{
			character->setBehaviour(new SearchPillBehaviour(character));
			character->setChanse(&character->chanseSleepingPill, &character->chanseFlee, &character->chanseWeapon);
		}
		else if (random <= character->chanseFlee + character->chanseSleepingPill + character->chanseWeapon)
		{
			character->setBehaviour(new SearchWeaponBehaviour(character));
			character->setChanse(&character->chanseWeapon, &character->chanseFlee, &character->chanseSleepingPill);
		}

		cout << "Nieuwe Kansen:" << endl;
		cout << "flee : " << character->chanseFlee << endl;
		cout << "pill : " << character->chanseSleepingPill << endl;
		cout << "weap : " << character->chanseWeapon << endl;
		cout << "\n" << endl;

		delete this;
	}
}
