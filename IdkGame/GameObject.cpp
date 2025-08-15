#include "GameObject.h"
#include <cassert>

namespace PinGame {

	sf::RectangleShape GameObject::InitBlock(sf::RectangleShape BlockShape, float BlockRectangle1, float  BlockRectangle2)
	{
		BlockShape.setSize(sf::Vector2f(BlockRectangle1, BlockRectangle2));
		BlockShape.setOrigin(BlockRectangle1 / 2.f, BlockRectangle2 / 2.f);
		BlockShape.setFillColor(sf::Color::White);

		return BlockShape;
	}

	sf::CircleShape GameObject::InitCycle(sf::CircleShape CycleShape, float CycleSize, Position2D CyclePosition)
	{
		CycleShape.setRadius(CycleSize);
		CycleShape.setOrigin(CycleSize, CycleSize);
		CycleShape.setFillColor(sf::Color::White);
		CycleShape.setPosition(CyclePosition.x, CyclePosition.y);

		return CycleShape;
	}

	void Bonuses::ChanceOfBonus(Position2D position_block)
	{
		if (Randomazer(1, 10) == 1) {
			switch (Randomazer(1, 4))
			{
			case 1: {
				current_Bonus.push_back(bonus1);
				current_type_Bonus.push_back(BonusType::fire_ball);
				break;
			}
			case 2: {
				current_Bonus.push_back(bonus2);
				current_type_Bonus.push_back(BonusType::fragile_blocks);
				break;
			}
			case 3: {
				current_Bonus.push_back(bonus3);
				current_type_Bonus.push_back(BonusType::short_and_fast);
				break;
			}
			case 4: {
				current_Bonus.push_back(bonus4);
				current_type_Bonus.push_back(BonusType::long_and_slow);
				break;
			}
			default: return;
			}
			current_Bonus[current_Bonus.size()-1].setPosition(position_block.x - BlockRectangle1 / 2.f, position_block.y);

		}
	}

}