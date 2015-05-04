#include "Render.h"


Render::Render()
{
	type = RENDER; 
	for (int i = 0; i < 6; i++)
		vertices.append(sf::Vertex());

	vertices[0].texCoords = sf::Vector2f(0, 64);
	vertices[1].texCoords = sf::Vector2f(64, 64);
	vertices[2].texCoords = sf::Vector2f(0, 0);
	vertices[3].texCoords = sf::Vector2f(64, 64);
	vertices[4].texCoords = sf::Vector2f(0, 0);
	vertices[5].texCoords = sf::Vector2f(64, 0);

	vertices[0].color = sf::Color::White;
	vertices[1].color = sf::Color::White;
	vertices[2].color = sf::Color::White;
	vertices[3].color = sf::Color::White;
	vertices[4].color = sf::Color::White;
	vertices[5].color = sf::Color::White;
}

Render::~Render()
{
	delete texture;
}

void Render::SetSize(sf::Vector2f size)
{
	vertices[0].position = sf::Vector2f(0, size.y);
	vertices[1].position = sf::Vector2f(size.x, size.y);
	vertices[2].position = sf::Vector2f(0, 0);
	vertices[3].position = sf::Vector2f(size.x, size.y);
	vertices[4].position = sf::Vector2f(0, 0);
	vertices[5].position = sf::Vector2f(size.x, 0);
}