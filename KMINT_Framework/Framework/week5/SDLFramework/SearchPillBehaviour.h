#pragma once
#include "CharacterBehaviour.h"

class Cow;

class SearchPillBehaviour :
	public CharacterBehaviour
{
public:
	SearchPillBehaviour(Cow* character);
	~SearchPillBehaviour();
	Vector2* move();
	void checkState();

protected:
	Cow* character;
};

