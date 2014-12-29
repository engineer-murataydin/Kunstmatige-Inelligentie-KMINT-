#pragma once

#include "Vector2.h"
#include "GameObject.h"
#include "Item.h"
#include <string>

class Cow;
class CharacterBehaviour;

using namespace std;

class Character : public GameObject
{
public:
	Character(Field* field, Vector2 location, SDL_Color color);
	virtual ~Character();

	virtual Vector2* move();
	void setBehaviour(CharacterBehaviour* behaviour);
	SDL_Texture* LoadTexture();
	string getState() const;
	string getName() const;
	virtual void Update(float deltaTime);
	virtual void applyForce(Vector2 force);

	virtual void reset(Vector2 pos);

	void addScore(int amount);
	int getScore();

	Vector2 velocity;
	Vector2 heading;
	Vector2 perp;
	Vector2 side;

	double maxForce;
	double mass;
	double maxSpeed;
	double maxTurnRate;

	SDL_Color color;


	double viewDistance;

	bool collideWith(GameObject* character);

	virtual void reset();
protected:
	string name;
	CharacterBehaviour* behaviour;
	string textureName;
	int score;

	void rotate(double deg);
};

