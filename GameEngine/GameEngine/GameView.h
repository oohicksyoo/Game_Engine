#pragma once
#include "Singleton.h"
#include "Debug.h"

//SFML
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/System/Clock.hpp>
#include <SFML/Window/Event.hpp>
#include <SFML/Graphics/Texture.hpp>
#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/View.hpp>
#include <SFML/Graphics/RenderTexture.hpp>

using namespace Utility;
using namespace sf;

namespace Engine {
	class GameView : public Singleton<GameView> {

		friend class Singleton<GameView>;

		public:
			void ProcessEvents(Event e);
			Texture GetSceneView();

		private:
			GameView();

		private:
			bool isPlaying;
			bool isFullscreen;
			Texture texture;
			Sprite sprite;
			View camera;
			RenderTexture renderTexture;
			Texture sceneView;
	};
}

