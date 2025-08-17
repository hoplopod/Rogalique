#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <vector>
#include <cassert>

#include "Constants.h"
#include "MathGame.h"


namespace Rogalique {

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

	enum class MenuSelection {
		Nothing = 0,
		Play,
		Load,
		Save,
		Score,
		Exit
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

	class Player : public GameObject {

	};
	
}
