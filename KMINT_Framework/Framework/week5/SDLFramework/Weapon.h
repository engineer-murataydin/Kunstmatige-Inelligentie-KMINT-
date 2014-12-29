#pragma once
#include "Item.h"

class Weapon : public Item
{
public:
	Weapon(Field* field, Vector2 position, SDL_Color color);
	~Weapon();
};

