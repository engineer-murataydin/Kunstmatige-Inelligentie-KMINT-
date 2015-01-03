#pragma once
#include "GameObject.h"
#include "Vector2.h"
#include "Field.h"

class Item :
	public GameObject
{
public:
	Item(Field* field, Vector2 location);
	~Item();
	void Update(float deltatime);
protected:
};

