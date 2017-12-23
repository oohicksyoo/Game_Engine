#include "stdafx.h"
#include "ShaderComponent.h"

Components::ShaderComponent::ShaderComponent(lua_State* L) : Component(L)
{
	componentName = "Shader";
}

void Components::ShaderComponent::SetInformation(LuaRef ref)
{
	infoRef = ref;
	Debug::getInstance().Log("Set Infromation Shader Component");
	//TODO: Grab information for vertex and fragment shader here and load them
}

void Components::ShaderComponent::DrawPanelInformation()
{
	Text("Hello");
}
