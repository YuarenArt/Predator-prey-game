#pragma once

#include <QSet>


enum Difficult {
	standart,
	hard
};

// possible type of value in matrix
enum ImageType
{
	Grass,
	Prey,
	Predator,
	Forest,
	Stone,
	Zombie
};

ImageType& operator++(ImageType& type);
ImageType operator++(ImageType& type, int);

// possible direction to move
enum MoveDirection {
	all,
	vertical,
	horizontal,
	diagonally,
	verticallyAndHorizontally
};

// certain direction when move
enum MoveDestination {
	Up,
	Down,
	Left,
	Right,
	UpLeft,
	UpRight,
	DownLeft,
	DownRight
};

QSet<MoveDestination> getMoveDestinationsByDirection(const MoveDirection& direction);


QSet<MoveDirection> getMoveDirectionsByDistination(const MoveDestination& destination);
bool isValidDestinationByPossibleDirection(const QSet<MoveDirection>& possibleDirections,
										   const MoveDirection        possibleDirection);
