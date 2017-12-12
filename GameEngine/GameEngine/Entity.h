#pragma once
#include <iostream>
#include <vector>
#include <string>
#include "Component.h"

using namespace std;
using namespace Components;

namespace Entities {
	class Entity
	{
		public:
			Entity(int ID, string Name);
			~Entity();

		private:
			int id;
			vector<Component> Components;
	};
}

