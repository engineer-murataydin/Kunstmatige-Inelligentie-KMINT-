#include "Character.h"
#include "CharacterBehaviour.h"
#include "Field.h"
#include "Utill.h"
#include "Cow.h"
#include <SDL.h>

Character::Character(Field* field, Vector2* location, SDL_Color color) : name("?"), field(field), color(color)
{
	this->location = new Vector2();
	setLocation(location);
	heading = Vector2(1, 0);
	side = Vector2(0, 1);
	mass = 10;
	maxTurnRate = 1;
	maxSpeed = 10;
	maxForce = 10;
	score = 0;
}


Character::~Character()
{
}

void Character::setLocation(Vector2* location)
{
	while (location->getX() < 0)
	{
		location->setX(location->getX() + field->width);
	}
	while (location->getY() < 0)
	{
		location->setY(location->getY() + field->height);
	}

	location->setX(fmod(location->getX(), field->width));
	location->setY(fmod(location->getY(), field->height));

	this->location->setX(location->getX());
	this->location->setY(location->getY());
	SetOffset(location->getX(), location->getY());
}

Vector2* Character::getLocation() const
{
	return location;
}

void Character::setBehaviour(CharacterBehaviour* behaviour)
{
	delete this->behaviour;
	this->behaviour = behaviour;
}

SDL_Texture* Character::LoadTexture()
{
	SDL_Texture* texture = FWApplication::GetInstance()->LoadTexture(textureName);
	SDL_SetTextureColorMod(texture, color.r, color.g, color.b);

	return texture;
}

string Character::getState() const
{
	return behaviour->getName();
}

string Character::getName() const
{
	return name;
}

void Character::Update(float deltaTime)
{
	move();

	behaviour->checkState();
}

Vector2* Character::move()
{
	behaviour->move();
	Vector2 newLocation = *location + velocity;
	setLocation(&newLocation);
	return location;
}


void Character::rotate(double deg)
{
	heading.rotate(deg);
	side.rotate(deg);
}
Field* Character::getField() const
{
	return field;
}

void Character::applyForce(Vector2 force)
{
	if (force.getLength() > maxForce)
	{
		force.normalize(maxForce);
	}
	velocity = velocity + force / mass;

	if (velocity.getLength() > maxSpeed)
	{
		velocity.normalize(maxSpeed);
	}
}

vector<Cow*> Character::getCowsInRange() const
{
	vector<Cow*> cowsInRange;
	vector<Cow*> cows = field->getCows();

	for (size_t i = 0; i < cows.size(); i++)
	{
		if (Utill::distanceBewteenPoints(*cows[i]->getLocation(), *getLocation()) < viewDistance)
		{
			if (cows[i] != this)
			{
				cowsInRange.push_back(cows[i]);
			}
		}
	}
	return cowsInRange;
}
