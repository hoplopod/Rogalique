
#include "Application.h"
#include "Constants.h"

namespace Rogalique {

	Application& Application::Instance()
	{
		static Application instance;
		return instance;
	}

	Application::Application() :window(sf::VideoMode(SCREEN_WIDTH, SCREEN_HEIGHT), GAME_NAME) {};

	void Application::Run()
	{
		
		game.InitializeGame();

		while (window.isOpen()) {

			if (game.RestartClock == true) {
				gameClock.restart();
				lastTime = 0.f;
				game.RestartClock = false;
			}

			sf::sleep(sf::milliseconds(16));
			currentTime = gameClock.getElapsedTime().asSeconds();
			deltaTime = currentTime - lastTime;
			lastTime = currentTime;

			sf::Event event;
			while (window.pollEvent(event))
			{
				if (event.type == sf::Event::Closed)
					window.close();
			}

			game.Update(deltaTime, window);

			if (sf::Keyboard::isKeyPressed(sf::Keyboard::BackSpace)) {
				window.close();
			}

		}
	}

}