#pragma once
#include "CharacterBehaviour.h"

class Rabbit;

class CatchCowBehaviour : public CharacterBehaviour
{
public:
	CatchCowBehaviour(Rabbit* character);
	~CatchCowBehaviour();
	Vector2* move();
	void checkState();

protected:
	void virtual onExit();
	Rabbit* character;
};

