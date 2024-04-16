#include "Predator.h"
#include <QRandomGenerator>

const MyGame::ImageType	imageTypeOfPredator = MyGame::ImageType::predator;
const int			    moveLengthPredator = 3;
const MoveDirection     predatorMoveDirection = verticallyAndHorizontally;

Predator::Predator(const Position& position, bool isPlayer) :
	ActorsInterface(position, imageTypeOfPredator, predatorMoveDirection, moveLengthPredator, isPlayer)
{ }

Position Predator::autoMoveHard(PositionMatrix& positionMatrix)
{
    Position preyPosition = positionMatrix.findNearestActor(getPosition(), MyGame::prey);
    Position predatorPostion = getPosition();

    MoveDestination bestMove = getBestMove(predatorPostion, positionMatrix, preyPosition);
    Position newPredatorPosition = positionMatrix.positionAfterMove(predatorPostion, getMoveLength(), bestMove, getImageType());
    
    return newPredatorPosition;
}

MoveDestination Predator::getBestMove(const Position& currentPosition, const PositionMatrix& positionMatrix, const Position& preyPosition)
{
    int minDistance = INT_MAX;
    MoveDestination bestMove = MoveDestination::Up;

    QSet<MoveDestination> possibleMoves = getMoveDestinationsByDirection(getPossibleDirection());

    for (const auto& move : possibleMoves) {
        Position newPos = positionMatrix.positionAfterMove(currentPosition, getMoveLength(), move, getImageType());
        int distance = manhattanDistance(newPos, preyPosition);

        if (distance < minDistance) {
            minDistance = distance;
            bestMove = move;
        }
    }

    return bestMove;
}

