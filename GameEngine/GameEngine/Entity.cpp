#include "stdafx.h"
#include "Entity.h"


Entities::Entity::Entity(int ID, string Name) {
	id = ID;
	name = Name;
}


Entities::Entity::~Entity() {
	for (auto& c : components) {
		delete c.second;
	}
}

string Entities::Entity::GetName()
{
	return name;
}

int Entities::Entity::GetID()
{
	return id;
}

void Entities::Entity::AddComponent(type_index type, Component * component)
{
	components[type] = component;
}

vector<Component*> Entities::Entity::GetComponents()
{
	vector<Component*> coms;

	for (auto& c : components) {
		coms.push_back(c.second); //push in the Component part of the dictionary
	}

	return coms;
}

GraphicsComponent * Entities::Entity::GetGraphics()
{
	return GetComponent<GraphicsComponent>();
}

template <typename T>
T* Entities::Entity::GetComponent()
{
	auto it = components.find(type_index(typeid(T)));
	if (it != components.end()) {
		return dynamic_cast<T*>(it->second);
	}

	return nullptr;
}
