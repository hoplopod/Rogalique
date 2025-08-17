#include "Game.h"

namespace Rogalique {

	void Game::DrawPlay(sf::RenderWindow& window)
	{

		window.clear();

		text.Score.setString(L"Ñ÷¸ò:");
		text.Score.setCharacterSize(30);
		text.Score.setPosition(600.f, 10.f);
		window.draw(text.Score);
		text.Score.setString(std::to_string(Score));
		text.Score.setPosition(700.f, 10.f);
		window.draw(text.Score);

		player.RectangleObject.setPosition(player.ObjectPosition.x, player.ObjectPosition.y);
		window.draw(player.RectangleObject);

		ball.CircleObject.setPosition(ball.ObjectPosition.x, ball.ObjectPosition.y);
		window.draw(ball.CircleObject);

		for (int i = 0; i < NumBlock; ++i) {
			if (blocks.Block[i].DieBlock != TypeBlocks::DieBlock) window.draw(blocks.Block[i].RectangleObject);
		}

		for (int i = 0; i < bonus.current_Bonus.size(); ++i) {
			window.draw(bonus.current_Bonus[i]);
		}

		window.display();

	}

	void Game::PlayerMove(float deltaTime) {
		if (player.ObjectPosition.x >= SCREEN_WIDTH - (PlayerRectangle1 + bonus.bonus_platform) / 2.f || player.ObjectPosition.x > (PlayerRectangle1 + bonus.bonus_platform) / 2.f) {
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
				player.playerDirection = Mooving::Left;
			}
		}

