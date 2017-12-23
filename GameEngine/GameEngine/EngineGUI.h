#pragma once
#include "Singleton.h"
#include "Debug.h"
#include "RenderEngine.h"
#include "GameView.h"
#include "Entity.h"
#include "EntityManager.h"
#include "LuaManager.h"
#include "ComponentFactory.h"
#include <typeindex>
#include <typeinfo>

//Dear Im GUI
#include "imgui.h"
#include "imgui-sfml.h"

//SFML
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/System/Clock.hpp>
#include <SFML/Window/Event.hpp>

#include <vector>

using namespace Utility;
using namespace ImGui;
using namespace sf;
using namespace Engine;
using namespace Entities;
using namespace Managers;
using namespace Factories;

namespace Engine {
	class EngineGUI : public Singleton<EngineGUI>
	{
		friend class Singleton<EngineGUI>;
		public:
			void Initialize(RenderWindow& window);
			void Shutdown();
			void ProcessEvents(Event e);
			void Update(RenderWindow& window, Time deltaClock);
			void Draw(Sprite sceneView);
			void Render(RenderWindow& window);			

		private:
			EngineGUI();
			void StatsWindow();
			void MenuBar();
			void EntityMenu();
			void Entities(vector<Entity*> e);
			void Hierarchy(vector<Entity*> e);
			void SelectedEntity();
			void LoggingWindow();
			void SceneWindow(Sprite sceneView);

			//Edit Menu Functions
			void Undo();
			void Redo();
			void Cut();
			void Copy();
			void Paste();


		private:
			vector<float> fpsNodes;
			Entity* selectedHeirarchy;

	};
}

