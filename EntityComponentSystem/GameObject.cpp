#include "GameObject.h"


GameObject::GameObject()
{
}

GameObject::~GameObject()
{
	std::unordered_map<const std::type_info *, Component*>::iterator it;
	for (it = components.begin(); it != components.end();)
	{ 
		delete it->second;
		it++;
	}

	components.clear();
}

void GameObject::AddComponent(Component* newComponent)
{
	components[&typeid(*newComponent)] = newComponent;
	
	//components.insert(make_pair(&typeid(*newComponent)), newComponent); //#include <utility>
}
