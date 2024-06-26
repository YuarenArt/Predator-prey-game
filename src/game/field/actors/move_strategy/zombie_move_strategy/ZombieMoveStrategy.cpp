#include "ZombieMoveStrategy.h"
#include <QRandomGenerator>

const MyGame::ImageType imageTypeOfZombi = MyGame::ImageType::zombie;
const int moveLengthZombie = 1;
const int maxMoveCounter = 3;
const MoveDirection zombiePossibleMoveDirectionVertical = vertical;
const MoveDirection zombiePossibleMoveDirectionHorizontal = horizontal;

ZombieMoveStrategy::ZombieMoveStrategy() : MoveStrategyInterface(imageTypeOfZombi, moveLengthZombie),
moveCounter(0)
{
    direction = static_cast<MoveDirection>(getRandomZombieMoveDirection());
    destination = getDestinationByDirection(direction);

}

Position ZombieMoveStrategy::moveHard(const Position& currentPosition, const PositionMatrix& positionMatrix) {
    if (moveCounter >= maxMoveCounter) {
        moveCounter = 0;
        direction = getRandomZombieMoveDirection();
        destination = getDestinationByDirection(direction);
    }

    Position newPosition = positionMatrix.positionAfterMove(currentPosition, moveLengthZombie, destination, imageTypeOfZombi);

    if (!positionMatrix.isValidPosition(newPosition) || positionMatrix.isBarrier(newPosition)) {
        destination = getOppositeDestination(destination);
        newPosition = positionMatrix.positionAfterMove(currentPosition, moveLengthZombie, destination, imageTypeOfZombi);
    }

    moveCounter++;
    return newPosition;
}

MoveDirection ZombieMoveStrategy::getRandomZombieMoveDirection() const {
    QSet<MoveDirection> possibleDirections = { zombiePossibleMoveDirectionVertical, zombiePossibleMoveDirectionHorizontal };
    QVector<MoveDirection> directions(possibleDirections.begin(), possibleDirections.end());
    MoveDirection direction = directions[QRandomGenerator::global()->bounded(directions.size())];
    return direction;
}

MoveDestination ZombieMoveStrategy::getOppositeDestination(MoveDestination direction) const {
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

MoveDirection ZombieMoveStrategy::getRandomDirection() const {
    QSet<MoveDirection> possibleDirections = { vertical , horizontal };
    QVector<MoveDirection> directionsVector(possibleDirections.begin(), possibleDirections.end());
    return directionsVector[QRandomGenerator::global()->bounded(directionsVector.size())];
}

MoveDestination getDestinationByDirection(MoveDirection direction) {
    QSet<MoveDestination> destinations = getMoveDestinationsByDirection(direction);
    QVector<MoveDestination> destinationsVector(destinations.begin(), destinations.end());
    return destinationsVector[QRandomGenerator::global()->bounded(destinationsVector.size())];
}
