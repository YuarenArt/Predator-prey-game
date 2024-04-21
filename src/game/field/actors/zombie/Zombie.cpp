#include "Zombie.h"

#include <QRandomGenerator>

const MyGame::ImageType imageTypeOfZombi = MyGame::ImageType::zombie;
const int moveLengthZombie = 1;
const int maxMoveCounter = 5;
const MoveDirection zombiePossibleMoveDirectionVertical = vertical;
const MoveDirection zombiePossibleMoveDirectionHorizontal = horizontal;

Zombie::Zombie(const Position& position, bool isPlayer) :
    ActorsInterface(position, imageTypeOfZombi, getRandomZombieMoveDirection(), moveLengthZombie, isPlayer),
    moveCounter(0), direction(getRandomDirection())
{ }

Position Zombie::autoMoveHard(PositionMatrix& positionMatrix)
{
    if (moveCounter >= maxMoveCounter) {
        moveCounter = 0;
        direction = getOppositeDirection(direction);
    }

    Position newPosition = positionMatrix.positionAfterMove(getPosition(), moveLengthZombie, direction, imageTypeOfZombi);

    if (!positionMatrix.isValidPosition(newPosition) || positionMatrix.isBarrier(newPosition)) {
        direction = getOppositeDirection(direction);
        newPosition = positionMatrix.positionAfterMove(getPosition(), moveLengthZombie, direction, imageTypeOfZombi);
    }

    moveCounter++;
    return newPosition;
}

MoveDirection Zombie::getRandomZombieMoveDirection()
{
    QSet<MoveDirection> possibleDirections = { zombiePossibleMoveDirectionVertical, zombiePossibleMoveDirectionHorizontal };
    QVector<MoveDirection> directions(possibleDirections.begin(), possibleDirections.end());
    return directions[QRandomGenerator::global()->bounded(directions.size())];
}

MoveDestination Zombie::getOppositeDirection(MoveDestination direction) const
{
    switch (direction) {
    case MoveDestination::Up:
        return MoveDestination::Down;
    case MoveDestination::Down:
        return MoveDestination::Up;
    case MoveDestination::Left:
        return MoveDestination::Right;
    case MoveDestination::Right:
        return MoveDestination::Left;
    default:
        return MoveDestination::Up;
    }
}

MoveDestination Zombie::getRandomDirection() const
{
    QSet<MoveDestination> possibleDirections = getMoveDestinationsByDirection(getPossibleDirection());
    QVector<MoveDestination> directions(possibleDirections.begin(), possibleDirections.end());
    return directions[QRandomGenerator::global()->bounded(directions.size())];
}