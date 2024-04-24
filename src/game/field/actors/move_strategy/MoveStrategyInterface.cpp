#include "MoveStrategyInterface.h"

#include <QRandomGenerator>
#include <QDateTime>

MoveStrategyInterface::MoveStrategyInterface(MyGame::ImageType imageType, int moveLength) : imageType(imageType), moveLength(moveLength) 
{}

Position MoveStrategyInterface::move(const Position& currentPosition, const PositionMatrix& positionMatrix, const Difficult difficult)
{
    Position newPosition;
    switch (difficult) {
    case standart:
        newPosition = moveStandart(currentPosition, positionMatrix);
        break;
    case hard:
        newPosition = moveHard(currentPosition, positionMatrix);
        break;
    default:
        qDebug() << "There is no such difficult";
        break;
    }

    return newPosition;
}

Position MoveStrategyInterface::moveStandart(const Position& currentPosition, const PositionMatrix& positionMatrix)
{
	MoveDirection possibleDirection = getPossibleDirections(imageType);
	QSet<MoveDestination> possibleMoveDestination = getMoveDestinationsByDirection(possibleDirection);
	Position newPosition;

	if (!possibleMoveDestination.isEmpty()) {

		QList<MoveDestination> possibleDirectionsList = possibleMoveDestination.values();

		quint64 seed = QDateTime::currentMSecsSinceEpoch();
		QRandomGenerator generator(seed);
		int randomIndex = generator.bounded(0, possibleMoveDestination.size());
		MoveDestination randomDirection = possibleDirectionsList.at(randomIndex);

		newPosition = positionMatrix.positionAfterMove(currentPosition, moveLength, randomDirection, imageType);
	}
	else {
		qDebug() << "Empty possible directions set";
	}

	return newPosition;
}

int manhattanDistance(const Position& pos1, const Position& pos2) {

	int dx = pos1.getPosition().getColumn() - pos2.getPosition().getColumn();
	int dy = pos1.getPosition().getRow() - pos2.getPosition().getRow();

	return abs(dx) + abs(dy);
}