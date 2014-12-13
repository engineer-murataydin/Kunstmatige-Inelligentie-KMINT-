#include "Graph.h"
#include "Utill.h"
#include "PathNode.h"
#include <map>
#include "FWApplication.h"

Graph::Graph()
{
	outOfscreen = new Node(-100, -100, this);

	Node* node = new Node(100, 100, this);
	nodes.push_back(node);

	node = new Node(100, 150, this);
	new Edge(node, nodes[0]);
	nodes.push_back(node);

	node = new Node(400, 200, this);
	nodes.push_back(node);

	node = new Node(50, 300, this);
	new Edge(node, nodes[1]);
	new Edge(node, nodes[2]);
	nodes.push_back(node);

	node = new Node(250, 400, this);
	new Edge(node, nodes[2]);
	nodes.push_back(node);

	node = new Node(100, 400, this);
	new Edge(node, nodes[2]);
	new Edge(node, nodes[4]);
	nodes.push_back(node);

	node = new Node(150, 200, this);
	new Edge(node, nodes[3]);
	new Edge(node, nodes[2]);
	new Edge(node, nodes[1]);
	nodes.push_back(node);

	node = new Node(275, 125, this);
	new Edge(node, nodes[2]);
	new Edge(node, nodes[1]);
	new Edge(node, nodes[0]);
	nodes.push_back(node);

	cow = new Cow(nodes[1]);
	rabbit = new Rabbit(nodes[3]);
	pill = new Pill(nodes[5]);
	weapon = new Weapon(nodes[2]);

	FWApplication* application = FWApplication::GetInstance();

	application->AddRenderable(cow);
	application->AddRenderable(rabbit);
	application->AddRenderable(pill);
	application->AddRenderable(weapon);
}


Graph::~Graph()
{
	for (int i = 0; i < nodes.size(); i++)
	{
		delete nodes[i];
	}
	delete outOfscreen;
}

void Graph::processInput(SDL_Event event)
{
	switch (event.type)
	{
	case SDL_MOUSEBUTTONDOWN:
		if (event.button.button == SDL_BUTTON_LEFT)
		{
			step();
		}
		else if (event.button.button == SDL_BUTTON_RIGHT)
		{
			rabbit->move();
		}
		break;
	default:
		break;
	}
}

void Graph::step()
{
	cow->move();
	rabbit->move();

}


void Graph::render()
{
	for (int i = 0; i < nodes.size(); i++)
	{
		Node* node = nodes[i];

		for (int j = 0; j < node->edges.size(); j++)
		{
			Edge* edge = node->edges[j];
			FWApplication::GetInstance()->DrawLine(edge->from->x + 10, edge->from->y + 10, edge->to->x + 10, edge->to->y + 10);
		}
		FWApplication::GetInstance()->DrawRect(node->x, node->y, 20, 20, true);
	}
}

stack<Node*> Graph::CreatePath(Node* from, Node* to)
{
	if (from == to)
	{
		stack<Node*> stack;
		stack.push(from);
		return stack;
	}
	map<Node*, PathNode*> openList;
	map<Node*, PathNode*> closedList;

	openList[from] = new PathNode(from, 0, 0, NULL);
	while (!openList.empty())
	{
		PathNode* pathNode = openList.begin()->second;
		int value = pathNode->F();
		for (auto iterator = openList.begin(); iterator != openList.end(); iterator++)
		{
			if (value > iterator->second->F())
			{
				value = iterator->second->F();
				pathNode = iterator->second;
			}
		}

		Node* node = pathNode->node;

		for (int i = 0; i < node->edges.size(); i++)
		{
			Node* foundNode = node->edges[i]->getOtherNode(node);
			if (closedList.find(foundNode) == closedList.end())
			{
				map<Node*, PathNode*>::iterator found = openList.find(foundNode);
				if (found != openList.end())
				{
					if (pathNode->F() > found->second->F())
					{
						found->second->g = pathNode->g + node->edges[i]->cost;
						found->second->from = pathNode;
					}
				}
				else
				{
					openList[foundNode] = new PathNode(foundNode,
						pathNode->g + node->edges[i]->cost,
						Utill::distanceBewteenPoints(foundNode->x, foundNode->y, to->x, to->y),
						pathNode);
				}
			}
		}
		openList.erase(node);

		closedList[node] = pathNode;
		if (pathNode->node == to)
		{
			break;
		}
	}

	PathNode* nodeInPath = closedList.find(to)->second;
	stack<Node*> path;

	while (nodeInPath->from)
	{
		path.push(nodeInPath->node);
		nodeInPath = nodeInPath->from;
	}

	return path;
}

