#pragma once

#include "Vector2.h"
#include "IGameObject.h"
#include "Item.h"
#include <string>

class Cow;
class Field;
class CharacterBehaviour;

using namespace std;

class Character : public IGameObject
{
public:
	Character(Field* field, Vector2* location, SDL_Color color);
	virtual ~Character();

	virtual Vector2* move();
	Vector2* getLocation() const;
	void setLocation(Vector2* location);
	void setBehaviour(CharacterBehaviour* behaviour);
	SDL_Texture* LoadTexture();
	string getState() const;
	string getName() const;
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

	SDL_Color color;

	int score;

	double viewDistance;
	Vector2* location;
	Field* getField() const;

	vector<Cow*> getCowsInRange() const;

protected:
	Field* field;
	string name;
	CharacterBehaviour* behaviour;
	string textureName;

	void rotate(double deg);
};

