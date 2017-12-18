#include "stdafx.h"
#include "ComponentFactory.h"


Factories::ComponentFactory::ComponentFactory()
{

}

Component * Factories::ComponentFactory::CreateComponent(string componentName)
{
	if (componentName == "graphicsComponent") {
		return new GraphicsComponent;
	} else if (componentName == "shaderComponent") {
		return new ShaderComponent;
	}

	return nullptr;
}

type_index Factories::ComponentFactory::GetType(string componentName)
{
	if (componentName == "graphicsComponent") {
		return type_index(typeid(GraphicsComponent));
	} else if (componentName == "shaderComponent") {
		return type_index(typeid(ShaderComponent));
	}
	
	return type_index(typeid(Component));
}
