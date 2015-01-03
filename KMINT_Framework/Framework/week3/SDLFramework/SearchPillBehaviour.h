#pragma once
#include "CharacterBehaviour.h"

class Rabbit;

class SearchPillBehaviour :
	public CharacterBehaviour
{
public:
	SearchPillBehaviour(Rabbit* character);
	~SearchPillBehaviour();
	Node* move();
	void checkState();

protected:
	Rabbit* character;
};

