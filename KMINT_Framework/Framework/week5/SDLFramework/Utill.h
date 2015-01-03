#pragma once
#include <math.h>
#include "Vector2.h"

class Utill
{
public:

	static double Utill::distanceBewteenPoints(double x1, double y1, double x2, double y2)
	{
		return sqrt(pow(x1 - x2, 2) + pow(y1 - y2, 2));
	}

	static double Utill::distanceBewteenPoints(Vector2 a, Vector2 b)
	{
		return distanceBewteenPoints(a.getX(), a.getY(), b.getX(), b.getY());
	}

};