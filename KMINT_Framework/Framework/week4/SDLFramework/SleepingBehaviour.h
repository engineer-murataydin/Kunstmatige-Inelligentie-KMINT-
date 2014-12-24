#pragma once
#include "CharacterBehaviour.h"

class SleepingBehaviour : public CharacterBehaviour
{
public:
	SleepingBehaviour(Cow* character);
	~SleepingBehaviour();
	Vector2* move();
	void checkState();
	int count;
protected:
	Cow* character;
};

