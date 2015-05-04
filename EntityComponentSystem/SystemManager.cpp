#include "SystemManager.h"


SystemManager::~SystemManager()
{
	SystemList::iterator it;
	for (it = systems.begin(); it != systems.end();)
	{
		delete it->second;
		it++;
	}

	systems.clear();
}

void SystemManager::Update(std::vector<GameObject*>* objectList)
{
	if (systems.count(&typeid(RenderSystem)) != 0)
	{
		for (int i = 0; i < objectList->size(); i++)
		{
			GameObject* tempPointer = objectList->at(i);
			static_cast<RenderSystem*>(systems[&typeid(RenderSystem)])->Update(tempPointer);
		}
	}
}

void SystemManager::AddSystem(System* newSystem)
{
	systems[&typeid(*newSystem)] = newSystem;

	//components.insert(make_pair(&typeid(*newComponent)), newComponent); //#include <utility>
}
