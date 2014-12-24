#include "Weapon.h"


Weapon::Weapon(Vector2* position) : Item(position)
{
	SetTexture(FWApplication::GetInstance()->LoadTexture("gun-metal.png"));
	SetSize(50, 50);
}


Weapon::~Weapon()
{
}


