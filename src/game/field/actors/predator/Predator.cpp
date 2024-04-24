#include "Predator.h"
#include <QRandomGenerator>

const MyGame::ImageType	imageTypeOfPredator = MyGame::ImageType::predator;
const int			    moveLengthPredator = 3;
const MoveDirection     predatorMoveDirection = verticallyAndHorizontally;

Predator::Predator(const Position& position, const Difficult& difficult, bool isPlayer) :
    ActorsInterface(position, imageTypeOfPredator, predatorMoveDirection, moveLengthPredator, isPlayer, new PredatorMoveStrategy(), difficult)
{
    moveStrategy = static_cast<PredatorMoveStrategy*>(getMoveStrategy());
}




