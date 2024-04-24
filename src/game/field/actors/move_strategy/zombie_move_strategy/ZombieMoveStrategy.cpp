#include "ZombieMoveStrategy.h"
#include <QRandomGenerator>

const MyGame::ImageType imageTypeOfZombi = MyGame::ImageType::zombie;
const int moveLengthZombie = 1;
const int maxMoveCounter = 5;
const MoveDirection zombiePossibleMoveDirectionVertical = vertical;
const MoveDirection zombiePossibleMoveDirectionHorizontal = horizontal;

ZombieMoveStrategy::ZombieMoveStrategy() : MoveStrategyInterface(imageTypeOfZombi, moveLengthZombie), 
                                           moveCounter(0), direction(static_cast<MoveDestination>(QRandomGenerator::global()->bounded(4))) {}

Position ZombieMoveStrategy::moveHard(const Position& currentPosition, const PositionMatrix& positionMatrix) {
    if (moveCounter >= maxMoveCounter) {
        moveCounter = 0;
        direction = getOppositeDirection(direction);
    }

    Position newPosition = positionMatrix.positionAfterMove(currentPosition, moveLengthZombie, direction, imageTypeOfZombi);

    if (!positionMatrix.isValidPosition(newPosition) || positionMatrix.isBarrier(newPosition)) {
        direction = getOppositeDirection(direction);
        newPosition = positionMatrix.positionAfterMove(currentPosition, moveLengthZombie, direction, imageTypeOfZombi);
    }

    moveCounter++;
    return newPosition;
}

int ZombieMoveStrategy::getRandomZombieMoveDirection() const {
    QSet<MoveDirection> possibleDirections = { zombiePossibleMoveDirectionVertical, zombiePossibleMoveDirectionHorizontal };
    QVector<MoveDirection> directions(possibleDirections.begin(), possibleDirections.end());
    return directions[QRandomGenerator::global()->bounded(directions.size())];
}

MoveDestination ZombieMoveStrategy::getOppositeDirection(MoveDestination direction) const {
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
