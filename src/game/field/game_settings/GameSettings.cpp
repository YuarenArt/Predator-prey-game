#include "GameSettings.h"

GameSettings::GameSettings(const Difficult& difficult, const MyGame::ImageType& typeOfPlayer, const int& maxMoves,
                            const int& countRows, const int& countColumns) :
    difficult(difficult), typeOfPlayer(typeOfPlayer), maxMoves(maxMoves), movesCounter(0), countRows(countRows), countColumns(countColumns)
{ }

Difficult GameSettings::getDifficult() const
{
    return difficult;
}

MyGame::ImageType GameSettings::getTypeOfPlayer() const
{
    return typeOfPlayer;
}

int GameSettings::getMaxMoves() const
{
    return maxMoves;
}

int GameSettings::getMovesCounter() const
{
    return movesCounter;
}

int GameSettings::getCountRows() const
{
    return countRows;
}

int GameSettings::getCountColumns() const
{
    return countColumns;
}
