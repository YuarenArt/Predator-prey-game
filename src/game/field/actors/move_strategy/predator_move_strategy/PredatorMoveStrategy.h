#pragma once
#include "../MoveStrategyInterface.h"

class PredatorMoveStrategy : public MoveStrategyInterface {
public:
    PredatorMoveStrategy();
    Position        moveHard(const Position& currentPosition, const PositionMatrix& positionMatrix) override;
    MoveDestination getBestMove(const Position& currentPosition, const PositionMatrix& positionMatrix, const Position& preyPosition);

};
