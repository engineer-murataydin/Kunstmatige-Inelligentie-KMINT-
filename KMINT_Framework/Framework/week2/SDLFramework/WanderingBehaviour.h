#pragma once
#include "CharacterBehaviour.h"
class WanderingBehaviour :
	public CharacterBehaviour
{
public:
	WanderingBehaviour(Character* character);
	~WanderingBehaviour();
	Node* move();
};

