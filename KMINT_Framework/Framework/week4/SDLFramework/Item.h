#pragma once
#include "IGameObject.h"
#include "Vector2.h"

class Item :
	public IGameObject
{
public:
	Item(Vector2* location);
	~Item();
	void Update(float deltatime);
	Vector2* getLocation();
	void setLocation(Vector2* location);
protected:
	Vector2* location;
};

