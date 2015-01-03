#include "Vector2.h"
#define _USE_MATH_DEFINES
#include <math.h>

Vector2::Vector2(double y, double x) : y(y), x(x)
{
}

Vector2::Vector2() : Vector2(0, 0)
{

}


Vector2::~Vector2()
{

}


void Vector2::normalize(double length)
{
	double VectorLength = getLength();
	if (VectorLength != 0)
	{
		x = length * x / VectorLength;
		y = length * y / VectorLength;
	}
}

double Vector2::getLength()
{
	return sqrt(x*x + y*y);
}

double Vector2::getX() const
{
	return x;
}

double Vector2::getY() const
{
	return y;
}

void Vector2::setX(double x)
{
	this->x = x;
}

void Vector2::setY(double y)
{
	this->y = y;
}

Vector2 Vector2::operator *(double d)
{
	return Vector2(y * d, x * d);
}

Vector2 Vector2::operator /(double d)
{
	return Vector2(y / d, x / d);
}

double Vector2::getRotation()
{
	return atan2(y, x);
}

Vector2* Vector2::rotate(double angle)
{
	double tx = x, ty = y;
	x = tx * cos(angle) - ty * sin(angle);
	y = tx * sin(angle) + ty * cos(angle);
	return this;
}

Vector2 Vector2::operator -(Vector2 dif)
{
	return Vector2(y - dif.y, x - dif.x);
}

Vector2 Vector2::operator +(Vector2 dif)
{
	return Vector2(y + dif.y, x + dif.x);

}

