#pragma once
#include "Character.h"
#include "Pill.h"
#include "Weapon.h"

class Rabbit :
	public Character
{
public:
	Rabbit(Field* field, Vector2 location, SDL_Color color);
	~Rabbit();
};

