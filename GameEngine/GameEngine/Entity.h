#pragma once
#include <iostream>
#include <map>
#include <string>
#include <typeindex>
#include <vector>
#include "Debug.h"

#include "Component.h"
#include "TransformComponent.h"
#include "GraphicsComponent.h"

#include "LuaBridge.h"

//Dear Im GUI
#include "imgui.h"
#include "imgui-sfml.h"

using namespace std;
using namespace Components;
using namespace Utility;

namespace Entities {
	class Entity
	{
		public:
			Entity(lua_State* L) : updateFunction(L) {
				luaState = L;
			};
			~Entity();
			void Initialize(int ID, string Name);
			void SetName(string Name);
			string GetName();
			vector<char> GetNameChar();
			int GetID();
			void AddComponent(type_index type, Component* component);
			vector<Component*> GetComponents();
			void DrawPanelInformation();
			lua_State* GetState() {
				return luaState;
			};

			//Lua Calls
			void Move(float x, float y);
			
			

			//Move these
			void SetUpdate(LuaRef ref) {
				updateFunction = ref;
			};

			void CallUpdate() {				
				if (!updateFunction.isNil()) {
					updateFunction(this);
				}
			};

			
			

			//Get component
			template <typename T>
			T* GetComponent();

		private:
			GraphicsComponent* GetGraphics();
			TransformComponent* GetTransform();

		private:
			int id;
			string name;
			map<type_index, Component*> components;	
			lua_State* luaState;
			LuaRef updateFunction;
			
	};
}

