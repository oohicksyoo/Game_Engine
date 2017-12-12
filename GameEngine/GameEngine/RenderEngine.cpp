#include "stdafx.h"
#include "RenderEngine.h"

Engine::RenderEngine::RenderEngine()
{
	window.create(VideoMode(640, 480, 32), "Cherry Engine");
	window.setVerticalSyncEnabled(true);
	EngineGUI::getInstance().Initialize(window);
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
			window.close();
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
