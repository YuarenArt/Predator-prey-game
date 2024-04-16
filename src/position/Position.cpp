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

bool Position::operator== (const Position& rhs) const
{
    return this->position == rhs.position;;
}

bool Position::operator!= (const Position& rhs) const
{
    return !(*this == rhs);
}

Position Position::operator-(const Position& rhs) const
{
    int rowDiff = position.getRow() - rhs.position.getRow();
    int colDiff = position.getColumn() - rhs.position.getColumn();
    return Position(rowDiff, colDiff);
}

void Position::moveUp() {
    position.setRow(position.getRow() - 1);
}

void Position::moveDown() {
    position.setRow(position.getRow() + 1);
}

void Position::moveLeft() {
    position.setColumn(position.getColumn() - 1);
}

void Position::moveRight() {
    position.setColumn(position.getColumn() + 1);
}

void Position::moveUpLeft() {
    position.setRow(position.getRow() - 1);
    position.setColumn(position.getColumn() - 1);
}

void Position::moveUpRight() {
    position.setRow(position.getRow() - 1);
    position.setColumn(position.getColumn() + 1);
}

void Position::moveDownLeft() {
    position.setRow(position.getRow() + 1);
    position.setColumn(position.getColumn() - 1);
}

void Position::moveDownRight() {
    position.setRow(position.getRow() + 1);
    position.setColumn(position.getColumn() + 1);
}