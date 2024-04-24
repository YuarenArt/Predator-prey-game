#pragma once

#include <QObject>

#include "../ActorsInterface.h"

class Prey final : public ActorsInterface
{

public:
	Prey(const Position& position, const Difficult& difficult, bool isPlayer = false);
	~Prey() override = default;
};
