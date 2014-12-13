#pragma once
#include "CharacterBehaviour.h"

class SleepingBehaviour : public CharacterBehaviour
{
public:
	SleepingBehaviour(Character* character);
	~SleepingBehaviour();
	Node* move();
	void checkState();
	int count;
};

