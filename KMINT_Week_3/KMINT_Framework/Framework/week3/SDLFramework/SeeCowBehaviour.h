#pragma once
#include "CharacterBehaviour.h"

class Rabbit;

class SeeCowBehaviour : public CharacterBehaviour
{
public:
	SeeCowBehaviour(Rabbit* character);
	~SeeCowBehaviour();
	Node* move();
	void checkState();

protected:
	Rabbit* character;
};

