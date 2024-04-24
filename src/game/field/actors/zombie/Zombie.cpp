#include "Zombie.h"

const MyGame::ImageType	imageTypeOfZombie = MyGame::ImageType::zombie;
const int			    moveLengthZombie = 1;
const MoveDirection     zombieMoveDirection = verticallyAndHorizontally;

Zombie::Zombie(const Position& position, const Difficult& difficult, bool isPlayer) :
    ActorsInterface(position, imageTypeOfZombie, zombieMoveDirection, moveLengthZombie, isPlayer, new ZombieMoveStrategy(), difficult)
{
    moveStrategy = static_cast<ZombieMoveStrategy*>(getMoveStrategy());
}
