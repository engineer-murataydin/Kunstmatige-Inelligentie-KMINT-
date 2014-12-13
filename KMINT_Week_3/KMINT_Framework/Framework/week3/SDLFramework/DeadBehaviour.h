#pragma once
#include "CharacterBehaviour.h"
class Rabbit;

class DeadBehaviour : public CharacterBehaviour
{
public:
	DeadBehaviour(Rabbit* character);
	~DeadBehaviour();

	Node* move();
	void checkState();

private:
	int	stepsLeft;

protected:
	Rabbit* character;
};

