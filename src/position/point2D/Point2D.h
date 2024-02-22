#pragma once

class Point2D
{
public:

	Point2D(int row = 0, int column = 0);

	void setPoint(int row, int column);
	int getX() const;               
	int getY() const;

private:

	int row;
	int column;
};

