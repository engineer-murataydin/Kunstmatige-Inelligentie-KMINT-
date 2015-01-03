#include "Character.h"
#include "CharacterBehaviour.h"
#include "Utill.h"
#include "Cow.h"
#include <SDL.h>

Character::Character(Field* field, Vector2 location, SDL_Color color) : GameObject(field), name("?"), color(color)
{
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
	setLocation(newLocation);
	return location;
}


void Character::rotate(double deg)
{
	heading.rotate(deg);
	side.rotate(deg);
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

void Character::reset(Vector2 pos)
{
	setLocation(pos);
	velocity = Vector2();
}

bool Character::collideWith(GameObject* object)
{
	if (object == this)
	{
		return false;
	}

	return Utill::distanceBewteenPoints(*getLocation(), *object->getLocation()) < 50;
}

int Character::getScore()
{
	return score;
}

void Character::addScore(int amount)
{
	if (amount < 0)
	{
		return;
	}
	score += amount;
}

void Character::reset()
{
	score = 0;
	velocity = Vector2();
}