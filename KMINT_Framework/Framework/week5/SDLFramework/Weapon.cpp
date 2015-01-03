#include "Weapon.h"
#include <SDL.h>

Weapon::Weapon(Field* field, Vector2 position, SDL_Color color) : Item(field, position)
{
	SDL_Texture* texture = FWApplication::GetInstance()->LoadTexture("gun-metal.png");
	SDL_SetTextureColorMod(texture, color.r, color.g, color.b);

	SetTexture(texture);
	SetSize(50, 50);
}


Weapon::~Weapon()
{
}


