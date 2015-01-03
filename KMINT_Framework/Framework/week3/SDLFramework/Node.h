#pragma once
#include "Node.h"
#include <vector>
#include <random>
#include "IGameObject.h"

using namespace std;

class Edge;
class Graph;

class Node
{
public:
	Node(float x, float y, Graph* graph);
	~Node();

	void addEdge(Edge* edge);
	bool delEdge(Edge* edge);

	float x;
	float y;
	Graph* graph;

	Node* getRandomConnectedNode();
	static Node* getRandomConnectedNode(Node* node, int times);
	vector<Node*> getConnectedNodes();
	vector<Edge*> edges;
};

