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
	entityLoading(entitiesToLoad);
	

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
		.endNamespace()
		.beginClass<Entity>("Entity")
		.addFunction("Move", &Entity::Move)
		.endClass();
		
}

void Managers::LuaManager::entityLoading(LuaRef entitiesToLoad)
{
	Debug::getInstance().Log("Loading Entities (" + to_string(entitiesToLoad.length()) + ")");
	for (int i = 0; i < entitiesToLoad.length(); i++) {
		LuaRef entity = entitiesToLoad[i + 1];
		string entityName = entity["name"].cast<string>();
		string entityPath = entity["path"].cast<string>();

		Debug::getInstance().Log("Loading Entity: " + entityName + " at (" + entityPath + ")");

		luaL_dofile(L, entityPath.c_str());

		//Grabbing object from lua script
		LuaRef entityFile = getGlobal(L, entityName.c_str());
		if (entityFile.isNil()) {
			Debug::getInstance().Log("Global Variable (" + entityName + ") was not found!");
		} else {
			Debug::getInstance().Log("(" + entityName + ") was found");
			Entity* e = creatEntity(entityFile);
			EntityManager::getInstance().AddEntity(e);
		}		
	}
	Debug::getInstance().Log("All entities loaded");
}

Entity* Managers::LuaManager::creatEntity(LuaRef e)
{
	//Creating a entity from the file given
	LuaRef information = e["information"];
	LuaRef name = information["name"];
	if (!name.isNil()) {
		Debug::getInstance().Log("Found name! (" + name.cast<string>() + ")");
	}

	Entity* newEntity = new Entity(L);//new Entity(entityIndex, name.cast<string>());
	newEntity->Initialize(getNewID(), name.cast<string>());

	//Add Components here
	LuaRef components = e["components"];
	LuaRef componentList = components["componentList"];
	if (!componentList.isNil()) {
		Debug::getInstance().Log("Component list was found (" + to_string(componentList.length()) + ") components to be added");
		for (int i = 0; i < componentList.length(); i++) {
			string componentName = componentList[i + 1].cast<string>();
			LuaRef componentDetails = components[componentName];
			if (componentDetails.isNil()) {
				Debug::getInstance().Log("ERROR: Missing Component details for (" + componentList[i + 1].cast<string>() + ")");
			} else {
				Component* c = ComponentFactory::getInstance().CreateComponent(L, componentName);
				type_index type = ComponentFactory::getInstance().GetType(componentName);

				c->SetInformation(componentDetails);

				newEntity->AddComponent(type, c);
				Debug::getInstance().Log("Added (" + componentName + ") to components for entity (" + name.cast<string>() + ")");
			}
		}
	} else {
		Debug::getInstance().Log("ERROR: Unable to find component list, please check that there is a (componentList) in the components section");
	}

	LuaRef customScripts = e["customScripts"];
	if (!customScripts.isNil()) {
		LuaRef updateFunction = customScripts["update"];
		if (!updateFunction.isNil()) {
			newEntity->SetUpdate(updateFunction);
		}
	}

	return newEntity;
}

int Managers::LuaManager::getNewID()
{
	entityIndex++;
	return entityIndex;
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

void Managers::LuaManager::move(float x = 0, float y = 0)
{

}


