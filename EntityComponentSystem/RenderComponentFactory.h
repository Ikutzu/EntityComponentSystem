#pragma once
#include "Render.h"

class RenderComponentFactory
{
public:

	static RenderComponentFactory* GetInstance();

	Render* CreateRenderComponent(std::string textureName);

private:

	RenderComponentFactory();
	~RenderComponentFactory();

	static RenderComponentFactory* instance;

};

