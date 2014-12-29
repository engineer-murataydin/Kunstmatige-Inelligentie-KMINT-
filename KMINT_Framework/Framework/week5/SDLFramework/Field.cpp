#include "Field.h"
#include "Utill.h"
#include "WanderingBehaviour.h"
#include "Rabbit.h"
#include "Cow.h"
#include "Weapon.h"
#include "Pill.h"
#include "Dna.h"

Field::Field(double width, double height, SDL_Color color) :width(width), height(height), color(color)
{
	spawnRabbit = Vector2{ height / 2, width - 200 };
	spawnCow = Vector2{ height / 2, 200 };
}


Field::~Field()
{
}


Cow* Field::getCow() const
{
	return cow;
}

Rabbit* Field::getRabbit() const
{
	return rabbit;
}

Pill* Field::getPill() const
{
	return pill;
}

Weapon* Field::getWeapon() const
{
	return weapon;
}

void Field::setRabbit(Rabbit* rabbit)
{
	this->rabbit = rabbit;
}

void Field::setCow(Cow* cow)
{
	this->cow = cow;
}

void Field::init()
{
	FWApplication* app = FWApplication::GetInstance();

	uniform_int_distribution<int> widthDist(0, width);
	uniform_int_distribution<int> heightDist(0, height);

	rabbit = new Rabbit(this, spawnRabbit, color);
	app->AddRenderable(rabbit);

	cow = new Cow(this, spawnCow, Dna(), color);
	app->AddRenderable(cow);

	pill = new Pill(this, Vector2(heightDist(app->dre), widthDist(app->dre)), color);
	app->AddRenderable(pill);

	weapon = new Weapon(this, Vector2(heightDist(app->dre), widthDist(app->dre)), color);
	app->AddRenderable(weapon);
}


void Field::restart()
{
	rabbit->reset(spawnRabbit);
	cow->reset(spawnCow);
}

int Field::getScore() const
{
	return cow->getScore() - rabbit->getScore();
}

void Field::reset(Dna* dna)
{
	cow->dna = *dna;
	cow->reset();
	rabbit->reset();
	restart();

	uniform_int_distribution<int> widthDist(0, width);
	uniform_int_distribution<int> heightDist(0, height);

	pill->setLocation(Vector2(heightDist(FWApplication::GetInstance()->dre), widthDist(FWApplication::GetInstance()->dre)));
	weapon->setLocation(Vector2(heightDist(FWApplication::GetInstance()->dre), widthDist(FWApplication::GetInstance()->dre)));

}
