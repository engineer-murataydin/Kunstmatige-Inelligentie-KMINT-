#pragma once

#include "Vector2.h"
#include "IGameObject.h"
#include "Item.h"
#include <string>

class Field;
class CharacterBehaviour;

using namespace std;

class Character : public IGameObject
{
public:
	Character(Field* field, Vector2* location);
	virtual ~Character();

	virtual Vector2* move();
	Vector2* getLocation();
	void setLocation(Vector2* location);
	void setBehaviour(CharacterBehaviour* behaviour);
	SDL_Texture* LoadTexture();
	string getState();
	string getName();
	virtual void Update(float deltaTime);
	virtual void applyForce(Vector2 force);

	Vector2 velocity;
	Vector2 heading;
	Vector2 perp;
	Vector2 side;

	double maxForce;
	double mass;
	double maxSpeed;
	double maxTurnRate;

	double viewDistance;
	Vector2* location;
	Field* getField() const;

protected:
	Field* field;
	string name;
	CharacterBehaviour* behaviour;
	string textureName;

	void rotate(double deg);
};

