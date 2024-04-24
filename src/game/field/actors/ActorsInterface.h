#pragma once

#include <QObject>
#include <QMetaObject>

#include "../../../position/Position.h"
#include "../position_matrix/PositionMatrix.h"
#include "../enums/enums.h"
#include "move_strategy/MoveStrategyInterface.h"
#include "move_strategy/predator_move_strategy/PredatorMoveStrategy.h"
#include "move_strategy/prey_move_strategy/PreyMoveStrategy.h"
#include "move_strategy/zombie_move_strategy/ZombieMoveStrategy.h"

class ActorsInterface: public QObject
{

	Q_OBJECT

signals:
	void removeActor(const Position& position, MyGame::ImageType type);

public:

	ActorsInterface(const Position& position, const MyGame::ImageType& imageType,
					const MoveDirection& possibleDirection, const int moveLength, bool isPlayer,
					MoveStrategyInterface* moveStrategy, const Difficult& difficult);

	virtual ~ActorsInterface() = default;

	Position move(const Difficult& difficult, PositionMatrix& positionMatrix);
	Position playerMove(const MoveDestination& direction, PositionMatrix& positionMatrix);

	Position				getPosition() const;
	MyGame::ImageType		getImageType() const;
	int						getMoveLength() const;
	MoveDirection			getPossibleDirection() const;
	MoveStrategyInterface*  getMoveStrategy() const;

	void setPosition(const Position& newPosition);
	void setImageType(const MyGame::ImageType& newImageType);
	void setPossibleDirection(const MoveDirection& newPossibleDirection);
	void setPlayble();

	bool isPlayer() const;
	bool isValidMoveDirection(const MoveDestination& target) const;

protected:

	Position		       position;
	Difficult			   difficult;
	MyGame::ImageType      imageType;
	MoveDirection	       possibleDirection;
	bool                   isPlayer_;
	const int			   moveLength;
	MoveStrategyInterface *moveStrategy;

};

