#pragma once
#include "Character.h"
#include "Pill.h"
#include "Weapon.h"

class Rabbit :
	public Character
{
public:
	Rabbit(Node* location);
	~Rabbit();
	void Update(float deltaTime);
	Node* move();
	Node* moveRandom();
	Pill* pill;
	Weapon* weapon;

	double chanseSleepingPill;
	double chanseWeapon;
	double chanseFlee;

	void setChanse(double* decrease, double* increaseOne, double* increaseTwo);
};

