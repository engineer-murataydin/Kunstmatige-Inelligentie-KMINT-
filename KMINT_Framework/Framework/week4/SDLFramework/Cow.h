#pragma once
#include "Character.h"
#include "Rabbit.h"
#include <stack>

class Cow :
	public Character
{
public:
	Cow(Field* field, Vector2* location);
	~Cow();

	double minDistance;
private:
};

