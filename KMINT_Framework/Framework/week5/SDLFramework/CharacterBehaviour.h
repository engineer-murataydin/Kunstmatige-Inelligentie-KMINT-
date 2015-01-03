#pragma once
#include <string>
#include "Vector2.h"
#include "Field.h"
#include "Utill.h"

class Character;

using namespace std;

class CharacterBehaviour
{
public:
	CharacterBehaviour(Character* character);
	virtual ~CharacterBehaviour();
	virtual Vector2* move();
	virtual void checkState() = 0;
	virtual string getName();
protected:
	string name;
	Character* character;
	virtual void onEnter();
	virtual void onExit();
};

