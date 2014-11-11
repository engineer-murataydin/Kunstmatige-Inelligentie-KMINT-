#pragma once

#include <vector>
#include <stack>
#include "Node.h"
#include "Edge.h"
#include <SDL.h>
#include "Rabbit.h"
#include "Cow.h"

class Graph
{
public:
	Graph();
	~Graph();

	void render();
	void processInput(SDL_Event event);
	static stack<Node*> CreatePath(Node* from, Node* to);
	void step();
	vector<Node*> nodes;

	Rabbit* rabbit;
	Cow* cow;
};

