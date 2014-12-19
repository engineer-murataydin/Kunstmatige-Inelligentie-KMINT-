#include "Rabbit.h"
#include "FWApplication.h"
#include "WanderingBehaviour.h"

Rabbit::Rabbit(Node* location) :Character(location)
{
	textureName = "rabbit-3.png";
	SetTexture(LoadTexture());
	SetSize(50, 50);

	behaviour = new WanderingBehaviour(this);

	chanseFlee = 33;
	chanseSleepingPill = 33;
	chanseWeapon = 33;
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

void Rabbit::setChanse(double* decrease, double* increaseOne, double* increaseTwo)
{
	double remove = *decrease * 0.25;
	*decrease -= remove;
	*increaseOne += 0.5 * remove;
	*increaseTwo += 0.5 * remove;
}
