#include "Pill.h"
#include <SDL.h>

Pill::Pill(Field* field, Vector2 position, SDL_Color color) : Item(field, position)
{
	SDL_Texture* texture = FWApplication::GetInstance()->LoadTexture("pill.png");
	SDL_SetTextureColorMod(texture, color.r, color.g, color.b);

	SetTexture(texture);
	SetSize(50, 50);
}


Pill::~Pill()
{
}