		if (player.ObjectPosition.x <= (PlayerRectangle1 + bonus.bonus_platform) / 2.f || player.ObjectPosition.x < SCREEN_WIDTH - (PlayerRectangle1 + bonus.bonus_platform) / 2.f) {
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
				player.playerDirection = Mooving::Right;
			}
		}

		switch (player.playerDirection)
		{
		case Mooving::Left: {
			player.ObjectPosition.x -= INITIAL_SPEED * deltaTime * bonus.bonus_speed;
			break;
		}
		case Mooving::Right: {
			player.ObjectPosition.x += INITIAL_SPEED * deltaTime * bonus.bonus_speed;
			break;
		}
		}

		player.playerDirection = Mooving::Stop;
	}

	bool Game::BallCollige(Position2D ObjectPosition, float ObjectRectangle1, float ObjectRectangle2) {
		switch (isCircleCollide(ObjectPosition, { ObjectRectangle1 , ObjectRectangle2 }, ball.ObjectPosition, BallSize))
		{
		case -1: {

			sound.PinPon.play();
			ball.BallDirectionX *= -1;
			ball.BallDirectionY *= -1;
			ball.CosBall = 1;
			ball.SinBall = 1;
			ball.ObjectPosition.x += (error_rate * ball.BallDirectionX);
			ball.ObjectPosition.y += (error_rate * ball.BallDirectionY);

			return true;
		}
		case 0: {
			return false;
		}
		case 1: {

			sound.PinPon.play();
			ball.BallDirectionX *= -1;
			ball.CosBall = cos(Randomazer(0, 45) * PI / 180.f);
			ball.SinBall = 2.f - ball.CosBall;
			ball.ObjectPosition.x += (error_rate * ball.BallDirectionX);

			return true;
		}
		case 2: {

			sound.PinPon.play();
			ball.BallDirectionY *= -1;
			ball.SinBall = sin(Randomazer(45, 90) * PI / 180.f);
			ball.CosBall = 2.f - ball.SinBall;
			ball.ObjectPosition.y += (error_rate * ball.BallDirectionY);

			return true;
		}
		default:
			break;
		}

		return 0;
	}
	

	void Game::BlockCollige()
	{
		for (int i = 0; i < NumBlock; ++i) {
			if (blocks.Block[i].DieBlock != TypeBlocks::DieBlock) {
				if (BallCollige(blocks.Block[i].ObjectPosition, BlockRectangle1, BlockRectangle2)) {
					switch (blocks.Block[i].DieBlock)
					{
					case TypeBlocks::UsualBlock: {
						Score++;
						bonus.ChanceOfBonus(blocks.Block[i].ObjectPosition);
						blocks.Block[i].DieBlock = TypeBlocks::DieBlock;
						BrokenBlocks -= 1;
						break;
					}
					case TypeBlocks::StrongBlock: {
						break;
					}
					case TypeBlocks::FragileBlock: {
						Score++;
						blocks.Block[i].DieBlock = TypeBlocks::UsualBlock;
						blocks.Block[i].RectangleObject.setFillColor(sf::Color::White);
						break;
					}
					default:
						break;
					}
				}
			}
		}
	}

	void Game::BonusBlockCollige()
	{
		for (int i = 0; i < NumBlock; ++i) {
			if (blocks.Block[i].DieBlock != TypeBlocks::DieBlock) {
				if (bonus.TimeOfBonus[1] != 0) {
					if (BallCollige(blocks.Block[i].ObjectPosition, BlockRectangle1, BlockRectangle2)) {
						Score++;
						blocks.Block[i].DieBlock = TypeBlocks::DieBlock;
						BrokenBlocks -= 1;
					}
				}
				else if (bonus.TimeOfBonus[0] != 0)
					if (isCircleCollide(blocks.Block[i].ObjectPosition, { BlockRectangle1, BlockRectangle2 }, ball.ObjectPosition, BallSize) != 0) {
						Score++;
						blocks.Block[i].DieBlock = TypeBlocks::DieBlock;
						BrokenBlocks -= 1;
					}
			}
		}
	}

	void Game::AllCollige(sf::RenderWindow& window)
	{
		if (bonus.TimeOfBonus[0] != 0 || bonus.TimeOfBonus[1] != 0) {
			BonusBlockCollige();
		} else BlockCollige();

		BallCollige(player.ObjectPosition, PlayerRectangle1 + bonus.bonus_platform, PlayerRectangle2);

		if (ball.ObjectPosition.y <= BallSize) {
			ball.BallDirectionY *= -1;
			ball.SinBall = sin(Randomazer(45, 90) * PI / 180.f);
			ball.CosBall = 2.f - ball.SinBall;
			ball.ObjectPosition.y += (error_rate * ball.BallDirectionY);
			sound.PinPon.play();
		}

		if (ball.ObjectPosition.x >= SCREEN_WIDTH - BallSize || ball.ObjectPosition.x <= BallSize) {
			ball.BallDirectionX *= -1;
			ball.CosBall = cos(Randomazer(0, 45) * PI / 180.f);
			ball.SinBall = 2.f - ball.CosBall;
			ball.ObjectPosition.x += (error_rate * ball.BallDirectionX);
			sound.PinPon.play();
		}

		if (ball.ObjectPosition.y >= SCREEN_HEIGHT - BallSize) {
			if (ball.Ball_health != 0) {
				ball.Ball_health--;
				BallRespawn();
			}
			else {
				sound.Deth.play();
				State_end = GameStating::end_Lose;
				GameState = GameStating::End;
			}
			
		}

		if (BrokenBlocks == 0) {
			sound.Win.play();
			State_end = GameStating::end_Win;
			GameState = GameStating::End;
		}

	}

	void Ball::BallMoving(float deltaTime) {
		ObjectPosition.y += INITIAL_BALL_SPEED * deltaTime * BallDirectionY * SinBall;
		ObjectPosition.x += INITIAL_BALL_SPEED * deltaTime * BallDirectionX * CosBall;
	}

	void Game::Bonus_move(float deltaTime, int current_bonus)
	{
		bonus.ObjectPosition.x = bonus.current_Bonus[current_bonus].getPosition().x;
		bonus.ObjectPosition.y = bonus.current_Bonus[current_bonus].getPosition().y;
		bonus.ObjectPosition.y += INITIAL_BONUS_SPEED * deltaTime;
		bonus.current_Bonus[current_bonus].setPosition(bonus.ObjectPosition.x, bonus.ObjectPosition.y);
	}

	bool Game::Bonus_collige(int current_bonus)
	{
		
		if (isRectangleCollige(player.ObjectPosition, { PlayerRectangle1 + bonus.bonus_platform, PlayerRectangle2 }, { bonus.ObjectPosition.x + 30.f, bonus.ObjectPosition.y + 30.f }, { 60.f, 60.f }) == 1) {
			switch (bonus.current_type_Bonus[current_bonus])
			{
			case BonusType::fire_ball: {
				bonus.TimeOfBonus[0] = gameBonusClock.getElapsedTime().asSeconds();
				ball.CircleObject.setFillColor(sf::Color::Red);
				break;
			}
			case BonusType::fragile_blocks: {
				for (int i = 0; i < NumBlock; ++i) {
					blocks.Block[i].RectangleObject.setFillColor(sf::Color::Green);
				}
				bonus.TimeOfBonus[1] = gameBonusClock.getElapsedTime().asSeconds();
				break;
			}
			case BonusType::long_and_slow: {
				bonus.bonus_platform = 60.f;
				bonus.bonus_speed = 0.5f;
				player.RectangleObject.setSize(sf::Vector2f(PlayerRectangle1 + bonus.bonus_platform, PlayerRectangle2));
				player.RectangleObject.setOrigin(sf::Vector2f((PlayerRectangle1 + bonus.bonus_platform) / 2.f, PlayerRectangle2 / 2.f));
				bonus.TimeOfBonus[2] = gameBonusClock.getElapsedTime().asSeconds();
				break;
			}
			case BonusType::short_and_fast: {
				bonus.bonus_platform = -30.f;
				bonus.bonus_speed = 5.f;
				player.RectangleObject.setSize(sf::Vector2f(PlayerRectangle1 + bonus.bonus_platform, PlayerRectangle2));
				player.RectangleObject.setOrigin(sf::Vector2f((PlayerRectangle1 + bonus.bonus_platform) / 2.f, PlayerRectangle2 / 2.f));
				bonus.TimeOfBonus[3] = gameBonusClock.getElapsedTime().asSeconds();
				break;
			}
			default:
				break;
			}

			return true;
		}
		else return false;
	}

	void Game::BonusSystem(sf::RenderWindow& window, float deltaTime)
	{
		for (int i = 0; i < bonus.current_Bonus.size(); ++i) {

			Bonus_move(deltaTime, i);

			if (Bonus_collige(i) == true || bonus.ObjectPosition.y >= SCREEN_HEIGHT) {
				bonus.current_Bonus.erase(bonus.current_Bonus.begin() + i);
				bonus.current_type_Bonus.erase(bonus.current_type_Bonus.begin() + i);
				--i;
			}
		}
		for (int j = 0; j < 4; ++j) {
			if (gameBonusClock.getElapsedTime().asSeconds() - bonus.TimeOfBonus[j] >= HOW_LONG_TIME_BONUS) {
				bonus.TimeOfBonus[j] = 0;
				switch (j)
				{
				case 0: {
					ball.CircleObject.setFillColor(sf::Color::White);
					break;
				}
				case 1: {
					ColorBlock();
					break;
				}
				default: {
					if (bonus.TimeOfBonus[2] == 0 && bonus.TimeOfBonus[3] == 0) {
						player.RectangleObject.setSize(sf::Vector2f(PlayerRectangle1, PlayerRectangle2));
						player.RectangleObject.setOrigin(sf::Vector2f(PlayerRectangle1 / 2.f, PlayerRectangle2 / 2.f));
						bonus.bonus_platform = 0;
						bonus.bonus_speed = 1;

					}
					break;
				}

				}
			}

		}
	}

	void Game::GamePlaying(sf::RenderWindow& window, float deltaTime)
	{
		ball.BallMoving(deltaTime);

		AllCollige(window);

		PlayerMove(deltaTime);

		BonusSystem(window, deltaTime);

		DrawPlay(window);

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)) {
			GameState = GameStating::pause;
			GamePaused(window);
		}
	}

}
