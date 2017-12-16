#include "stdafx.h"
#include "EntityManager.h"

Managers::EntityManager::EntityManager()
{

}

Managers::EntityManager::~EntityManager()
{
	for (auto it = entities.begin(); it != entities.end(); it++) {
		delete (*it);
	}
	entities.clear();
}

void Managers::EntityManager::AddEntity(Entity* &entity)
{
	entities.push_back(entity);
}

bool Managers::EntityManager::RemoveEntityAt(int i)
{
	return false;
}
