#include "stdafx.h"
#include "Entity.h"


Entities::Entity::~Entity() {
	for (auto& c : components) {
		delete c.second;
	}
}

void Entities::Entity::Initialize(int ID, string Name)
{
	id = ID;
	name = Name;
	AddComponent(type_index(typeid(TransformComponent)), new TransformComponent(luaState)); //Add a transform component by default
}

void Entities::Entity::SetName(string Name)
{
	name = Name;
}

string Entities::Entity::GetName()
{
	return name;
}

vector<char> Entities::Entity::GetNameChar()
{
	vector<char> vect;

	for (int i = 0; i < name.length(); i++) {
		vect.push_back(name[i]);
	}

	return vect;
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

	coms.push_back(GetComponent<TransformComponent>());

	for (auto& c : components) {
		if (c.first != type_index(typeid(TransformComponent))) {
			coms.push_back(c.second); //push in the Component part of the dictionary
		}		
	}

	return coms;
}

void Entities::Entity::DrawPanelInformation()
{
	//ID
	string idText = "ID (" + to_string(GetID()) + ")";
	TextDisabled(idText.c_str());

	//Name
	char inputName[256] = "";
	for (int i = 0; i < name.length(); i++) {
		inputName[i] = name[i];
	}
	InputText("Name", inputName, 256);
	name = inputName;
}

void Entities::Entity::Move(float x, float y)
{
	GetComponent<TransformComponent>()->MovePosition(Vector2f(x, y));
}

GraphicsComponent * Entities::Entity::GetGraphics()
{
	return GetComponent<GraphicsComponent>();
}

TransformComponent * Entities::Entity::GetTransform()
{
	return GetComponent<TransformComponent>();
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
