#pragma once
#include "GameObject.h"
#include "RenderSystem.h"
#include "System.h"

#include <unordered_map>
#include <typeinfo>
#include <vector>

class SystemManager
{
public:
	~SystemManager();

	void Update(std::vector<GameObject*>* objectList);
	void AddSystem(System* newSystem);

private:
	using SystemList = std::unordered_map < const std::type_info *, System* >;
	SystemList systems;
};