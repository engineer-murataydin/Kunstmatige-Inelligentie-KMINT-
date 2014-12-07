#pragma once
#include "CharacterBehaviour.h"
class SearchWeaponBehaviour :
	public CharacterBehaviour
{
public:
	SearchWeaponBehaviour(Character* character);
	~SearchWeaponBehaviour();
	Node* move();
	void checkState();
};

