#pragma once

#include <QObject>
#include "../ActorsInterface.h"

class Zombie final : public ActorsInterface
{
public:
    Zombie(const Position& position, bool isPlayer = false);
    ~Zombie() override = default;

    Position autoMoveHard(PositionMatrix& positionMatrix) override;
};
