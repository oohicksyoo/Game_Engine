#pragma once
#include "Component.h"
#include <string>
#include "Debug.h"

//Lua Stuff
#include <LuaBridge.h>
extern "C" {
# include "lua.h"
# include "lauxlib.h"
# include "lualib.h"
}

using namespace std;
using namespace luabridge;
using namespace Utility;

namespace Components {
	class ShaderComponent : public Component
	{
		public:
			ShaderComponent();
			void SetInformation(LuaRef ref) override;
	};
}

