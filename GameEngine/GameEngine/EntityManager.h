#pragma once
#include "Singleton.h"
#include "Debug.h"
#include "Entity.h"
#include <vector>

using namespace Utility;
using namespace Entities;
using namespace std;

namespace Managers {
	class EntityManager : public Singleton<EntityManager>
	{
		friend class Singleton<EntityManager>;
		public:
			void AddEntity(Entity* &entity);
			bool RemoveEntityAt(int i);
			vector<Entity*> GetEntities();

		private:
			EntityManager();
			~EntityManager();

		private:
			vector<Entity*> entities;
	};
}

