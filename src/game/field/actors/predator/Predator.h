#pragma once

#include <QObject>

#include "../ActorsInterface.h"

class Predator final : public ActorsInterface
{

public:
	Predator(const Position& position, const Difficult& difficult, bool isPlayer = false);
	~Predator() override = default;
};
