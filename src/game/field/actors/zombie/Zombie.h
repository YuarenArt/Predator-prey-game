#pragma once

#include <QObject>

#include "../ActorsInterface.h"

class Zombie final : public ActorsInterface
{

public:
	Zombie(const Position& position, const Difficult& difficult, bool isPlayer = false);
	~Zombie() override = default;
};
