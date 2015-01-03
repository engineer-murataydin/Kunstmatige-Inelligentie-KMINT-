#pragma once
#include "CharacterBehaviour.h"

class Cow;

class FleeBehaviour : public CharacterBehaviour
{
public:
	FleeBehaviour(Cow* character);
	~FleeBehaviour();
	Vector2* move();
	void checkState();
	virtual void onExit();
	virtual void onEnter();
protected:
	Cow* character;
};

