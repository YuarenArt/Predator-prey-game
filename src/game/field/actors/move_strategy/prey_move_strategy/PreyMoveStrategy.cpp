#include "PreyMoveStrategy.h"
#include <limits>

const MyGame::ImageType imageTypeOfPrey = MyGame::ImageType::prey;
const int moveLengthPrey = 1;
const MoveDirection preyMoveDirection = all;

PreyMoveStrategy::PreyMoveStrategy() : MoveStrategyInterface(imageTypeOfPrey, moveLengthPrey) {}

MoveDestination PreyMoveStrategy::getBestMove(const Position& currentPosition, const PositionMatrix& positionMatrix, const Position& predatorPosition) {
    int maxDistance = INT_MIN;
    MoveDestination bestMove = MoveDestination::Up;

    QSet<MoveDestination> possibleMoves = getMoveDestinationsByDirection(preyMoveDirection);

    for (const auto& move : possibleMoves) {
        Position newPos = positionMatrix.positionAfterMove(currentPosition, moveLengthPrey, move, imageTypeOfPrey);
        int distance = manhattanDistance(newPos, predatorPosition);

        if (distance > maxDistance) {
            maxDistance = distance;
            bestMove = move;
        }
    }

    return bestMove;
}

Position PreyMoveStrategy::moveHard(const Position& currentPosition, const PositionMatrix& positionMatrix) {

    Position predatorPosition = positionMatrix.findNearestActor(currentPosition, MyGame::predator);
    MoveDestination bestMove = getBestMove(currentPosition, positionMatrix, predatorPosition);
    return positionMatrix.positionAfterMove(currentPosition, moveLengthPrey, bestMove, imageTypeOfPrey);

}
