#include "DeadBehaviour.h"
#include "WanderingBehaviour.h"
#include "CatchRabbitBehaviour.h"
#include "Character.h"
#include "Rabbit.h"
#include <SDL.h>

DeadBehaviour::DeadBehaviour(Character* character) : CharacterBehaviour(character)
{
	this->character = character;
	SDL_Texture* texture = character->LoadTexture();
	SDL_SetTextureColorMod(texture, 50, 50, 50);
	character->SetTexture(texture);

	stepsLeft = 1;

	name = "Dead";
}

DeadBehaviour::~DeadBehaviour()
{
	onExit();
}

Vector2* DeadBehaviour::move()
{
	--stepsLeft;
	return character->getLocation();
}

void DeadBehaviour::checkState()
{
	if (stepsLeft <= 0)
	{
		if (character->getName() == "Rabbit"){
			character->setBehaviour(new WanderingBehaviour(dynamic_cast<Rabbit*>(character)));
		}
		else
		{
			character->setBehaviour(new CatchRabbitBehaviour(dynamic_cast<Cow*>(character)));
		}
	}
}

void DeadBehaviour::onExit()
{
}
