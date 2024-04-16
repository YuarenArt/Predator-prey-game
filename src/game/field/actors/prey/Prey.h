#pragma once

#include <QObject>

#include "../ActorsInterface.h"

class Prey final : public ActorsInterface
{

public:
    Prey(const Position& position, bool isPlayer = false);
    ~Prey() override = default;

    Position autoMoveHard(PositionMatrix& positionMatrix) override;
    MoveDestination getBestMove(const Position& currentPosition, const PositionMatrix& positionMatrix, const Position& predatorPosition);
};
