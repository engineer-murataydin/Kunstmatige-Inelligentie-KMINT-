#include <iostream>
#include "Config.h"
#include "FWApplication.h"
#include <SDL_events.h>
#include "SDL_timer.h"
#include <time.h>
#include "Graph.h"

int main(int argc, char **argv)
{
	//auto window = Window::CreateSDLWindow();
	auto application = new FWApplication();
	Graph* graph = new Graph();
	application->AddRenderable(graph->cow);
	application->AddRenderable(graph->rabbit);
	if (!application->GetWindow())
	{
		LOG("Couldn't create window...");
		return EXIT_FAILURE;
	}

	application->SetTargetFPS(60);

	//while (true){}
	while (application->IsRunning())
	{
		application->StartTick();

		SDL_Event event;
		while (SDL_PollEvent(&event))
		{
			switch (event.type)
			{
			case SDL_QUIT:
				application->Quit();
				break;
			case SDL_KEYDOWN:
				switch (event.key.keysym.sym){

				default:
					break;
				}
			case SDL_MOUSEBUTTONDOWN:
				graph->processInput(event);
				break;
			}
		}

		application->SetColor(Color(255, 255, 255, 255));
		graph->render();
		application->UpdateGameObjects();
		application->RenderGameObjects();
		application->EndTick();
	}

	delete application;
	delete graph;
	return EXIT_SUCCESS;
}