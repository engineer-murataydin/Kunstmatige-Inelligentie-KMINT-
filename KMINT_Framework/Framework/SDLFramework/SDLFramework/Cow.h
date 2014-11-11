#pragma once
#include "Character.h"
#include <stack>

class Cow :
	public Character
{
public:
	Cow(Node* location);
	~Cow();

	Node* move(Node* destination);
	Node* move(){ return NULL; };
	void Update(float deltaTime);
	stack<Node*> path;

private:
	Node* previousGoal;
};

