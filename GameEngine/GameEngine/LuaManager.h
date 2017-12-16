#pragma once
#include "Singleton.h"
#include "Debug.h"
#include "Entity.h"
#include "EntityManager.h"

//Lua Stuff
#include <LuaBridge.h>
#include <iostream>
#include <string>
extern "C" {
# include "lua.h"
# include "lauxlib.h"
# include "lualib.h"
}

using namespace luabridge;
using namespace std;
using namespace Utility;
using namespace Entities;
using namespace Managers;

namespace Managers {
	class LuaManager : public Singleton<LuaManager>
	{
		friend class Singleton<LuaManager>;
		private:
			LuaManager();
			void init();
			void registerFunctionCallbacks();

			//Lua Based Callbacks
		private:
			static void log(string String);
			static void spacer();

		private:
			lua_State* L;
	};
}

