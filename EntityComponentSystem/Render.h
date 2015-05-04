#pragma once

#include "Component.h"
#include <SFML/Graphics.hpp>

class Render : public Component
{
public:
	Render();
	~Render();

	sf::Texture* texture;
	sf::VertexArray vertices;

	void SetSize(sf::Vector2f size);

};