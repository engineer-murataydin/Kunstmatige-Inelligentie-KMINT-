#include "SearchWeaponBehaviour.h"
#include "CatchCowBehaviour.h"
#include "Character.h"
#include "Rabbit.h"
#include <SDL.h>

SearchWeaponBehaviour::SearchWeaponBehaviour(Rabbit* character) : CharacterBehaviour(character)
{
	this->character = character;
	SDL_Texture* texture = character->LoadTexture();
	SDL_SetTextureColorMod(texture, 100, 0, 0);
	character->SetTexture(texture);
	name = "SearchWeapon";
}


SearchWeaponBehaviour::~SearchWeaponBehaviour()
{
}

Vector2* SearchWeaponBehaviour::move()
{
	return character->getLocation();
}

void SearchWeaponBehaviour::checkState()
{

}
