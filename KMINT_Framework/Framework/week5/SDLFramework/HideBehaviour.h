#pragma once
#include "CharacterBehaviour.h"


class Cow;

class HideBehaviour :
	public CharacterBehaviour
{
public:
	HideBehaviour(Cow* character);
	virtual ~HideBehaviour();
	virtual Vector2* move();
	virtual void checkState();

protected:
	Cow* character;
};

