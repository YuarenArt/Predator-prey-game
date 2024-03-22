#pragma once

#include "../../../position/Position.h"
#include "../position_matrix/PositionMatrix.h"
#include "../enums/enums.h"

class ActorsInterface
{
public:

	virtual Position move(const MoveDestination& direction);
	virtual Position move(const Difficult& difficult, const PositionMatrix& positionMatrix);
	virtual Position autoMoveStandart(const PositionMatrix& positionMatrix) = 0;
	virtual Position autoMoveHard(const PositionMatrix& positionMatrix) = 0;

	virtual Position getPosition() const;
	virtual ImageType getImageType() const;
	virtual int getMoveLength() const;

	virtual void setPosition(const Position& newPosition);
	virtual void setImageType(const ImageType& newImageType);
	virtual void setPossibleDirection(const MoveDirection& newPossibleDirection);

	virtual bool isPlayer() const;
	virtual bool isValidMoveDirection(const MoveDestination& target) const;

private:

	Position position;
	ImageType imageType;
	MoveDirection possibleDirection;
	const int moveLength;
	bool isGamer;


	virtual Position moveUp();
	virtual Position moveDown();
	virtual Position moveLeft();
	virtual Position moveRight();
	virtual Position moveUpLeft();
	virtual Position moveUpRight();
	virtual Position moveDownLeft();
	virtual Position moveDownRight();

};

