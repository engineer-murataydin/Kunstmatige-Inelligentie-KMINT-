#include "Pill.h"


Pill::Pill(Node* position) : Item(position)
{
	SetTexture(FWApplication::GetInstance()->LoadTexture("pill.png"));
	SetSize(50, 50);
}


Pill::~Pill()
{
}
