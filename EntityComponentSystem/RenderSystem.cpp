#include "RenderSystem.h"


void RenderSystem::Update(GameObject* obj)
{
	Transform* tempTransform = obj->GetComponent<Transform>();
	Render* tempRender = obj->GetComponent<Render>();

	if (tempTransform == nullptr)
		printf("RenderSystem::Update: Entity has no Transform component");
	else if (tempRender == nullptr)
		printf("RenderSystem::Update: Entity has no Render component");
	else
	{
		state = state.Default;
		state.transform.translate(-tempTransform->origin).rotate(tempTransform->rotation, tempTransform->position + tempTransform->origin).scale(tempTransform->scale, tempTransform->position + tempTransform->origin).translate(tempTransform->position);
		state.texture = tempRender->texture;

		window->draw(&tempRender->vertices[0], tempRender->vertices.getVertexCount(), sf::Triangles, state);
	}
}