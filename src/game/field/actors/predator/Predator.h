#pragma once

#include <QObject>

#include "../ActorsInterface.h"

class Predator final : public ActorsInterface
{

public:
	Predator(const Position& position, bool isPlayer = false);
	~Predator() override = default;

	Position autoMoveHard (PositionMatrix& positionMatrix) override;
	MoveDestination getBestMove(const Position& currentPosition, const PositionMatrix& positionMatrix, const Position& preyPosition);
};
