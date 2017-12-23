#include "stdafx.h"
#include "TransformComponent.h"


Components::TransformComponent::TransformComponent(lua_State* L) : Component(L)
{
	componentName = "Transform";
	position = Vector2f(0, 0);
	rotation = 0;
	scale = Vector2f(1, 1);
}

void Components::TransformComponent::DrawPanelInformation()
{
	float pos[2] = { position.x, position.y };
	InputFloat2("Position", pos);
	position = Vector2f(pos[0], pos[1]);

	InputFloat("Rotation", &rotation);

	float scaleF[2] = { scale.x, scale.y };
	InputFloat2("Scale", scaleF);
	scale = Vector2f(scaleF[0], scaleF[1]);
}

Vector2f Components::TransformComponent::GetPosition()
{
	return position;
}

float Components::TransformComponent::GetRotation()
{
	return rotation;
}

Vector2f Components::TransformComponent::GetScale()
{
	return scale;
}

void Components::TransformComponent::SetPosition(Vector2f vect)
{
	position = vect;
}

void Components::TransformComponent::SetRotation(float rot)
{
	rotation = rot;
}

void Components::TransformComponent::SetScale(Vector2f vect)
{
	scale = vect;
}

void Components::TransformComponent::MovePosition(Vector2f vect)
{
	position += vect;
}
