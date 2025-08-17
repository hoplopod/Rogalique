#include "MathGame.h"
#include <cstdlib>
#include <SFML/Graphics.hpp>

namespace PinGame {

	int isCircleCollide(Position2D rectPosition, Vector2D rectSize, Position2D CircleLPosition, float CircleRadius)
	{
		const float squareDistanceX1 = rectPosition.x + rectSize.x / 2.f;
		const float squareDistanceX2 = rectPosition.x - rectSize.x / 2.f;

		const float squareDistanceY1 = rectPosition.y + rectSize.y / 2.f;
		const float squareDistanceY2 = rectPosition.y - rectSize.y / 2.f;

		const float squareRadiusSumX1 = CircleLPosition.x + CircleRadius;
		const float squareRadiusSumX2 = CircleLPosition.x - CircleRadius;

		const float squareRadiusSumY1 = CircleLPosition.y + CircleRadius;
		const float squareRadiusSumY2 = CircleLPosition.y - CircleRadius;

		if (((squareDistanceX1 >= squareRadiusSumX2 && squareDistanceX1 <= squareRadiusSumX1) || (squareDistanceX2 >= squareRadiusSumX2 && squareDistanceX2 <= squareRadiusSumX1)) && 
			((squareDistanceY1 <= squareRadiusSumY1 && squareDistanceY1 >= squareRadiusSumY2) || (squareDistanceY2 <= squareRadiusSumY1 && squareDistanceY2 >= squareRadiusSumY2))) {
			if (abs(rectPosition.x - CircleLPosition.x) / (rectSize.x / rectSize.y) > abs(rectPosition.y - CircleLPosition.y)) {
				return 1;
			}
			else if (abs(rectPosition.x - CircleLPosition.x) / (rectSize.x / rectSize.y) < abs(rectPosition.y - CircleLPosition.y)) {
				return 2;
			}
			else return -1;
		}

		if ((squareDistanceX1 >= squareRadiusSumX1 && squareDistanceX2 <= squareRadiusSumX2) && ((squareDistanceY1 >= squareRadiusSumY1 && squareDistanceY2 <= squareRadiusSumY1) ||
		   (squareDistanceY1 >= squareRadiusSumY2 && squareDistanceY2 <= squareRadiusSumY1))){
			return 2;
		}

		if ((squareDistanceY1 >= squareRadiusSumY1 && squareDistanceY2 <= squareRadiusSumY1) && ((squareDistanceX1 >= squareRadiusSumX2 && squareDistanceX2 <= squareRadiusSumX2) ||
			(squareDistanceX1 >= squareRadiusSumX1 && squareDistanceX2 <= squareRadiusSumX1))) {
			return 1;
		}

		return 0;
	}

	int isRectangleCollige(Position2D rectPosition1, Vector2D rectSize1, Position2D rectPosition2, Vector2D rectSize2)
	{
		const float first_size_left_X = rectPosition1.x - (rectSize1.x / 2.f);
		const float first_size_Right_X = rectPosition1.x + (rectSize1.x / 2.f);
		const float first_size_Up_Y = rectPosition1.y - (rectSize1.y / 2.f);
		const float first_size_Bottom_Y = rectPosition1.y + (rectSize1.y / 2.f);

		const float second_size_left_X = rectPosition2.x - (rectSize2.x / 2.f);
		const float second_size_Right_X = rectPosition2.x + (rectSize2.x / 2.f);
		const float second_size_Up_Y = rectPosition2.y - (rectSize2.y / 2.f);
		const float second_size_Bottom_Y = rectPosition2.y + (rectSize2.y / 2.f);

		if (((first_size_Up_Y <= second_size_Bottom_Y && first_size_Bottom_Y >= second_size_Bottom_Y) || (first_size_Up_Y <= second_size_Up_Y && first_size_Bottom_Y >= second_size_Up_Y)) &&
			((first_size_left_X <= second_size_left_X && first_size_Right_X >= second_size_left_X) || (first_size_left_X <= second_size_Right_X && first_size_Right_X >= second_size_Right_X))) {
			return 1;
		}
		else return 0;
	}

	int Randomazer(int start, int end)
	{
		return rand() % (end - start + 1) + start;
	}

}
