#pragma once
#include "Singleton.h"
#include "Debug.h"
#include "RenderEngine.h"

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

namespace Engine {
	class EngineGUI : public Singleton<EngineGUI>
	{
		friend class Singleton<EngineGUI>;
		public:
			void Initialize(RenderWindow& window);
			void Shutdown();
			void ProcessEvents(Event e);
			void Update(RenderWindow& window, Time deltaClock);
			void Draw();
			void Render(RenderWindow& window);

		private:
			EngineGUI();
			void StatsWindow();
			void MenuBar();

			//Edit Menu Functions
			void Undo();
			void Redo();
			void Cut();
			void Copy();
			void Paste();


		private:
			vector<float> fpsNodes;

	};
}

