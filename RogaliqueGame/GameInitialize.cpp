#include <cassert>

#include "Game.h"

namespace Rogalique {

	void Game::InitializeGame()
	{

		//Menu
		//Logo 
		assert(menu.texture_logo.loadFromFile("Resources/MenuImages/\\LogoImage.png"));
		menu.texture_logo.loadFromFile("Resources/MenuImages/\\LogoImage.png");
		menu.texture_logo.setSmooth(true);

		menu.logo.setTexture(menu.texture_logo);
		menu.logo.setTextureRect(sf::IntRect(0, 0, 1000, 700));
		menu.logo.setScale(sf::Vector2f(0.3f, 0.3f));
		menu.logo.setPosition(250.f, 30.f);
		menu.logo.setColor(sf::Color::White);

		//Deth_Text
		assert(menu.texture_lose_logo.loadFromFile("Resources/MenuImages/\\LoseImage1.png"));
		menu.texture_lose_logo.loadFromFile("Resources/MenuImages/\\LoseImage1.png");
		menu.texture_lose_logo.setSmooth(true);

		menu.lose_logo.setTexture(menu.texture_lose_logo);
		menu.lose_logo.setTextureRect(sf::IntRect(0, 0, 1000, 700));
		menu.lose_logo.setScale(sf::Vector2f(0.5f, 0.5f));
		menu.lose_logo.setPosition(230.f, 80.f);
		menu.lose_logo.setColor(sf::Color::White);

		//Win_Text
		assert(menu.texture_win_logo.loadFromFile("Resources/MenuImages/\\WinImage.png"));
		menu.texture_win_logo.loadFromFile("Resources/MenuImages/\\WinImage.png");
		menu.texture_win_logo.setSmooth(true);

		menu.win_logo.setTexture(menu.texture_win_logo);
		menu.win_logo.setTextureRect(sf::IntRect(0, 0, 1000, 700));
		menu.win_logo.setScale(sf::Vector2f(0.5f, 0.5f));
		menu.win_logo.setPosition(230.f, 80.f);
		menu.win_logo.setColor(sf::Color::White);

		//Pause_Text
		assert(menu.texture_pause_logo.loadFromFile("Resources/MenuImages/\\MenuImage5.png"));
		menu.texture_pause_logo.loadFromFile("Resources/MenuImages/\\MenuImage5.png");
		menu.texture_pause_logo.setSmooth(true);

		menu.pause_logo.setTexture(menu.texture_pause_logo);
		menu.pause_logo.setTextureRect(sf::IntRect(0, 0, 600, 300));
		menu.pause_logo.setScale(sf::Vector2f(0.25f, 0.25f));
		menu.pause_logo.setPosition(310.f, 150.f);
		menu.pause_logo.setColor(sf::Color::White);

		//button 1
		assert(menu.texture_button1.loadFromFile("Resources/MenuImages/\\MenuImage1.png"));
		menu.texture_button1.loadFromFile("Resources/MenuImages/\\MenuImage1.png");
		menu.texture_button1.setSmooth(true);

		menu.button1.setTexture(menu.texture_button1);
		menu.button1.setTextureRect(sf::IntRect(0, 0, 600, 300));
		menu.button1.setScale(sf::Vector2f(0.3f, 0.3f));
		menu.button1.setPosition(30.f, 230.f);
		menu.button1.setColor(sf::Color::White);

		//button 2
		assert(menu.texture_button2.loadFromFile("Resources/MenuImages/\\MenuImage2.png"));
		menu.texture_button2.loadFromFile("Resources/MenuImages/\\MenuImage2.png");
		menu.texture_button2.setSmooth(true);

		menu.button2.setTexture(menu.texture_button2);
		menu.button2.setTextureRect(sf::IntRect(0, 0, 1500, 300));
		menu.button2.setScale(sf::Vector2f(0.25f, 0.25f));
		menu.button2.setPosition(30.f, 325.f);
		menu.button2.setColor(sf::Color::White);

		//button 2_2
		assert(menu.texture_button2_2.loadFromFile("Resources/MenuImages/\\MenuImage2_2.png"));
		menu.texture_button2_2.loadFromFile("Resources/MenuImages/\\MenuImage2_2.png");
		menu.texture_button2_2.setSmooth(true);

		menu.button2_2.setTexture(menu.texture_button2_2);
		menu.button2_2.setTextureRect(sf::IntRect(0, 0, 1500, 300));
		menu.button2_2.setScale(sf::Vector2f(0.2f, 0.2f));
		menu.button2_2.setPosition(450.f, 500.f);
		menu.button2_2.setColor(sf::Color::White);

		//button 2_2_2
		menu.button2_2_2 = menu.button2_2;
		menu.button2_2_2.setScale(sf::Vector2f(0.15f, 0.15f));
		menu.button2_2_2.setPosition(550.f, 550.f);

		//button 3
		assert(menu.texture_button3.loadFromFile("Resources/MenuImages/\\MenuImage3.png"));
		menu.texture_button3.loadFromFile("Resources/MenuImages/\\MenuImage3.png");
		menu.texture_button3.setSmooth(true);

		menu.button3.setTexture(menu.texture_button3);
		menu.button3.setTextureRect(sf::IntRect(0, 0, 600, 300));
		menu.button3.setScale(sf::Vector2f(0.25f, 0.25f));
		menu.button3.setPosition(30.f, 400.f);
		menu.button3.setColor(sf::Color::White);

		//button 4
		assert(menu.texture_button4.loadFromFile("Resources/MenuImages/\\MenuImage4.png"));
		menu.texture_button4.loadFromFile("Resources/MenuImages/\\MenuImage4.png");
		menu.texture_button4.setSmooth(true);

		menu.button4.setTexture(menu.texture_button4);
		menu.button4.setTextureRect(sf::IntRect(0, 0, 600, 300));
		menu.button4.setScale(sf::Vector2f(0.25f, 0.25f));
		menu.button4.setPosition(30.f, 475.f);
		menu.button4.setColor(sf::Color::White);

		//button 5
		assert(menu.texture_button5.loadFromFile("Resources/MenuImages/\\LoseImage2.png"));
		menu.texture_button5.loadFromFile("Resources/MenuImages/\\LoseImage2.png");
		menu.texture_button5.setSmooth(true);

		menu.button5.setTexture(menu.texture_button5);
		menu.button5.setTextureRect(sf::IntRect(0, 0, 600, 300));
		menu.button5.setScale(sf::Vector2f(0.2f, 0.2f));
		menu.button5.setPosition(320.f, 250.f);
		menu.button5.setColor(sf::Color::White);

		//button 6
		assert(menu.texture_button6.loadFromFile("Resources/MenuImages/\\LoseImage3.png"));
		menu.texture_button6.loadFromFile("Resources/MenuImages/\\LoseImage3.png");
		menu.texture_button6.setSmooth(true);

		menu.button6.setTexture(menu.texture_button6);
		menu.button6.setTextureRect(sf::IntRect(0, 0, 600, 300));
		menu.button6.setScale(sf::Vector2f(0.2f, 0.2f));
		menu.button6.setPosition(320.f, 325.f);
		menu.button6.setColor(sf::Color::White);

		//button 7
		assert(menu.texture_button7.loadFromFile("Resources/MenuImages/\\MenuImage6.png"));
		menu.texture_button7.loadFromFile("Resources/MenuImages/\\MenuImage6.png");
		menu.texture_button7.setSmooth(true);

		menu.button7.setTexture(menu.texture_button7);
		menu.button7.setTextureRect(sf::IntRect(0, 0, 700, 300));
		menu.button7.setScale(sf::Vector2f(0.32f, 0.32f));
		menu.button7.setPosition(275.f, 230.f);
		menu.button7.setColor(sf::Color::White);

		//button6_2
		menu.button6_2 = menu.button6;
		menu.button6_2.setPosition(10.f, 10.f);

		//Fone 1
		assert(menu.texture_fone1.loadFromFile("Resources/MenuImages/\\FoneImage1.png"));
		menu.texture_fone1.loadFromFile("Resources/MenuImages/\\FoneImage1.png");
		menu.texture_fone1.setSmooth(true);

		menu.fone1.setTexture(menu.texture_fone1);
		menu.fone1.setTextureRect(sf::IntRect(0, 0, 800, 600));
		menu.fone1.setScale(sf::Vector2f(1, 1));
		menu.fone1.setPosition(0,0);

		//Text
		assert(text.Cascadia.loadFromFile("Resources/\\CascadiaMono.ttf"));
		text.Cascadia.loadFromFile("Resources/\\CascadiaMono.ttf");
		text.Score.setFont(text.Cascadia);
		text.Score.setStyle(sf::Text::Bold);
		text.Score.setFillColor(sf::Color::White);
		text.Score.setCharacterSize(20);

		//Sound
		//Die
		assert(sound.PlayerDie.loadFromFile("Resources/\\GameOver.wav"));
		sound.PlayerDie.loadFromFile("Resources/\\GameOver.wav");
		sound.Deth.setBuffer(sound.PlayerDie);
		sound.Deth.setVolume(50.f);

		//Win
		assert(sound.PlayerWin.loadFromFile("Resources/\\Win.wav"));
		sound.PlayerWin.loadFromFile("Resources/\\Win.wav");
		sound.Win.setBuffer(sound.PlayerWin);
		sound.Win.setVolume(50.f);

		//Pin
		assert(sound.Pong.loadFromFile("Resources/\\Pin.wav"));
		sound.Pong.loadFromFile("Resources/\\Pin.wav");
		sound.PinPon.setBuffer(sound.Pong);
		sound.PinPon.setVolume(40.f);
	}

	void Game::RestartGame()
	{
			RestartClock = true;
	}

	void Game::GameSave()
	{
		save_file.open(PATH_TO_SAVE, std::fstream::out);

		switch (GameState) {
		case GameStating::Menu: {
			save_file << 0 << std::endl;

			//Save score
			save_file << BestScore << std::endl;

			for (int i = 0; i < AllScore.size(); ++i) {
				save_file << AllScore[i] << " ";
			}

			break;
		}
		case GameStating::Playing: {
			save_file << 1 << std::endl;

			//Save score
			save_file << BestScore << std::endl;

			for (int i = 0; i < AllScore.size(); ++i) {
				save_file << AllScore[i] << " ";
			}
			save_file <<std::endl;

			break;
		}
		default: break;
		}
		
		save_file.close();
	}

	void Game::GameLoad()
	{
		save_file.open(PATH_TO_SAVE, std::fstream::in);
		int numState, numBlock;
		save_file >> numState;

		switch (numState)
		{
		case 0: {
			save_file >> BestScore;

			for (int i = 0; i < AllScore.size(); ++i) {
				save_file  >> AllScore[i];
			}

			break;
		}
		case 1: {
			save_file >> BestScore;
		}
		default:
			break;
		}

		save_file.close();
	}

}