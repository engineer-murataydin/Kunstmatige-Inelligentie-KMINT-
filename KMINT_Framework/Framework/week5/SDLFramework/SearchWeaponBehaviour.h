#pragma once
#include "CharacterBehaviour.h"

class Cow;

class SearchWeaponBehaviour :
	public CharacterBehaviour
{
public:
	SearchWeaponBehaviour(Cow* character);
	~SearchWeaponBehaviour();
	Vector2* move();
	void checkState();

protected:
	Cow* character;
};

