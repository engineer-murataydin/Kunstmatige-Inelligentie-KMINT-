#pragma once
#include "Node.h"

class Character;

class CharacterBehaviour
{
public:
	CharacterBehaviour(Character* character);
	virtual ~CharacterBehaviour();
	virtual Node* move() = 0;

protected:
	Character* character;
};

