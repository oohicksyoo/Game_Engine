#pragma once
#include "Singleton.h"
#include "Debug.h"
#include "Entity.h"

//Components
#include "Component.h"
#include "GraphicsComponent.h"
#include "ShaderComponent.h"
#include "TransformComponent.h"

#include <vector>

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
using namespace Entities;
using namespace Components;

namespace Engine {
	class GameView : public Singleton<GameView> {

		friend class Singleton<GameView>;

		public:
			void ProcessEvents(Event e);
			Texture GetSceneView();
			void AddEntityToScene(Entity* entity);
			vector<Entity*> GetHierarchy();
			void SetIsPlaying(bool value);
			bool GetIsPlaying();

		private:
			GameView();
			~GameView();

		private:
			bool isPlaying;
			bool isFullscreen;
			vector<Entity*> hierarchy;
			View camera;
			RenderTexture renderTexture;
			Texture sceneView;
	};
}

