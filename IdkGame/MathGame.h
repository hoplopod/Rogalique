#pragma once

#include <cmath>

namespace PinGame {

	struct Vector2D {
		float x = 0;
		float y = 0;
	};

	typedef Vector2D Position2D;

	int isCircleCollide(Position2D rectPosition, Vector2D rectSize, Position2D CircleLPosition, float CircleRadius);

	int isRectangleCollige(Position2D rectPosition1, Vector2D rectSize1, Position2D rectPosition2, Vector2D rectSize2);


	int Randomazer(int start, int end);
}