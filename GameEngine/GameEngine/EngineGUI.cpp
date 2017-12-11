#include "stdafx.h"
#include "EngineGUI.h"

Engine::EngineGUI::EngineGUI()
{
}

void Engine::EngineGUI::Initialize(RenderWindow& window) {
	SFML::Init(window);
}

void Engine::EngineGUI::Shutdown()
{
	SFML::Shutdown();
}

void Engine::EngineGUI::ProcessEvents(Event e)
{
	SFML::ProcessEvent(e);
}

void Engine::EngineGUI::Update(RenderWindow & window, Time deltaClock)
{
	SFML::Update(window, deltaClock);
}

void Engine::EngineGUI::Draw()
{
	//TODO: Draw some widgets here
	Begin("Sample Window");
	
	if (Button("Sample Button")) {
		Debug::getInstance().Log("Button Action in console");
	}

	End();
}

void Engine::EngineGUI::Render(RenderWindow & window)
{
	SFML::Render(window);
}


