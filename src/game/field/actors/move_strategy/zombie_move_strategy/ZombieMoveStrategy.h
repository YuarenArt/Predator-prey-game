#pragma once
#include "../MoveStrategyInterface.h"

class ZombieMoveStrategy : public MoveStrategyInterface {
public:
    ZombieMoveStrategy();
    Position moveHard(const Position& currentPosition, const PositionMatrix& positionMatrix) override;

private:
    int moveCounter;
    MoveDestination direction;

    int             getRandomZombieMoveDirection()                  const;
    MoveDestination getOppositeDirection(MoveDestination direction) const;
    MoveDirection   getRandomDirection()                            const;
};
