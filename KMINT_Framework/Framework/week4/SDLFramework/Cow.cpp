#include "Cow.h"
#include "CatchRabbitBehaviour.h"

Cow::Cow(Field* field, Vector2* location) : Character(field, location)
{
	textureName = "cow-1.png";
	SetTexture(LoadTexture());
	SetSize(50, 50);
	behaviour = new CatchRabbitBehaviour(this);
	name = "Cow";
	maxSpeed = 5;
	maxTurnRate = 1;
	mass = 10;
	minDistance = 1;
	viewDistance = 50;
}

Cow::~Cow()
{
}