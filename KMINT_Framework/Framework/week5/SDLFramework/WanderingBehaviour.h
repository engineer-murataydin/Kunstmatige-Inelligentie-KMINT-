#pragma once
#include "CharacterBehaviour.h"
#include <random>

class Cow;

class WanderingBehaviour :
	public CharacterBehaviour
{
public:
	WanderingBehaviour(Cow* character);
	~WanderingBehaviour();
	virtual Vector2* move();
	virtual void checkState();

protected:
	uniform_int_distribution<int> chanse;
	Cow* character;
	virtual void onExit();
};

