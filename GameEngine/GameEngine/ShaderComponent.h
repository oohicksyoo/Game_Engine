#pragma once
#include "Component.h"
#include <string>
#include "Debug.h"

//Lua Stuff
#include <LuaBridge.h>

//Dear Im GUI
#include "imgui.h"
#include "imgui-sfml.h"

using namespace std;
using namespace luabridge;
using namespace Utility;
using namespace ImGui;

namespace Components {
	class ShaderComponent : public Component
	{
		public:
			ShaderComponent(lua_State* L);
			void SetInformation(LuaRef ref) override;
			void DrawPanelInformation() override;
			type_index GetType() override { return type_index(typeid(ShaderComponent)); };
	};
}

