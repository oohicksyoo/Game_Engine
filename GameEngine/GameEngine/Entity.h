#pragma once
#include <iostream>
#include <map>
#include <string>
#include <typeindex>
#include <vector>
#include "Debug.h"

#include "Component.h"
#include "GraphicsComponent.h"

using namespace std;
using namespace Components;
using namespace Utility;

namespace Entities {
	class Entity
	{
		public:
			Entity(int ID, string Name);
			~Entity();
			string GetName();
			int GetID();
			void AddComponent(type_index type, Component* component);
			vector<Component*> GetComponents();
			

			//Get component
			template <typename T>
			T* GetComponent();

		private:
			GraphicsComponent* GetGraphics();

		private:
			int id;
			string name;
			map<type_index, Component*> components;
	};
}

