#pragma once
#include "Singleton.h"
#include <iostream>
#include <string>
#include <string.h>

using namespace std;

namespace Utility {
	class Debug : public Singleton<Debug>
	{
		friend class Singleton<Debug>;
		private:
			Debug();

		public:
			void Log(string String);
			void Spacer();
	};
}

