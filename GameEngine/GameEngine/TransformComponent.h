#pragma once
#include "Component.h"
#include "Debug.h"
#include <string>

//Lua Stuff
#include <LuaBridge.h>

//Dear Im GUI
#include "imgui.h"
#include "imgui-sfml.h"

using namespace std;
using namespace sf;
using namespace Utility;
using namespace luabridge;
using namespace ImGui;

namespace Components {
	class TransformComponent : public Component
	{
		public:
			TransformComponent(lua_State* L);
			void DrawPanelInformation() override;
			type_index GetType() override { return type_index(typeid(TransformComponent)); };
			Vector2f GetPosition();
			float GetRotation();
			Vector2f GetScale();
			void SetPosition(Vector2f vect);
			void SetRotation(float rot);
			void SetScale(Vector2f vect);
			void MovePosition(Vector2f vect);

		private:
			Vector2f position;
			float rotation;
			Vector2f scale;
	};
}

