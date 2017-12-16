#pragma once
#include "Component.h"
#include <string>

using namespace std;

namespace Components {
	class GraphicsComponent : public Component
	{
		public:
			GraphicsComponent();
			void SetFilename(string path);
			string GetFilename();

		private:
			string filename;
	};
}

