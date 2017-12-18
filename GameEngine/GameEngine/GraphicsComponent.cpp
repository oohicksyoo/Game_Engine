#include "stdafx.h"
#include "GraphicsComponent.h"

Components::GraphicsComponent::GraphicsComponent()
{

}

void Components::GraphicsComponent::SetInformation(LuaRef ref)
{
	Debug::getInstance().Log("Set Infromation Graphics Component");
	filename = ref["filename"].cast<string>();
	SetFilename(filename);
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
	return sprite;
}


