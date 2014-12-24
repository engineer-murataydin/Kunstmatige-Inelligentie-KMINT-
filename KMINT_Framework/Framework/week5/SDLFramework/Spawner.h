#pragma once
#include "Vector2.h"

template<typename T>
class Spawner
{
public:

	Spawner(Vector2 location, T instance) :instance(instance), location(location)
	{	};
	~Spawner()
	{	};



	T instance;
	Vector2 location;
};

