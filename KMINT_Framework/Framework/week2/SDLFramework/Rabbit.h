#pragma once
#include "Character.h"


class Rabbit :
	public Character
{
public:
	Rabbit(Node* location);
	~Rabbit();
	void Update(float deltaTime);
	Node* move();
	Node* moveRandom();
};

