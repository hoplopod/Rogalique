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

		bool BallCollige(Position2D ObjectPosition, float ObjectRectangle1, float ObjectRectangle2);

		bool Bonus_collige(int current_bonus);

		void BonusBlockCollige();

		void BlockCollige();

		void AllCollige(sf::RenderWindow& window);

		void Update(float deltaTime, sf::RenderWindow& window);

		void InitializeGame();

		void DrawPlay(sf::RenderWindow& window);

		void EndGame(sf::RenderWindow& window);

		void GameMenu(sf::RenderWindow& window);

		void ScoreMenu(sf::RenderWindow& window);

		void GamePlaying(sf::RenderWindow& window, float deltaTime);

		void RestartGame();

		void BonusSystem(sf::RenderWindow& window, float deltaTime);

		void Bonus_move(float deltaTime, int current_bonus);

		void PlayerMove(float deltaTime);

		void BallRespawn();

		void GamePaused(sf::RenderWindow& window);

		void GameSave();

		void GameLoad();

		void ColorBlock();

		bool RestartClock = false;

		int BrokenBlocks = NumBlock;

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
		Ball ball;
		Sound sound;
		Menu menu;
		Bonuses bonus;

		Blocks blocks;
	};

}
