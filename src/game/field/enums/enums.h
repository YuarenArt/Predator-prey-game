#pragma once

#include <QSet>

enum Difficult {
	standart,
	hard
};

namespace MyGame {

	// possible type of value in matrix
	enum ImageType
	{
		grass,
		prey,
		predator,
		forest,
		stone,
		zombie
	};

	ImageType& operator++(ImageType& type);
	ImageType operator++(ImageType& type, int);
	QSet<MyGame::ImageType> getImageTypeSet();
}


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

bool isValidDestinationByPossibleDirection(const QSet<MoveDirection>& possibleDirections,
										   const MoveDirection        possibleDirection);

MoveDirection getPossibleDirections(MyGame::ImageType imageType);

QSet<MoveDirection> getMoveDirectionsByDistination(const MoveDestination& destination);