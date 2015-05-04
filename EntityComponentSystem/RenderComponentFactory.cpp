#include "RenderComponentFactory.h"

RenderComponentFactory* RenderComponentFactory::instance = nullptr;

RenderComponentFactory* RenderComponentFactory::GetInstance()
{
	if (instance == nullptr)
		instance = new RenderComponentFactory;
	
	return instance;
}

Render* RenderComponentFactory::CreateRenderComponent(std::string textureName)
{
	Render* tempRender = new Render;

	tempRender->texture = new sf::Texture;
	tempRender->texture->loadFromFile(textureName);
	tempRender->SetSize(sf::Vector2f(64.0, 64.0));

	return tempRender;
}

RenderComponentFactory::RenderComponentFactory()
{
}

RenderComponentFactory::~RenderComponentFactory()
{
	delete instance;
}
