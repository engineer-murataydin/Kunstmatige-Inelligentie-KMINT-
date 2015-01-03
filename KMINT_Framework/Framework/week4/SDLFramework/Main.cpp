#include <iostream>
#include "Config.h"
#include "FWApplication.h"
#include <SDL_events.h>
#include "SDL_timer.h"
#include <time.h>
#include "Field.h"

int main(int argc, char **argv)
{
	//auto window = Window::CreateSDLWindow();
	int offsetX = 50, offsetY = 50, width = 800, height = 600;
	auto application = new FWApplication(offsetX, offsetY, width, height);
	Field field(width, height);
	field.init(5);
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
				break;
			}
		}

		application->SetColor(Color(255, 255, 255, 255));
		application->UpdateGameObjects();
		application->RenderGameObjects();
		application->EndTick();
	}

	delete application;
	return EXIT_SUCCESS;
}