#pragma once
#include "Character.h"
#include "Rabbit.h"
#include "Dna.h"
#include <stack>

class Cow :
	public Character
{
public:
	Cow(Field* field, Vector2* location, Dna dna, SDL_Color color);
	~Cow();

	double minDistance;
private:
};

