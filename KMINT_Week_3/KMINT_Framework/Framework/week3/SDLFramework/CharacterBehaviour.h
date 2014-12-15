#pragma once
#include "Node.h"
#include <string>

class Character;

class CharacterBehaviour
{
public:
	CharacterBehaviour(Character* character);
	virtual ~CharacterBehaviour();
	virtual Node* move() = 0;
	virtual void checkState() = 0;
	virtual string getName();
protected:
	string name;
	Character* character;
	virtual void onEnter();
	virtual void onExit();
};

