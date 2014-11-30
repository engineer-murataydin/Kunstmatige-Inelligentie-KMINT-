#pragma once
#include "CharacterBehaviour.h"
class WanderingBehaviour :
	public CharacterBehaviour
{
public:
	WanderingBehaviour(Character* character);
	~WanderingBehaviour();
	virtual Node* move();
	virtual void checkState();

protected:
	default_random_engine dre;
	uniform_int_distribution<int> chanse;
};

