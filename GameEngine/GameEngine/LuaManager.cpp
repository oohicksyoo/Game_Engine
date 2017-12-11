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
	Debug::getInstance().Log("Application Title: " + ref["title"].cast<string>());

	/*
	luaL_dofile(L, "Scripts/Entry.lua");

	LuaRef applicationSettings = LuaRef::fromStack(L, -1);
	applicationTitle = applicationSettings["title"].cast<string>();
	screenWidth = applicationSettings["width"].cast<int>();
	screenHeight = applicationSettings["height"].cast<int>();
	LuaRef scriptsToLoad = applicationSettings["scripts"];
	LuaRef entitiesToLoad = applicationSettings["entities"];

	cout << "Loading in Lua scripts (" << scriptsToLoad.length() << ")" << endl;
	for (int i = 0; i < scriptsToLoad.length(); i++) {
		string scriptPath = scriptsToLoad[i + 1].cast<string>();
		cout << "Load Lua: " << scriptPath << endl;
		luaL_dofile(L, scriptPath.c_str());
	}
	cout << "All scripts loaded" << endl;

	cout << "Loading Entities (" << entitiesToLoad.length() << ")" << endl;
	for (int i = 0; i < entitiesToLoad.length(); i++) {
		LuaRef entity = entitiesToLoad[i + 1];
		string entityName = entity["name"].cast<string>();
		string entityPath = entity["path"].cast<string>();
		cout << "Loading Entity: " << entityName << " at (" << entityPath << ")" << endl;
		luaL_dofile(L, entityPath.c_str());

		LuaRef entityFile = getGlobal(L, entityName.c_str());
		if (entityFile.isNil()) {
			cout << "Global Variable (" << entityName << ") was not found!" << endl;
		} else {
			cout << entityName << " was found" << endl;
		}

		//cout << "Length: " << entityFile.length() << endl;
	}
	cout << "All entities loaded" << endl;

	//Test the scripts function
	LuaRef sumNumbers = getGlobal(L, "sumNumbers");
	int result = sumNumbers(5, 4);
	cout << "Result: " << result << endl;
	*/
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


