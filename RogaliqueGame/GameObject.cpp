#include "GameObject.h"
#include <cassert>

namespace Rogalique {

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

}