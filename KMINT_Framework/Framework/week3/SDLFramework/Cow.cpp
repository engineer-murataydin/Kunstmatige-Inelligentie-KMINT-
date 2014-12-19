#include "Cow.h"
#include "Graph.h"
#include "CatchRabbitBehaviour.h"

Cow::Cow(Node* location) : Character(location)
{
	textureName = "cow-1.png";
	SetTexture(LoadTexture());
	SetSize(50, 50);
	behaviour = new CatchRabbitBehaviour(this);
	name = "Cow";
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
	return behaviour->move();
}

bool Cow::isHunting()
{
	return behaviour->getName() == "CatchRabbit";
}