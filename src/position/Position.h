#pragma once

#include "point2D/Point2D.h"

class Position
{
public:

	Position(int row = 0, int column = 0);

	Point2D getPosition() const;
	void setPosition(int row, int column);

	static Position generateRandomPosition(int maxRow, int maxColumn);

	bool operator== (const Position& rhs) const;
	bool operator!= (const Position& rhs) const;
	Position operator-(const Position& rhs) const;

	void moveUp();
	void moveDown();
	void moveLeft();
	void moveRight();
	void moveUpLeft();
	void moveUpRight();
	void moveDownLeft();
	void moveDownRight();

private:

	Point2D position;
};

