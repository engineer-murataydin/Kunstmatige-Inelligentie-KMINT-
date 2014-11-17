#include "Rabbit.h"
#include "FWApplication.h"

Rabbit::Rabbit(Node* location) :Character(location)
{
	SetTexture(FWApplication::GetInstance()->LoadTexture("rabbit-3.png"));
	SetSize(50, 50);
}


Rabbit::~Rabbit()
{
}

Node* Rabbit::move()
{
	Node* temp = getLocation();
	while (temp == getLocation())
	{
		for (int i = 0; i < 100; i++)
		{
			setLocation(getLocation()->getRandomConnectedNode());
		}
	}
	SetOffset(getLocation()->x, getLocation()->y);
	return getLocation();
}

void Rabbit::Update(float deltaTime)
{

}
