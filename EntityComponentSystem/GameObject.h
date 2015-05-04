#pragma once

#include "Component.h"

#include <unordered_map>
#include <typeinfo>



class GameObject
{
public:
	GameObject();
	~GameObject();

	void AddComponent(Component* newComponent);
	template<typename T> T* GetComponent();

private:

	using ComponentList = std::unordered_map < const std::type_info *, Component* > ;
	ComponentList components;
};

template<typename T>
T* GameObject::GetComponent()
{
	if (components.count(&typeid(T)) != 0)
		return static_cast<T*>(components[&typeid(T)]);
	else
		return nullptr;

	//ComponentList::const_iterator position = components.find(&typeid(T));
	//if (position != components.end())
	//	return static_cast<T*>(position->second);
	//else
	//	return nullptr;
}