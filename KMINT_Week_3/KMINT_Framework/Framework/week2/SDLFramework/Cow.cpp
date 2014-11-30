#include "Cow.h"
#include "Graph.h"
#include "WanderingBehaviour.h"

Cow::Cow(Node* location) : Character(location)
{
	textureName = "cow-1.png";
	SetTexture(LoadTexture());
	SetSize(50, 50);
	behaviour = new WanderingBehaviour(this);
}


Cow::~Cow()
{
	previousGoal = nullptr;
}

void Cow::Update(float deltaTime)
{
	behaviour->checkState();
}

Node* Cow::move()
{
	if (!isBored())
	{
		bored += 25;
	}
	return behaviour->move();
}
