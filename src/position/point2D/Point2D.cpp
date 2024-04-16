#include "Point2D.h"

Point2D::Point2D(int row, int column) : row(row), column(column) {}

void Point2D::setPoint(int row, int column)
{
    this->row = row;
    this->column = column;
}

void Point2D::setRow(int row) {
    this->row = row;
}

void Point2D::setColumn(int column) {
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

bool Point2D::operator==(const Point2D& rhs) const {
    return (row == rhs.row && column == rhs.column);
}