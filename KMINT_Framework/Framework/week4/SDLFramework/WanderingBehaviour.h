#pragma once
#include "CharacterBehaviour.h"
#include <random>

class Rabbit;
class Cow;

class WanderingBehaviour :
	public CharacterBehaviour
{
public:
	WanderingBehaviour(Rabbit* character);
	~WanderingBehaviour();
	virtual Vector2* move();
	virtual void checkState();

protected:
	default_random_engine dre;
	uniform_int_distribution<int> chanse;
	Rabbit* character;
	virtual void onExit();
};

