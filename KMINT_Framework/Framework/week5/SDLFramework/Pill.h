#pragma once
#include "Item.h"

class Pill : public Item
{
public:
	Pill(Vector2* position, SDL_Color color);
	~Pill();
};

