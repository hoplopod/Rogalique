
#include <SFML/Graphics.hpp>

#include "Game.h"
#include "Engine.h"

namespace Rogalique {


	class Application{
	public:
		Application(const Application& app) = delete;
		Application& operator = (const Application&) = delete;

		static Application& Instance();

		void Run();

		sf::Clock gameClock;
		float lastTime = 0.f;
		float currentTime = 0.f;
		float deltaTime = 0.f;

	private:
		Engine engine;

		Game game;
		sf::RenderWindow window;

	private:
		Application();
		~Application() = default;
	};
}