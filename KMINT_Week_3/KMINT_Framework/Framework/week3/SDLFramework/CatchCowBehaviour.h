#pragma once
#include "CharacterBehaviour.h"

class Rabbit;

class CatchCowBehaviour : public CharacterBehaviour
{
public:
	CatchCowBehaviour(Rabbit* character);
	~CatchCowBehaviour();
	Node* move();
	void checkState();

protected:
	Rabbit* character;
};

