#include "stdafx.h"
#include "GraphicsComponent.h"

Components::GraphicsComponent::GraphicsComponent(lua_State* L) : Component(L)
{
	componentName = "Graphics";
	isFlipped = false;
}

void Components::GraphicsComponent::SetInformation(LuaRef ref)
{
	infoRef = ref;
	Debug::getInstance().Log("Set Infromation Graphics Component");
	filename = ref["filename"].cast<string>();
	isFlipped = ref["isFlipped"].cast<bool>();
	SetFilename(filename);
}

void Components::GraphicsComponent::DrawPanelInformation()
{
	ImGui::Image(sprite, ImVec2(64, 64), Color::White, Color::Black);
	if (Checkbox("Flip X", &isFlipped)) {
		CheckIsFlipped();
	}
}

void Components::GraphicsComponent::SetFilename(string path)
{
	filename = path;
	if(texture.loadFromFile(path)) {
		sprite.setTexture(texture);
	}
}

string Components::GraphicsComponent::GetFilename()
{
	return filename;
}

Sprite Components::GraphicsComponent::GetSprite()
{
	CheckIsFlipped();
	return sprite;
}

void Components::GraphicsComponent::CheckIsFlipped()
{
	//TODO: Fix this flip BS
	if (isFlipped) {
		sprite.scale(-1, 1);
	}
}


