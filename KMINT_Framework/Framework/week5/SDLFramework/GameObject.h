#pragma once
#include "IGameObject.h"
#include "Vector2.h"
#include "Field.h"

class GameObject :
	public IGameObject
{
public:
	GameObject(Field* field) : field(field), location(new Vector2()){}
	~GameObject(){}

	Vector2* getLocation(){ return location; }
	void setLocation(Vector2 location)
	{
		while (location.getX() < 0)
		{
			location.setX(location.getX() + field->width);
		}
		while (location.getY() < 0)
		{
			location.setY(location.getY() + field->height);
		}

		location.setX(fmod(location.getX(), field->width));
		location.setY(fmod(location.getY(), field->height));

		this->location->setX(location.getX());
		this->location->setY(location.getY());
		SetOffset(location.getX(), location.getY());
	}

	Field* getField() const
	{
		return field;
	}

protected:
	Field* field;
	Vector2* location;
};