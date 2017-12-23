#pragma once
#include "Component.h"
#include "Debug.h"
#include <string>
#include <typeindex>

//Lua Stuff
#include <LuaBridge.h>

//Dear Im GUI
#include "imgui.h"
#include "imgui-sfml.h"

//SFML
#include <SFML/Graphics/Texture.hpp>
#include <SFML/Graphics/Sprite.hpp>

using namespace std;
using namespace sf;
using namespace luabridge;
using namespace Utility;
using namespace ImGui;

namespace Components {
	class GraphicsComponent : public Component
	{
		public:	
			GraphicsComponent(lua_State* L);
			void SetInformation(LuaRef ref) override;
			void DrawPanelInformation() override;
			void SetFilename(string path);
			string GetFilename();
			Sprite GetSprite();		
			type_index GetType() override { return type_index(typeid(GraphicsComponent)); };
			void CheckIsFlipped();

		private:
			string filename;
			Sprite sprite;
			Texture texture;
			bool isFlipped;
	};
}

