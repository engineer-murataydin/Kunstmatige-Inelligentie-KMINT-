#pragma once
#include "CharacterBehaviour.h"
class CatchRabbitBehaviour :
	public CharacterBehaviour
{
public:
	CatchRabbitBehaviour(Cow* character);
	~CatchRabbitBehaviour();
	Vector2 moveToRabbit();
	Vector2 stayInGroup();

	Vector2* move();
	void checkState();

protected:
	Cow* character;
};

