#pragma once
#include "Character.h"
#include <stack>

class Cow :
	public Character
{
public:
	Cow(Node* location);
	~Cow();

	Node* move();
	void Update(float deltaTime);
	stack<Node*> path;
	bool isHunting();

private:
	Node* previousGoal;
};

