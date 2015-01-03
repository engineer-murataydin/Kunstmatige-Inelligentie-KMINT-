#include "Rabbit.h"
#include "FWApplication.h"
#include "WanderingBehaviour.h"

Rabbit::Rabbit(Field* field, Vector2* location) :Character(field, location)
{
	textureName = "rabbit-3.png";
	SetTexture(LoadTexture());
	SetSize(50, 50);

	name = "Rabbit";

	viewDistance = 100;
	maxSpeed = 4;
	maxTurnRate = 2;
	behaviour = new WanderingBehaviour(this);
}

Rabbit::~Rabbit()
{
}
