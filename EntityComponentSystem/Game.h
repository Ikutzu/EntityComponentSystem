#pragma once

#include "GameObject.h"
#include "SystemManager.h"
#include "RenderSystem.h"
#include "RenderComponentFactory.h"
#include "Transform.h"

#include <vector>

class Game
{
public:
	Game(sf::RenderWindow* win);
	~Game();

	void Update(float dt);
	void Draw();

private:
	void UpdateControls(float dt);

	SystemManager systemManager;
	
	sf::RenderWindow* window;
	GameObject* player;

	std::vector<GameObject*> gameObjectList;
};

