#pragma once
#include "Item.h"

class Weapon : public Item
{
public:
	Weapon(Vector2* position, SDL_Color color);
	~Weapon();
};

