#pragma once
#include "Node.h"
#include <vector>
#include <random>
#include "IGameObject.h"

using namespace std;
class Edge;
class Node
{
public:
	Node(float x, float y);
	~Node();

	void addEdge(Edge* edge);
	bool delEdge(Edge* edge);

	float x;
	float y;

	Node* getRandomConnectedNode();
	Node* getRandomConnectedNode(Node* node, int times);

	vector<Edge*> edges;

	default_random_engine dre;
};

