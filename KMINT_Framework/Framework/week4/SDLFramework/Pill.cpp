#include "Pill.h"


Pill::Pill(Vector2* position) : Item(position)
{
	SetTexture(FWApplication::GetInstance()->LoadTexture("pill.png"));
	SetSize(50, 50);
}


Pill::~Pill()
{
}
