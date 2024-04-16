#include "Prey.h"

const MyGame::ImageType imageTypeOfPrey = MyGame::ImageType::prey;
const int moveLengthPrey = 1;
const MoveDirection preyMoveDirection = all;

Prey::Prey(const Position& position, bool isPlayer) :
    ActorsInterface(position, imageTypeOfPrey, preyMoveDirection, moveLengthPrey, isPlayer)
{ }

Position Prey::autoMoveHard(PositionMatrix& positionMatrix)
{
    Position predatorPosition = positionMatrix.findNearestActor(getPosition(), MyGame::predator);
    Position preyPosition = getPosition();

    MoveDestination bestMove = getBestMove(preyPosition, positionMatrix, predatorPosition);
    Position newPreyPosition = positionMatrix.positionAfterMove(preyPosition, getMoveLength(), bestMove, getImageType());

    return newPreyPosition;
}

MoveDestination Prey::getBestMove(const Position& currentPosition, const PositionMatrix& positionMatrix, const Position& predatorPosition)
{
    int maxDistance = INT_MIN;
    MoveDestination bestMove = MoveDestination::Up;

    QSet<MoveDestination> possibleMoves = getMoveDestinationsByDirection(getPossibleDirection());

    for (const auto& move : possibleMoves) {
        Position newPos = positionMatrix.positionAfterMove(currentPosition, getMoveLength(), move, getImageType());
        int distance = manhattanDistance(newPos, predatorPosition);

        if (distance > maxDistance) {
            maxDistance = distance;
            bestMove = move;
        }
    }

    return bestMove;
}
