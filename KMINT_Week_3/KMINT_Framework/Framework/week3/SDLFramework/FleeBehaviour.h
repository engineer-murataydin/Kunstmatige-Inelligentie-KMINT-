#pragma once
#include "CharacterBehaviour.h"

class Rabbit;

class FleeBehaviour : public CharacterBehaviour
{
public:
	FleeBehaviour(Rabbit* character);
	~FleeBehaviour();
	Node* move();
	void checkState();

protected:
	Rabbit* character;
};

