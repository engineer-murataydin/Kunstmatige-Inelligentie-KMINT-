#include <iostream>
#include "Config.h"
#include "FWApplication.h"
#include <SDL_events.h>
#include "SDL_timer.h"
#include <time.h>
#include "Field.h"
#include <thread>
#include <chrono>
#include <algorithm>
#include "Rabbit.h"
#include "Cow.h"
#include "Weapon.h"
#include "Pill.h"

int main(int argc, char **argv)
{
	//auto window = Window::CreateSDLWindow();
	int offsetX = 50, offsetY = 50, width = 800, height = 600;
	auto application = new FWApplication(offsetX, offsetY, width, height);
	vector<SDL_Color> colors;

	colors.push_back({ 255, 0, 0 });
	colors.push_back({ 0, 255, 0 });
	colors.push_back({ 0, 0, 255 });
	colors.push_back({ 255, 255, 0 });

	vector<Field*> fields;
	for (int i = 0; i < colors.size(); i++)
	{
		fields.push_back(new Field(width, height, colors[i]));
		fields[i]->init();

		cout << i + 1 << ": " << fields[i]->getCow()->dna.toString() << endl;
	}

	if (!application->GetWindow())
	{
		LOG("Couldn't create window...");
		return EXIT_FAILURE;
	}

	application->SetTargetFPS(60);

	uint32_t time = application->GetTimeSinceStartedMS();

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
		if (application->GetTimeSinceStartedMS() - time >= 30000)
		{
			time = application->GetTimeSinceStartedMS();

			Field* best = fields[0];
			Field* secondBest = fields[1];
			if (best->getScore() > secondBest->getScore())
			{
				Field* temp = best;
				best = secondBest;
				secondBest = temp;
			}
			for (size_t i = 0; i < fields.size(); i++)
			{
				if (fields[i]->getScore() > best->getScore())
				{
					secondBest = best;
					best = fields[i];
				}
				else if (fields[i]->getScore() > secondBest->getScore())
				{
					secondBest = fields[i];
				}
			}
			vector<Dna*> children;
			for (int i = 0; i < fields.size(); i++)
			{
				children.push_back(new Dna());
			}
			Dna::mate(&best->getCow()->dna, &secondBest->getCow()->dna, children[0], children[1]);
			Dna::mate(&secondBest->getCow()->dna, &best->getCow()->dna, children[2], children[3]);
			cout << "Best:" << best->getCow()->dna.toString() << endl;
			cout << "secondBest:" << secondBest->getCow()->dna.toString() << endl;
			cout << "new Round:" << endl;
			for (size_t i = 0; i < fields.size(); i++)
			{
				cout << i + 1 << ": " << children[i]->toString() << endl;

				fields[i]->reset(children[i]);
			}
		}
	}

	delete application;
	return EXIT_SUCCESS;
}