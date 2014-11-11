#pragma once

#include "Node.h"
#include "IGameObject.h"

class Character : public IGameObject
{
public:
	Character(Node* location);
	virtual ~Character();

	virtual Node* move() = 0;
	Node* getLocation();
	void setLocation(Node* location);
private:
	Node* location;

};

