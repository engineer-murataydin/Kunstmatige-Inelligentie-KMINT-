#pragma once
#include "CharacterBehaviour.h"

class SleepingBehaviour : public CharacterBehaviour
{
public:
	SleepingBehaviour(Character* character);
	~SleepingBehaviour();
	Vector2* move();
	void checkState();
	int count;
};

