#pragma once

#include <vector>
#include "Rabbit.h"
#include "Cow.h"
#include "Weapon.h"
#include "Pill.h"

class Field
{
public:
	Field(double width, double heigth, SDL_Colour color);
	~Field();

	const double width;
	const double height;
	const SDL_Color color;

	void setRabbit(Rabbit* rabbit);
	void addCow(Cow* cow);

	vector<Cow*> getCows() const;
	Rabbit* getRabbit() const;
	Pill* getPill() const;
	Weapon* getWeapon() const;

	void init();
	void restart();

	Vector2 spawnRabbit;
	Vector2 spawnCow;

private:
	vector<Cow*> cows;
	Rabbit* rabbit;
	Pill* pill;
	Weapon* weapon;
};

