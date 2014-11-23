#include "Cow.h"
#include "Graph.h"
#include "WanderingBehaviour.h"

Cow::Cow(Node* location) : Character(location)
{
	SetTexture(FWApplication::GetInstance()->LoadTexture("cow-1.png"));
	SetSize(50, 50);

	behaviour = new WanderingBehaviour(this);
}


Cow::~Cow()
{
	previousGoal = nullptr;
}

void Cow::Update(float deltaTime)
{

}

Node* Cow::move(Node* destination)
{
	/*if (path.empty() || previousGoal != destination)
	{
		path = Graph::CreatePath(getLocation(), destination);
	}

	previousGoal = destination;

	if (!path.empty())
	{
		setLocation(path.top());
		path.pop();
	}
	SetOffset(getLocation()->x, getLocation()->y);
	return getLocation();*/

	return behaviour->move();
}
