#pragma once
#include "Singleton.h"
#include <string>
#include <typeindex>
#include "Component.h"
#include "GraphicsComponent.h"
#include "ShaderComponent.h"

using namespace std;
using namespace Components;
using namespace Utility;

namespace Factories {
	class ComponentFactory : public Singleton<ComponentFactory>
	{
		friend class Singleton<ComponentFactory>;
		private:
			ComponentFactory();

		public:
			Component* CreateComponent(string componentName);
			type_index GetType(string componentName);
	};
}

