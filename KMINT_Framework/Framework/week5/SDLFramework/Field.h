#pragma once

#include <vector>
#include <SDL.h>
#include "Vector2.h"

class Cow;
class Rabbit;
class Weapon;
class Pill;
class Dna;

class Field
{
public:
	Field(double width, double heigth, SDL_Colour color);
	~Field();

	const double width;
	const double height;
	const SDL_Color color;

	void setRabbit(Rabbit* rabbit);
	void setCow(Cow* cow);

	Cow* getCow() const;
	Rabbit* getRabbit() const;
	Pill* getPill() const;
	Weapon* getWeapon() const;

	void init();
	void restart();

	Vector2 spawnRabbit;
	Vector2 spawnCow;

	int getScore() const;

	void reset(Dna* dna);
private:
	Cow* cow;
	Rabbit* rabbit;
	Pill* pill;
	Weapon* weapon;
};

