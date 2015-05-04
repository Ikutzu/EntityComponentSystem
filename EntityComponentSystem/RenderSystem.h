#pragma once
#include "GameObject.h"
#include "Render.h"
#include "System.h"
#include "Transform.h"

class RenderSystem : public System
{
public:
	
	void Update(GameObject* obj);
	sf::RenderWindow* window;

	sf::RenderStates state;
};

