#include "Game.h"

namespace PinGame {

	void Game::Update(float deltaTime, sf::RenderWindow& window)
	{

		switch (GameState)
		{
		case GameStating::Menu: {
			RestartGame();
			GameMenu(window);
			break;
		}
		case GameStating::Playing: {
			GamePlaying(window, deltaTime);
			break;
		}
		case GameStating::End: {
			EndGame(window);
			break;
		}
		default:
			break;
		}

	}

	void Game::GameMenu(sf::RenderWindow& window)
	{

		while (GameState == GameStating::Menu && window.isOpen())
		{

			menu.button1.setColor(sf::Color::White);
			menu.button2.setColor(sf::Color::White);
			menu.button2_2.setColor(sf::Color::White);
			menu.button3.setColor(sf::Color::White);
			menu.button4.setColor(sf::Color::White);
			window.clear();

			menu.TypeButton = MenuSelection::Nothing;
			if (sf::IntRect(30, 230, 180, 90).contains(sf::Mouse::getPosition(window))) { menu.button1.setColor(sf::Color::Red);  menu.TypeButton = MenuSelection::Play; }
			if (sf::IntRect(30, 325, 375, 75).contains(sf::Mouse::getPosition(window))) { menu.button2.setColor(sf::Color::Red);  menu.TypeButton = MenuSelection::Load; }
			if (sf::IntRect(450, 500, 300, 60).contains(sf::Mouse::getPosition(window))) { menu.button2_2.setColor(sf::Color::Red);  menu.TypeButton = MenuSelection::Save; }
			if (sf::IntRect(30, 400, 150, 75).contains(sf::Mouse::getPosition(window))) { menu.button3.setColor(sf::Color::Red);  menu.TypeButton = MenuSelection::Score; }
			if (sf::IntRect(30, 475, 150, 75).contains(sf::Mouse::getPosition(window))) { menu.button4.setColor(sf::Color::Red);  menu.TypeButton = MenuSelection::Exit; }

			if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
				switch (menu.TypeButton)
				{
				case MenuSelection::Play: {
					GameState = GameStating::Playing;
					break;
				}
				case MenuSelection::Load: {
					GameLoad();
					break;
				}
				case MenuSelection::Save: {
					GameSave();
					break;
				}
				case MenuSelection::Score: {
					sf::sleep(sf::milliseconds(100));
					ScoreMenu(window);
					break;
				}
				case MenuSelection::Exit: {
					window.close();
					break;
				}
				default:
					break;
				}
			}

			window.draw(menu.logo);

			window.draw(menu.button1);
			window.draw(menu.button2);
			window.draw(menu.button2_2);
			window.draw(menu.button3);
			window.draw(menu.button4);

			window.display();

		}
		sf::sleep(sf::milliseconds(100));

	}

	void Game::ScoreMenu(sf::RenderWindow& window)
	{

		while (window.isOpen()) {
			
			//Button

			menu.button6_2.setColor(sf::Color::White);
			window.clear();

			menu.TypeButton = MenuSelection::Nothing;
			if (sf::IntRect(10, 10, 120, 60).contains(sf::Mouse::getPosition(window))) { menu.button6_2.setColor(sf::Color::Red);  menu.TypeButton = MenuSelection::Exit; }
			if (sf::Mouse::isButtonPressed(sf::Mouse::Left) && menu.TypeButton == MenuSelection::Exit) break;

			window.draw(menu.button6_2);

			//Text score

			text.Score.setString(L"Ëó÷øèé ñ÷¸ò:");
			text.Score.setCharacterSize(40);
			text.Score.setPosition(280.f, 100.f);
			window.draw(text.Score);

			text.Score.setString(std::to_string(BestScore));
			text.Score.setCharacterSize(50);
			text.Score.setPosition(380.f, 150.f);
			window.draw(text.Score);

			text.Score.setString(L"Ïîïûòêè:");
			text.Score.setCharacterSize(40);
			text.Score.setPosition(320.f, 250.f);
			window.draw(text.Score);

			text.Score.setCharacterSize(30);
			int num1 = -1, num2 = -5;
			for (int i = 0; i < 10; ++i) {
				if (i % 5 == 0) { num1++; num2 += 5;  }
				text.Score.setString(std::to_string(AllScore[9-i]));
				text.Score.setPosition(340.f + 75*num1, 300.f + 50*(i-num2));
				window.draw(text.Score);
			}

			window.display();
		}
		sf::sleep(sf::milliseconds(100));
	}

	void PinGame::Game::GamePaused(sf::RenderWindow& window)
	{
		while (window.isOpen() && GameState == GameStating::pause) {

			menu.button7.setColor(sf::Color::White);
			menu.button6.setColor(sf::Color::White);
			menu.button2_2_2.setColor(sf::Color::White);
			window.clear();

			menu.TypeButton = MenuSelection::Nothing;
			if (sf::IntRect(275, 230, 224, 96).contains(sf::Mouse::getPosition(window))) { menu.button7.setColor(sf::Color::Red);  menu.TypeButton = MenuSelection::Play; }
			if (sf::IntRect(320, 325, 120, 60).contains(sf::Mouse::getPosition(window))) { menu.button6.setColor(sf::Color::Red);  menu.TypeButton = MenuSelection::Exit; }
			if (sf::IntRect(550, 550, 225, 45).contains(sf::Mouse::getPosition(window))) { menu.button2_2_2.setColor(sf::Color::Red);  menu.TypeButton = MenuSelection::Save; }

			if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
				switch (menu.TypeButton)
				{
				case MenuSelection::Play: {
					GameState = GameStating::Playing;
					break;
				}
				case MenuSelection::Exit: {
					GameState = GameStating::Menu;
					break;
				}
				case MenuSelection::Save: {
					GameState = GameStating::Playing;
					GameSave();
					GameState = GameStating::pause;
					break;
				}
				default:
					break;
				}
			}

			//Fone
			player.RectangleObject.setPosition(player.ObjectPosition.x, player.ObjectPosition.y);
			window.draw(player.RectangleObject);

			ball.RectangleObject.setPosition(ball.ObjectPosition.x, ball.ObjectPosition.y);
			window.draw(ball.CircleObject);

			for (int i = 0; i < NumBlock; ++i) {
				if (blocks.Block[i].DieBlock != TypeBlocks::DieBlock) window.draw(blocks.Block[i].RectangleObject);
			}

			for (int i = 0; i < bonus.current_Bonus.size(); ++i) {
				window.draw(bonus.current_Bonus[i]);
			}
			window.draw(menu.fone1);

			text.Score.setString(L"Ñ÷¸ò:");
			text.Score.setCharacterSize(30);
			text.Score.setPosition(600.f, 10.f);
			window.draw(text.Score);
			text.Score.setString(std::to_string(Score));
			text.Score.setPosition(700.f, 10.f);
			window.draw(text.Score);

			window.draw(menu.pause_logo);
			window.draw(menu.button7);
			window.draw(menu.button6);
			window.draw(menu.button2_2_2);

			window.display();
		}
		RestartClock = true;
	}

	void Game::EndGame(sf::RenderWindow& window)
	{

		while (GameState == GameStating::End && window.isOpen())
		{
			menu.button5.setColor(sf::Color::White);
			menu.button6.setColor(sf::Color::White);
			window.clear();

			menu.TypeButton = MenuSelection::Nothing;
			if (sf::IntRect(320, 250, 120, 60).contains(sf::Mouse::getPosition(window))) { menu.button5.setColor(sf::Color::Red);  menu.TypeButton = MenuSelection::Play; }
			if (sf::IntRect(320, 325, 120, 60).contains(sf::Mouse::getPosition(window))) { menu.button6.setColor(sf::Color::Red);  menu.TypeButton = MenuSelection::Exit; }

			if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
				switch (menu.TypeButton)
				{
				case MenuSelection::Play: {
					GameState = GameStating::Playing;
					break;
				}
				case MenuSelection::Exit: {
					GameState = GameStating::Menu;
					break;
				}
				default:
					break;
				}
			}

			text.Score.setString(L"Ñ÷¸ò:");
			text.Score.setCharacterSize(30);
			text.Score.setPosition(320.f, 200.f);
			window.draw(text.Score);
			text.Score.setString(std::to_string(Score));
			text.Score.setPosition(420.f, 200.f);
			window.draw(text.Score);

			switch (State_end)
			{
			case GameStating::end_Lose: {
				window.draw(menu.lose_logo);
				break;
			}
			case GameStating::end_Win: {
				window.draw(menu.win_logo);
				break;
			}
			default:
				break;
			}

			window.draw(menu.button5);
			window.draw(menu.button6);

			window.display();
		}
		//Score
		if (BestScore < Score) BestScore = Score;
		AllScore.erase(AllScore.begin());
		AllScore.push_back(Score);
		Score = 0;

		RestartGame();
		sf::sleep(sf::milliseconds(100));

	}

}