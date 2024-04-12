#include "Zombie.h"

const MyGame::ImageType imageTypeOfZombi = MyGame::ImageType::zombie;
const int moveLengthZombie = 1;
const MoveDirection zombieMoveDirection = verticallyAndHorizontally;

Zombie::Zombie(const Position& position, bool isPlayer) :
    ActorsInterface(position, imageTypeOfZombi, zombieMoveDirection, moveLengthZombie, isPlayer)
{ }

Position Zombie::autoMoveHard(PositionMatrix& positionMatrix)
{
    // Реализация логики сложного автоматического перемещения зомби
    return Position();
}