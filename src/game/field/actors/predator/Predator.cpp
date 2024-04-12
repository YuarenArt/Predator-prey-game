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
	
	return Position();
}
