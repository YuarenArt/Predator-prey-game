#pragma once
#include "../MoveStrategyInterface.h"

class ZombieMoveStrategy : public MoveStrategyInterface {
public:
    ZombieMoveStrategy();
    Position moveHard(const Position& currentPosition, const PositionMatrix& positionMatrix) override;

private:
    int moveCounter;
    MoveDirection   direction;
    MoveDestination destination;

    MoveDirection   getRandomZombieMoveDirection()                    const;
    MoveDestination getOppositeDestination(MoveDestination direction) const;
    MoveDirection   getRandomDirection()                              const;
};

MoveDestination getDestinationByDirection(MoveDirection direction);