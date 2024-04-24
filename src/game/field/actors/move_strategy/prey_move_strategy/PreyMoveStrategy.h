#pragma once
#include "../MoveStrategyInterface.h"

class PreyMoveStrategy : public MoveStrategyInterface {
public:
    PreyMoveStrategy();
    Position        moveHard(const Position& currentPosition, const PositionMatrix& positionMatrix) override;
    MoveDestination getBestMove(const Position& currentPosition, const PositionMatrix& positionMatrix, const Position& predatorPosition);
};
