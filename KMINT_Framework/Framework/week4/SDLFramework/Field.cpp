#include "Field.h"

Field::Field(double width, double height) :width(width), height(height)
{
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

void Field::setRabbit(Rabbit* rabbit)
{
	this->rabbit = rabbit;
}

void Field::addCow(Cow* cow)
{
	cows.push_back(cow);
}

void Field::init(int cowAmount)
{
	FWApplication* app = FWApplication::GetInstance();
	rabbit = new Rabbit(this, new Vector2{ width / 2, height / 2 });
	app->AddRenderable(rabbit);
	for (int i = 0; i < cowAmount; i++)
	{
		addCow(new Cow(this, new Vector2{ 100, 100 }));
		app->AddRenderable(cows[cows.size() - 1]);
	}
}