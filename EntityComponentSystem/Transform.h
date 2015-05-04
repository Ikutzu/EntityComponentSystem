#pragma once

#include "Component.h"
#include <SFML/System.hpp>

class Transform : public Component
{
public:
	
	Transform();
	~Transform();

	sf::Vector2f position;
	sf::Vector2f scale;
	sf::Vector2f origin;

	float rotation;


};

