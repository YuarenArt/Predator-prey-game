#include "Prey.h"

const MyGame::ImageType imageTypeOfPrey = MyGame::ImageType::prey;
const int moveLengthPrey = 1;
const MoveDirection preyMoveDirection = all;

Prey::Prey(const Position& position, bool isPlayer) :
    ActorsInterface(position, imageTypeOfPrey, preyMoveDirection, moveLengthPrey, isPlayer)
{ }

Position Prey::autoMoveHard(PositionMatrix& positionMatrix)
{
    // Реализация логики сложного автоматического перемещения жертвы
    return Position();
}
