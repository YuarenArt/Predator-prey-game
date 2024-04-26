#include "ActorsInterface.h"
#include "QDebug"
#include <QRandomGenerator>
#include <QDateTime>

ActorsInterface::ActorsInterface(const Position& position, const MyGame::ImageType& imageType,
								 const MoveDirection& possibleDirection, const int moveLength, bool isPlayer,
								 MoveStrategyInterface* moveStrategy, const Difficult& difficult) :

	position(position), imageType(imageType), possibleDirection(possibleDirection),
	moveLength(moveLength), isPlayer_(isPlayer), moveStrategy(moveStrategy), difficult(difficult) { }

Position ActorsInterface::move(const Difficult& difficult, PositionMatrix& positionMatrix)
{
	Position currentPosition = getPosition();
	Position newPosition;
	switch (difficult) {
	case standart:
		newPosition = moveStrategy->moveStandart(currentPosition, positionMatrix);

		if (positionMatrix.isActorPosition(newPosition, MyGame::zombie) && newPosition != getPosition() && imageType != MyGame::prey) {
			emit removeActor(newPosition, MyGame::ImageType::zombie);
			positionMatrix.removeActorFromPosition(newPosition);
		}
		break;
	case hard:
		newPosition = moveStrategy->moveHard(currentPosition, positionMatrix);
		break;
	default:
		qDebug() << "There is no such difficult";
		break;
	}

	return newPosition;
}

Position ActorsInterface::playerMove(const MoveDestination& direction, PositionMatrix& positionMatrix)
{
	return positionMatrix.positionAfterMove(position, moveLength, direction, imageType);
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

MoveStrategyInterface* ActorsInterface::getMoveStrategy() const
{
	return moveStrategy;
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