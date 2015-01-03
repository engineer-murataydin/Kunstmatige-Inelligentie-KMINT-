#include "Cow.h"
#include "WanderingBehaviour.h"
#include <SDL.h>

Cow::Cow(Field* field, Vector2 location, Dna dna, SDL_Color color) : Character(field, location, color), dna(dna)
{
	textureName = "cow-1.png";
	SetTexture(LoadTexture());
	SetSize(50, 50);
	behaviour = new WanderingBehaviour(this);
	name = "Cow";
	maxSpeed = 5;
	maxTurnRate = 4;
	//mass = 10;
	viewDistance = 50;


}

Cow::~Cow()
{
}

void Cow::reset(Vector2 location)
{
	Character::reset(location);
	if (!pill)
	{
		setBehaviour(new WanderingBehaviour(this));
	}
}

void Cow::reset()
{
	weapon = nullptr;
	pill = nullptr;
	Character::reset();
}