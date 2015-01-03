#include "SearchPillBehaviour.h"
#include "SearchWeaponBehaviour.h"
#include "WanderingBehaviour.h"
#include "Character.h"
#include "Rabbit.h"
#include <SDL.h>

SearchPillBehaviour::SearchPillBehaviour(Rabbit* character) : CharacterBehaviour(character)
{
	this->character = character;
	SDL_Texture* texture = character->LoadTexture();
	SDL_SetTextureColorMod(texture, 0, 100, 0);
	character->SetTexture(texture);
	this->character = character;
	name = "SearchPill";
}

SearchPillBehaviour::~SearchPillBehaviour()
{
}

Vector2* SearchPillBehaviour::move()
{
	return character->getLocation();
}

void SearchPillBehaviour::checkState()
{

}