#include "stdafx.h"
#include "ComponentFactory.h"


Factories::ComponentFactory::ComponentFactory()
{

}

Component * Factories::ComponentFactory::CreateComponent(lua_State* L, string componentName)
{
	for (int i = 0; i < componentName.length(); i++) {
		componentName[i] = tolower(componentName[i]);
	}

	if (componentName == "graphicscomponent") {
		return new GraphicsComponent(L);
	} else if (componentName == "shadercomponent") {
		return new ShaderComponent(L);
	}

	return nullptr;
}

type_index Factories::ComponentFactory::GetType(string componentName)
{
	for (int i = 0; i < componentName.length(); i++) {
		componentName[i] = tolower(componentName[i]);
	}


	if (componentName == "graphicscomponent") {
		return type_index(typeid(GraphicsComponent));
	} else if (componentName == "shadercomponent") {
		return type_index(typeid(ShaderComponent));
	}
	
	return type_index(typeid(Component));
}
