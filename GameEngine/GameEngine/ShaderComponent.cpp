#include "stdafx.h"
#include "ShaderComponent.h"

Components::ShaderComponent::ShaderComponent()
{
	componentName = "Shader";
}

void Components::ShaderComponent::SetInformation(LuaRef ref)
{
	Debug::getInstance().Log("Set Infromation Shader Component");
	//TODO: Grab information for vertex and fragment shader here and load them
}
