#pragma once

class Point2D
{
public:

	Point2D(int row = 0, int column = 0);

	void setPoint(int row, int column);
	void setRow(int row);
	void setColumn(int column);

	int  getRow() const;               
	int  getColumn() const;

	bool operator==(const Point2D& rhs) const;

private:

	int row;
	int column;
};

