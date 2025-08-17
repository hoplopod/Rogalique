#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <vector>
#include <fstream>

#include "GameObject.h"
#include "MathGame.h"

namespace Rogalique {

	class Game {
	public:

		void Update(float deltaTime, sf::RenderWindow& window);

		void InitializeGame();

		void EndGame(sf::RenderWindow& window);

		void GameMenu(sf::RenderWindow& window);

		void ScoreMenu(sf::RenderWindow& window);

		void GamePlaying(sf::RenderWindow& window, float deltaTime);

		void RestartGame();

		void GamePaused(sf::RenderWindow& window);

		void GameSave();

		void GameLoad();

		bool RestartClock = false;

		int Score = 0;

		int BestScore = 0;

		std::vector<int> AllScore = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};

		GameStating GameState = GameStating::Menu;
		GameStating State_end = GameStating::end_Lose;

		sf::Clock gameBonusClock;

		std::fstream save_file;

	private:
		Player player;
		Text text;
		Sound sound;
		Menu menu;

	};

}
