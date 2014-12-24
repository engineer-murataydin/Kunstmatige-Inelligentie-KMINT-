#include "Rabbit.h"
#include "FWApplication.h"
#include "WanderingBehaviour.h"

Rabbit::Rabbit(Field* field, Vector2* location, SDL_Color color) :Character(field, location, color)
{
	textureName = "rabbit-3.png";
	SetTexture(LoadTexture());
	SetSize(50, 50);

	name = "Rabbit";

	viewDistance = 100;
	maxSpeed = 10;
	maxTurnRate = 2;
	behaviour = new WanderingBehaviour(this);
}

Rabbit::~Rabbit()
{
}
