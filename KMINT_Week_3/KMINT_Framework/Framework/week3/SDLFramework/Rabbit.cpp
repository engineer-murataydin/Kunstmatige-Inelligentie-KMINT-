#include "Rabbit.h"
#include "FWApplication.h"
#include "WanderingBehaviour.h"

Rabbit::Rabbit(Node* location) :Character(location)
{
	textureName = "rabbit-3.png";
	SetTexture(LoadTexture());
	SetSize(50, 50);

	behaviour = new WanderingBehaviour(this);
}


Rabbit::~Rabbit()
{
}

Node* Rabbit::move()
{
	return behaviour->move();
}

Node* Rabbit::moveRandom()
{
	Node* location = Node::getRandomConnectedNode(getLocation(), 100);
	setLocation(location);

	return location;
}

void Rabbit::Update(float deltaTime)
{
	behaviour->checkState();
}
