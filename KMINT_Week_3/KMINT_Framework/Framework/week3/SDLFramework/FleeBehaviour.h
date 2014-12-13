#pragma once
#include "CharacterBehaviour.h"
class FleeBehaviour : public CharacterBehaviour
{
public:
	FleeBehaviour(Character* character);
	~FleeBehaviour();
	Node* move();
	void checkState();
};

