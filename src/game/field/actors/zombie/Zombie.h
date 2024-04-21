#pragma once

#include <QObject>
#include "../ActorsInterface.h"

class Zombie final : public ActorsInterface
{
public:
    Zombie(const Position& position, bool isPlayer = false);
    ~Zombie() override = default;

    Position        autoMoveHard(PositionMatrix& positionMatrix) override;
    MoveDirection   getRandomZombieMoveDirection();
    MoveDestination getOppositeDirection(MoveDestination direction) const;
    MoveDestination getRandomDirection() const;

private:
    int             moveCounter;
    MoveDestination direction;
};
