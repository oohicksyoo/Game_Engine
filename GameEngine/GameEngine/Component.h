#pragma once
#include <string>
#include <typeindex>

//Lua Stuff
#include <LuaBridge.h>

//Dear Im GUI
#include "imgui.h"
#include "imgui-sfml.h"

using namespace std;
using namespace luabridge;
using namespace ImGui;

namespace Components {
	class Component
	{
		public:
			Component(lua_State* L) : infoRef(L) {};
			virtual ~Component() {};
			virtual void SetInformation(LuaRef ref) { infoRef = ref; };
			virtual type_index GetType() { return type_index(typeid(Component)); };
			virtual void DrawPanelInformation() {};
			string GetComponentName() { return componentName; };
			LuaRef GetRef() { return infoRef; };			

		protected:
			string componentName = "Component Name";
			LuaRef infoRef;

	};
}

