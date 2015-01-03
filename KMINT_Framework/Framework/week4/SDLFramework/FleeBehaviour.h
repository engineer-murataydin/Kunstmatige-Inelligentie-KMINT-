#pragma once
#include "CharacterBehaviour.h"

class Rabbit;

class FleeBehaviour : public CharacterBehaviour
{
public:
	FleeBehaviour(Rabbit* character);
	~FleeBehaviour();
	Vector2* move();
	void checkState();
	virtual void onExit();
	virtual void onEnter();
protected:
	Rabbit* character;
};

