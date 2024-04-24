#include "Prey.h"

const MyGame::ImageType	imageTypeOfPrey = MyGame::ImageType::prey;
const int			    moveLengthPrey = 1;
const MoveDirection     preyMoveDirection = all;

Prey::Prey(const Position& position, const Difficult& difficult, bool isPlayer) :
    ActorsInterface(position, imageTypeOfPrey, preyMoveDirection, moveLengthPrey, isPlayer, new PreyMoveStrategy(), difficult)
{
    moveStrategy = static_cast<PreyMoveStrategy*>(getMoveStrategy());
}

