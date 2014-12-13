#pragma once
#include "CharacterBehaviour.h"

class Rabbit;

class WanderingBehaviour :
	public CharacterBehaviour
{
public:
	WanderingBehaviour(Rabbit* character);
	~WanderingBehaviour();
	virtual Node* move();
	virtual void checkState();

protected:
	default_random_engine dre;
	uniform_int_distribution<int> chanse;
	Rabbit* character; //check!!------------------------------------------------------------------------------------

};

