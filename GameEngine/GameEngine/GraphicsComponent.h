#pragma once
#include "Component.h"
#include "Debug.h"
#include <string>

//Lua Stuff
#include <LuaBridge.h>
extern "C" {
# include "lua.h"
# include "lauxlib.h"
# include "lualib.h"
}

//SFML
#include <SFML/Graphics/Texture.hpp>
#include <SFML/Graphics/Sprite.hpp>

using namespace std;
using namespace sf;
using namespace luabridge;
using namespace Utility;

namespace Components {
	class GraphicsComponent : public Component
	{
		public:	
			GraphicsComponent();
			void SetInformation(LuaRef ref) override;
			void SetFilename(string path);
			string GetFilename();
			Sprite GetSprite();				

		private:
			string filename;
			Sprite sprite;
			Texture texture;
	};
}

