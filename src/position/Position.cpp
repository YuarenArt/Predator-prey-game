#include "Position.h"

#include <QRandomGenerator>

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

Position Position::generateRandomPosition(int maxRow, int maxColumn)
{
    int randomRow = QRandomGenerator::global()->bounded(maxRow);
    int randomColumn = QRandomGenerator::global()->bounded(maxColumn);
    return Position(randomRow, randomColumn);
}
