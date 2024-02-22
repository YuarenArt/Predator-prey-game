#include "Position.h"

Position::Position(int row, int column)
{
    this->position = Point2D(row, column);
}


Point2D Position::getPosition() const
{
    return position;
}


void Position::setPosition(const int row, const int column)
{
    position.setPoint(row, column);
}
