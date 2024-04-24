#pragma once
#include "../../../../position/Position.h"
#include "../../position_matrix/PositionMatrix.h"

class MoveStrategyInterface {
public:
    MoveStrategyInterface(MyGame::ImageType imageType, int moveLength);
    virtual ~MoveStrategyInterface() = default;

    virtual Position move        (const Position& currentPosition, const PositionMatrix& positionMatrix, const Difficult difficult);
    virtual Position moveHard    (const Position& currentPosition, const PositionMatrix& positionMatrix) = 0;
    virtual Position moveStandart(const Position& currentPosition, const PositionMatrix& positionMatrix);

private:
    MyGame::ImageType imageType;
    int               moveLength;
};

int manhattanDistance(const Position& pos1, const Position& pos2);