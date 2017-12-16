#include "stdafx.h"
#include "RenderEngine.h"

Engine::RenderEngine::RenderEngine()
{
	window.create(VideoMode(1280, 720, 32), "Cherry Engine");
	window.setVerticalSyncEnabled(true);
	EngineGUI::getInstance().Initialize(window);
	GameView::getInstance();

	backgroundColour = Color(25, 25, 25, 255);
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
		GameView::getInstance().ProcessEvents(event);

		if (event.type == Event::Closed) {
			CloseWindow();
		}			
	}

	//Clear Background and start stuff
	window.clear(backgroundColour);

	//Render GameView Here
	//TODO: Determine if we are in editor or play mode
	//TODO: Determine if we are in fullscreen play mode
	Texture tex = GameView::getInstance().GetSceneView();
	Sprite sceneViewSprite(tex);

	//Draw and update the IMGUI Stuff
	EngineGUI::getInstance().Update(window, deltaClock.restart());
	EngineGUI::getInstance().Draw(sceneViewSprite);
	EngineGUI::getInstance().Render(window);

	window.display();
}

void Engine::RenderEngine::CloseWindow() {
	window.close();
}
