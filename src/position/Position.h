#pragma once

#include "point2D/Point2D.h"

class Position
{
public:

	Position(int row = 0, int column = 0);

	Point2D getPosition() const;
	void setPosition(const int raw, const int column);

private:

	Point2D position;
};

