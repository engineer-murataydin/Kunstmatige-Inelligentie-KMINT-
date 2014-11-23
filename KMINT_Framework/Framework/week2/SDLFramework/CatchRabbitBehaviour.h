#pragma once
#include "CharacterBehaviour.h"
class CatchRabbitBehaviour :
	public CharacterBehaviour
{
public:
	CatchRabbitBehaviour(Character* character);
	~CatchRabbitBehaviour();
	Node* move();
	void checkState();
};

