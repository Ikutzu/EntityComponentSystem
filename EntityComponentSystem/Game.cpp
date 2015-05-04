#include "Game.h"


Game::Game(sf::RenderWindow* win)
{
	window = win;

	RenderSystem* tempSys = new RenderSystem();
	tempSys->window = win;
	systemManager.AddSystem(tempSys);

	GameObject* testi = new GameObject;

	testi->AddComponent(RenderComponentFactory::GetInstance()->CreateRenderComponent("pslogo.png"));
	//testi.GetComponent<Render>()->texture->setSmooth(true);


	Transform* tempTransform = new Transform;
	tempTransform->origin = sf::Vector2f(32, 32);
	tempTransform->position = sf::Vector2f(400, 300);
	testi->AddComponent(tempTransform);

	gameObjectList.push_back(testi);
	player = gameObjectList.at(0);
}

Game::~Game()
{
	for (int i = 0; i < gameObjectList.size(); i++)
	{
		delete gameObjectList[i];
	}
	gameObjectList.clear();
}

void Game::Update(float dt)
{
	UpdateControls(dt);
}

void Game::Draw()
{
	systemManager.Update(&gameObjectList);
}

void Game::UpdateControls(float dt)
{
	player->GetComponent<Transform>()->rotation += 50 * dt;

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Q))
		player->GetComponent<Transform>()->rotation += 100 * dt;
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::E))
		player->GetComponent<Transform>()->rotation -= 100 * dt;

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
	{
		player->GetComponent<Transform>()->scale.x += 10 * dt;
		player->GetComponent<Transform>()->scale.y += 10 * dt;
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
	{
		player->GetComponent<Transform>()->scale.x -= 10 * dt;
		player->GetComponent<Transform>()->scale.y -= 10 * dt;
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
		player->GetComponent<Transform>()->position.x -= 100 * dt;
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
		player->GetComponent<Transform>()->position.x += 100 * dt;
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
		player->GetComponent<Transform>()->position.y -= 100 * dt;
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
		player->GetComponent<Transform>()->position.y += 100 * dt;

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
		window->close();
}