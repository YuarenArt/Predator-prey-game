#include "Point2D.h"

Point2D::Point2D(int row, int column) : row(row), column(column) {}

void Point2D::setPoint(int row, int column)
{
    this->row = row;
    this->column = column;
}

int Point2D::getRow() const
{
    return row;
}

int Point2D::getColumn() const
{
    return column;
}

