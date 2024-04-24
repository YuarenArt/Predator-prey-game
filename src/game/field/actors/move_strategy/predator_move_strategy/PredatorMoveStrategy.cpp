#include "PredatorMoveStrategy.h"
#include <limits>

const MyGame::ImageType imageTypeOfPredator = MyGame::ImageType::predator;
const int moveLengthPredator = 3;
const MoveDirection predatorMoveDirection = verticallyAndHorizontally;

PredatorMoveStrategy::PredatorMoveStrategy() : MoveStrategyInterface(imageTypeOfPredator, moveLengthPredator) {}

MoveDestination PredatorMoveStrategy::getBestMove(const Position& currentPosition, const PositionMatrix& positionMatrix, const Position& preyPosition) {
    int minDistance = INT_MAX;
    MoveDestination bestMove = MoveDestination::Up;

    QSet<MoveDestination> possibleMoves = getMoveDestinationsByDirection(predatorMoveDirection);

    for (const auto& move : possibleMoves) {
        Position newPos = positionMatrix.positionAfterMove(currentPosition, moveLengthPredator, move, imageTypeOfPredator);
        int distance = manhattanDistance(newPos, preyPosition);

        if (distance < minDistance) {
            minDistance = distance;
            bestMove = move;
        }
    }

    return bestMove;
}

Position PredatorMoveStrategy::moveHard(const Position& currentPosition, const PositionMatrix& positionMatrix) {

    Position preyPosition = positionMatrix.findNearestActor(currentPosition, MyGame::prey);
    MoveDestination bestMove = getBestMove(currentPosition, positionMatrix, preyPosition);
    return positionMatrix.positionAfterMove(currentPosition, moveLengthPredator, bestMove, imageTypeOfPredator);

}
