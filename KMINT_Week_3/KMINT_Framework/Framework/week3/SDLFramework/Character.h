#pragma once

#include "Node.h"
#include "IGameObject.h"
#include <string>

class CharacterBehaviour;

class Character : public IGameObject
{
public:
	Character(Node* location);
	virtual ~Character();

	virtual Node* move() = 0;
	Node* getLocation();
	void setLocation(Node* location);
	void setBehaviour(CharacterBehaviour* behaviour);
	bool isBored();
	void setBored(int value);
	SDL_Texture* LoadTexture();
private:
	Node* location;
protected:
	CharacterBehaviour* behaviour;
	string textureName;
	int bored = 0;
};

