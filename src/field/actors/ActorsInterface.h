#pragma once

#include "../../position/Position.h"

class ActorsInterface
{
	void Move();



private:

	Position position;
	int moveLength;

	void moveUp();
	void moveDown();
	void moveLeft();
	void moveRight();

};

