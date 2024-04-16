#include "ActorsInterface.h"
#include "QDebug"
#include <QRandomGenerator>
#include <QDateTime>

ActorsInterface::ActorsInterface(const Position& position, const MyGame::ImageType& imageType,
								 const MoveDirection& possibleDirection, const int moveLength, bool isPlayer) :
	position(position), imageType(imageType), possibleDirection(possibleDirection), moveLength(moveLength), isPlayer_(isPlayer)
{ }

Position ActorsInterface::move(const Difficult& difficult, PositionMatrix& positionMatrix)
{
	Position newPosition;
	switch (difficult) {
	case standart:
		newPosition = autoMoveStandart(positionMatrix);
		break;
	case hard:
		newPosition = autoMoveHard(positionMatrix);
		break;
	default:
		qDebug() << "There is no such difficult";
		break;
	}

	return newPosition;
}

Position ActorsInterface::autoMoveStandart(PositionMatrix& positionMatrix)
{
	Position currentPosition = getPosition();
	MoveDirection possibleDirection = getPossibleDirections(getImageType());
	QSet<MoveDestination> possibleMoveDestination = getMoveDestinationsByDirection(possibleDirection);
	Position newPosition;

	if (!possibleMoveDestination.isEmpty()) {

		QList<MoveDestination> possibleDirectionsList = possibleMoveDestination.values();

		quint64 seed = QDateTime::currentMSecsSinceEpoch();
		QRandomGenerator generator(seed);
		int randomIndex = generator.bounded(0, possibleMoveDestination.size());
		MoveDestination randomDirection = possibleDirectionsList.at(randomIndex);

		newPosition = positionMatrix.positionAfterMove(currentPosition, moveLength, randomDirection, imageType);

		if (positionMatrix.isZombiePosition(newPosition) && newPosition != currentPosition) {
			emit removeActor(newPosition, MyGame::ImageType::zombie);
			positionMatrix.removeActorFromPosition(newPosition);
		}

	}
	else {
		qDebug() << "Empty possible directions set";
	}

	return newPosition;
}

Position ActorsInterface::getPosition() const
{
	return position;
}

MyGame::ImageType ActorsInterface::getImageType() const
{
	return imageType;
}

int ActorsInterface::getMoveLength() const
{
	return moveLength;
}

MoveDirection ActorsInterface::getPossibleDirection() const
{
	return possibleDirection;
}

void ActorsInterface::setPosition(const Position& newPosition)
{
	position = newPosition;
}

void ActorsInterface::setImageType(const MyGame::ImageType& newImageType)
{
	imageType = newImageType;
}

void ActorsInterface::setPossibleDirection(const MoveDirection& newPossibleDirection)
{
	possibleDirection = newPossibleDirection;
}

void ActorsInterface::setPlayble() 
{
	isPlayer_ = true;
}

bool ActorsInterface::isPlayer() const
{
	return isPlayer_;
}

bool ActorsInterface::isValidMoveDirection(const MoveDestination& destination) const
{
	QSet<MoveDirection> possibleDirections = getMoveDirectionsByDistination(destination);
	for (auto direction : possibleDirections) {
		if (direction == possibleDirection) return true;
	}
	return false;

}

int manhattanDistance(const Position& pos1, const Position& pos2) {

	int dx = pos1.getPosition().getColumn() - pos2.getPosition().getColumn();
	int dy = pos1.getPosition().getRow() - pos2.getPosition().getRow();

	return abs(dx) + abs(dy);
}