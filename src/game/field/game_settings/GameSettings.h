#pragma once

#include "../enums/enums.h"

class GameSettings
{

public:
	GameSettings(const Difficult& difficult, const MyGame::ImageType& typeOfPlayer,
		const int& maxMoves = 10, const int& countRows = 10, const int& countColumns = 10);
	~GameSettings() = default;

	Difficult		  getDifficult()    const;
	MyGame::ImageType getTypeOfPlayer() const;
	int				  getMaxMoves()		const;
	int				  getMovesCounter()	const;
	int				  getCountRows()	const;
	int				  getCountColumns()	const;


private:
	Difficult		  difficult;
	MyGame::ImageType typeOfPlayer;
	int		          maxMoves;
	int               movesCounter;
	int               countRows;
	int               countColumns;
};
