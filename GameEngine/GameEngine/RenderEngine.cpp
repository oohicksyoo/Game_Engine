#include "stdafx.h"
#include "RenderEngine.h"

Engine::RenderEngine::RenderEngine()
{
	window.create(VideoMode(1280, 720, 32), "Cherry Engine");
	window.setVerticalSyncEnabled(true);
	EngineGUI::getInstance().Initialize(window);

	backgroundColour = Color(168, 17, 17, 255);
}

void Engine::RenderEngine::Shutdown() {
	EngineGUI::getInstance().Shutdown();
}

bool Engine::RenderEngine::IsOpen() {
	return window.isOpen();
}

void Engine::RenderEngine::Update() {
	Event event;

	//Poll events
	while (window.pollEvent(event)) {
		EngineGUI::getInstance().ProcessEvents(event);
		if (event.type == Event::Closed) {
			CloseWindow();
		}		
	}

	//Draw and update the IMGUI Stuff
	EngineGUI::getInstance().Update(window, deltaClock.restart());
	EngineGUI::getInstance().Draw();

	//More rendering ie:Sprites

	//End stuff
	window.clear(backgroundColour);
	EngineGUI::getInstance().Render(window);
	window.display();
}

void Engine::RenderEngine::CloseWindow() {
	window.close();
}
