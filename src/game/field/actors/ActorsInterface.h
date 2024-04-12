#pragma once

#include <QObject>
#include <QMetaObject>

#include "../../../position/Position.h"
#include "../position_matrix/PositionMatrix.h"
#include "../enums/enums.h"

class ActorsInterface: public QObject
{

	Q_OBJECT

signals:
	void removeActor(const Position& position, MyGame::ImageType type);

public:

	ActorsInterface(const Position& position, const MyGame::ImageType& imageType,
					const MoveDirection& possibleDirection, const int moveLength, bool isPlayer);
	virtual ~ActorsInterface() = default;


	virtual Position move(const Difficult& difficult, PositionMatrix& positionMatrix);
	virtual Position autoMoveStandart(PositionMatrix& positionMatrix);
	virtual Position autoMoveHard(PositionMatrix& positionMatrix) = 0;

	virtual Position          getPosition() const;
	virtual MyGame::ImageType getImageType() const;
	virtual int				  getMoveLength() const;

	virtual void setPosition(const Position& newPosition);
	virtual void setImageType(const MyGame::ImageType& newImageType);
	virtual void setPossibleDirection(const MoveDirection& newPossibleDirection);
	virtual void setPlayble();

	virtual bool isPlayer() const;
	virtual bool isValidMoveDirection(const MoveDestination& target) const;

private:

	Position		  position;
	MyGame::ImageType imageType;
	MoveDirection	  possibleDirection;
	bool              isPlayer_;
	const int		  moveLength;

};

