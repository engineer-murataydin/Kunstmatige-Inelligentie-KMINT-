#pragma once
#include "CharacterBehaviour.h"

class Rabbit;

class SearchWeaponBehaviour :
	public CharacterBehaviour
{
public:
	SearchWeaponBehaviour(Rabbit* character);
	~SearchWeaponBehaviour();
	Vector2* move();
	void checkState();

protected:
	Rabbit* character;
};

