#include "stdafx.h"
#include "LuaManager.h"


Managers::LuaManager::LuaManager()
{
	Debug::getInstance().Log("Starting Lua Manager");
	init();
}

void Managers::LuaManager::init()
{
	L = luaL_newstate();
	luaL_openlibs(L);

	registerFunctionCallbacks();

	luaL_dofile(L, "Scripts/Entry.lua");
	LuaRef ref = LuaRef::fromStack(L, -1);
	LuaRef entitiesToLoad = ref["entities"];

	cout << "Loading Entities (" << entitiesToLoad.length() << ")" << endl;
	for (int i = 0; i < entitiesToLoad.length(); i++) {
		LuaRef entity = entitiesToLoad[i + 1];
		string entityName = entity["name"].cast<string>();
		string entityPath = entity["path"].cast<string>();

		Debug::getInstance().Log("Loading Entity: " + entityName + " at (" + entityPath + ")");

		luaL_dofile(L, entityPath.c_str());

		LuaRef entityFile = getGlobal(L, entityName.c_str());
		if (entityFile.isNil()) {
			Debug::getInstance().Log("Global Variable (" + entityName + ") was not found!");
		} else {
			Debug::getInstance().Log(entityName + " was found");
		}

		LuaRef ei = entityFile["information"];
		LuaRef ein = ei["name"];
		if (!ein.isNil()) {
			//Debug::getInstance().Log("Found name! (" + entityInformationName.cast<string>() + ")");
			Debug::getInstance().Log("Found name!");
		}

		//Create an Entity Here
		Entity* newEntity = new Entity(0, entityName);
		EntityManager::getInstance().AddEntity(newEntity);
	}
	Debug::getInstance().Log("All entities loaded");

	/*//Test the scripts function
	LuaRef sumNumbers = getGlobal(L, "sumNumbers");
	int result = sumNumbers(5, 4);
	cout << "Result: " << result << endl;*/	
}

void Managers::LuaManager::registerFunctionCallbacks()
{
	getGlobalNamespace(L)
		.beginNamespace("Debug")
		.addFunction("Log", log)
		.addFunction("Spacer", spacer)
		.endNamespace();	
}

//Lua Callbacks
void Managers::LuaManager::log(string String)
{
	Debug::getInstance().Log(String);
}

void Managers::LuaManager::spacer()
{
	Debug::getInstance().Spacer();
}


