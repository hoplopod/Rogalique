#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <vector>
#include <cassert>

#include "Constants.h"
#include "MathGame.h"


namespace PinGame {

	enum class Mooving {
		Stop = -1,
		Right,
		Left
	};

	enum class GameStating {
		Menu = 0,
		Playing,
		End,
		pause,
		end_Lose,
		end_Win
	};

	enum class TypeBlocks {
		StrongBlock = -1,
		DieBlock,
		UsualBlock,
		FragileBlock
	};

	enum class MenuSelection {
		Nothing = 0,
		Play,
		Load,
		Save,
		Score,
		Exit
	};

	enum class BonusType {
		fire_ball = 0,
		fragile_blocks,
		short_and_fast,
		long_and_slow
	};

	class GameObject {
	public:

		Position2D ObjectPosition;

		sf::CircleShape CircleObject;
		sf::RectangleShape RectangleObject;

		sf::RectangleShape InitBlock(sf::RectangleShape BlockShape, float BlockRectangle1, float  BlockRectangle2);

		sf::CircleShape InitCycle(sf::CircleShape CycleShape, float CycleSize, Position2D CyclePosition);

	};

	class Menu {
	
	public:

		sf::Texture texture_logo, texture_lose_logo, texture_win_logo, texture_pause_logo, texture_button1, texture_button2, texture_button2_2, texture_button3,
					texture_button4, texture_button5, texture_button6, texture_button7, texture_fone1;
		sf::Sprite logo, lose_logo, win_logo, pause_logo, button1, button2, button2_2, button2_2_2, button3, button4, button5, button6, button6_2, button7, fone1;

		MenuSelection TypeButton = MenuSelection::Nothing;

	};

	class Ball : public GameObject {
	public:

		int BallDirectionX = 1;
		int BallDirectionY = -1;

		float SinBall = 1;
		float CosBall = 0;

		int Ball_health = 2;

		void BallMoving(float deltaTime);
	};

	class Sound : public GameObject {
	public:

		sf::Sound PinPon;
		sf::SoundBuffer Pong;

		sf::Sound Deth;
		sf::SoundBuffer PlayerDie;

		sf::Sound Win;
		sf::SoundBuffer PlayerWin;

	};

	class Text : public GameObject {
	public:

		sf::Text Score;
		sf::Font Cascadia;

	};

	class Blocks : public GameObject{
	public:

		TypeBlocks DieBlock;

		std::vector<Blocks> Block;

		int NotBrokeBlocks = 0;

	};

	class Bonuses : public GameObject {
	public:

		BonusType TypeOfBonus;

		sf::Sprite bonus1, bonus2, bonus3, bonus4;
		sf::Texture texture_bonus1, texture_bonus2, texture_bonus3, texture_bonus4;

		std::vector<sf::Sprite> current_Bonus;
		std::vector<BonusType> current_type_Bonus;
		float TimeOfBonus[4] = {0, 0, 0, 0};
		
		float bonus_platform = 0.f;
		float bonus_speed = 1.f;

		void ChanceOfBonus(Position2D position_block);
	};

	class Player : public GameObject {
	public:

		Mooving playerDirection = Mooving::Stop;

	};
	
}
