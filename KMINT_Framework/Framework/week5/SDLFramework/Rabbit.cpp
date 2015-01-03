#include "Rabbit.h"
#include "FWApplication.h"
#include "CatchCowBehaviour.h"

Rabbit::Rabbit(Field* field, Vector2 location, SDL_Color color) :Character(field, location, color)
{
	textureName = "rabbit-3.png";
	SetTexture(LoadTexture());
	SetSize(50, 50);

	name = "Rabbit";

	viewDistance = 100;
	maxSpeed = 10;
	maxTurnRate = 4;
	behaviour = new CatchCowBehaviour(this);
}

Rabbit::~Rabbit()
{
}
