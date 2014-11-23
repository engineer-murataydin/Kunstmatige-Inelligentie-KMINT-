#pragma once
#include "CharacterBehaviour.h"
class SearchPillBehaviour :
	public CharacterBehaviour
{
public:
	SearchPillBehaviour(Character* character);
	~SearchPillBehaviour();
	Node* move();
};

