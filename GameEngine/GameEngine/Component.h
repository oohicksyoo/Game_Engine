#pragma once
#include <string>

//Lua Stuff
#include <LuaBridge.h>
extern "C" {
# include "lua.h"
# include "lauxlib.h"
# include "lualib.h"
}

using namespace std;
using namespace luabridge;

namespace Components {
	class Component
	{
		public:
			virtual ~Component() {};
			virtual void SetInformation(LuaRef ref) {};
			string GetComponentName() { return componentName; };

		protected:
			string componentName = "Component Name";

	};
}

