#include "Game.h"
#include "GameObject.h"
#include "Render.h"
#include "Transform.h"
#include <SFML/Graphics.hpp>

int main()
{
	sf::RenderWindow window(sf::VideoMode(800, 600), "EntityComponentSystem");
	sf::Clock clock;

	Game game(&window);
	
	
	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}
		sf::Time dt = clock.restart();
		game.Update(dt.asSeconds());

		window.clear();

		game.Draw();

		window.display();
	}

	return 0;
}