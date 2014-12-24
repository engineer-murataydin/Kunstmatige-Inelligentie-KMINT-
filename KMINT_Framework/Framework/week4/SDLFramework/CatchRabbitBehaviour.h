#pragma once
#include "CharacterBehaviour.h"
class CatchRabbitBehaviour :
	public CharacterBehaviour
{
public:
	CatchRabbitBehaviour(Character* character);
	~CatchRabbitBehaviour();
	Vector2 moveToRabbit();

	Vector2* move();
	void checkState();
};

