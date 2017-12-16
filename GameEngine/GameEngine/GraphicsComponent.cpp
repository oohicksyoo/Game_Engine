#include "stdafx.h"
#include "GraphicsComponent.h"


Components::GraphicsComponent::GraphicsComponent()
{
}

void Components::GraphicsComponent::SetFilename(string path)
{
	filename = path;
}

string Components::GraphicsComponent::GetFilename()
{
	return filename;
}
