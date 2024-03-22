#include "ActorsInterface.h"
#include "QDebug"

Position ActorsInterface::move(const MoveDestination& direction)
{
	return Position();
}

Position ActorsInterface::move(const Difficult& difficult, const PositionMatrix& positionMatrix)
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
		qDebug() << "There isn't such difficult";
		break;
	}

	return newPosition;
}

Position ActorsInterface::getPosition() const
{
	return position;
}

ImageType ActorsInterface::getImageType() const
{
	return imageType;
}

int ActorsInterface::getMoveLength() const
{
	return moveLength;
}

void ActorsInterface::setPosition(const Position& newPosition)
{
	position = newPosition;
}

void ActorsInterface::setImageType(const ImageType& newImageType)
{
	imageType = imageType;
}

void ActorsInterface::setPossibleDirection(const MoveDirection& newPossibleDirection)
{
	possibleDirection = newPossibleDirection;
}

bool ActorsInterface::isPlayer() const
{
	return isGamer;
}

bool ActorsInterface::isValidMoveDirection(const MoveDestination& destination) const
{
	QSet<MoveDirection> possibleDirections = getMoveDirectionsByDistination(destination);

	return isValidDestinationByPossibleDirection(possibleDirections, possibleDirection);
}

Position ActorsInterface::moveUp()
{
	return Position();
}

Position ActorsInterface::moveDown()
{
	return Position();
}

Position ActorsInterface::moveLeft()
{
	return Position();
}

Position ActorsInterface::moveRight()
{
	return Position();
}

Position ActorsInterface::moveUpLeft()
{
	return Position();
}

Position ActorsInterface::moveUpRight()
{
	return Position();
}

Position ActorsInterface::moveDownLeft()
{
	return Position();
}

Position ActorsInterface::moveDownRight()
{
	return Position();
}
