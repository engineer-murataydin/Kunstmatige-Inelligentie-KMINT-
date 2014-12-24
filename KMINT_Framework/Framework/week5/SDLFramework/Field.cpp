#include "Field.h"
#include "Utill.h"

Field::Field(double width, double height, SDL_Color color) :width(width), height(height), color(color)
{
	spawnRabbit = Vector2{ height / 2, width - 200 };
	spawnCow = Vector2{ height / 2, 200 };
}


Field::~Field()
{
}


vector<Cow*> Field::getCows() const
{
	return cows;
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

void Field::addCow(Cow* cow)
{
	cows.push_back(cow);
}

void Field::init()
{
	FWApplication* app = FWApplication::GetInstance();
	rabbit = new Rabbit(this, new Vector2(spawnRabbit), color);
	app->AddRenderable(rabbit);

	addCow(new Cow(this, new Vector2(spawnCow), Dna(), color));
	app->AddRenderable(cows[cows.size() - 1]);


}


void Field::restart()
{
	rabbit->setLocation(&spawnRabbit);
	for (size_t i = 0; i < cows.size(); i++)
	{
		cows[i]->setLocation(&spawnCow);
	}
}
