#pragma once
#include "CharacterBehaviour.h"
class CatchRabbitBehaviour :
	public CharacterBehaviour
{
public:
	CatchRabbitBehaviour();
	~CatchRabbitBehaviour();
	Node* move();
};

