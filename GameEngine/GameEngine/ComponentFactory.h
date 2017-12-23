#pragma once
#include "Singleton.h"
#include <string>
#include <typeindex>
#include "Component.h"
#include "GraphicsComponent.h"
#include "ShaderComponent.h"

//Lua Stuff
#include <LuaBridge.h>

using namespace std;
using namespace Components;
using namespace Utility;
using namespace luabridge;

namespace Factories {
	class ComponentFactory : public Singleton<ComponentFactory>
	{
		friend class Singleton<ComponentFactory>;
		private:
			ComponentFactory();

		public:
			Component* CreateComponent(lua_State* L, string componentName);
			type_index GetType(string componentName);
	};
}

