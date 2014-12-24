#pragma once

#include <vector>
#include "Rabbit.h"
#include "Cow.h"

class Field
{
public:
	Field(double width, double heigth);
	~Field();

	const double width;
	const double height;

	void setRabbit(Rabbit* rabbit);
	void addCow(Cow* cow);

	vector<Cow*> getCows() const;
	Rabbit* getRabbit() const;
	void init(int cowAmount = 1);
private:
	vector<Cow*> cows;
	Rabbit* rabbit;

};

