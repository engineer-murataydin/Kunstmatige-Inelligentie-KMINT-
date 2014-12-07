#pragma once
#include "CharacterBehaviour.h"
class DeadBehaviour : public CharacterBehaviour
{
public:
	DeadBehaviour(Character* character);
	~DeadBehaviour();

	Node* move();
	void checkState();

private:
	int	stepsLeft;
};

