#pragma once

#include <math.h>

using namespace std;

class Vector2
{
public:
	Vector2();
	Vector2(double y, double x);
	~Vector2();

	double Vector2::getLength();
	void normalize(double length = 1);

	double getX() const;
	double getY() const;

	void setX(double x);
	void setY(double y);

	double getRotation();

	Vector2 operator *(double d);
	Vector2 operator /(double d);
	Vector2* rotate(double angle);

	Vector2 operator -(Vector2 dif);
	Vector2 operator +(Vector2 dif);

private:
	double x;
	double y;
};

