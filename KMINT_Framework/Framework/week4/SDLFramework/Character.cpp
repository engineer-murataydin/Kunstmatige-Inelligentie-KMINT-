#include "Character.h"
#include "CharacterBehaviour.h"
#include "Field.h"

Character::Character(Field* field, Vector2* location) : name("?"), field(field)
{
	this->location = new Vector2();
	setLocation(location);
	heading = Vector2(1, 0);
	side = Vector2(0, 1);
	mass = 10;
	maxTurnRate = 1;
	maxSpeed = 10;
	maxForce = 10;
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
	SetOffset(this->location->getX(), this->location->getY());
}

Vector2* Character::getLocation()
{
	return location;
}

void Character::setBehaviour(CharacterBehaviour* behaviour)
{
	this->behaviour = behaviour;
}

SDL_Texture* Character::LoadTexture()
{
	return FWApplication::GetInstance()->LoadTexture(textureName);
}

string Character::getState()
{
	return behaviour->getName();
}

string Character::getName()
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