#pragma once
#include "IGameObject.h"
#include "Node.h"

class Item :
	public IGameObject
{
public:
	Item(Node* location);
	~Item();
	void Update(float deltatime);
	Node* getLocation();
	void setLocation(Node* location);
protected:
	Node* location;
};

