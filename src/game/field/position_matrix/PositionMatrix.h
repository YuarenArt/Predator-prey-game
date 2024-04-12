#pragma once

#include <QVector>
#include <stdexcept>

#include "../enums/enums.h" 
#include "../../../position/Position.h"

//TODO изюавиться от множества методов для определения позици актора и сделать один метод

class PositionMatrix
{
public:
	PositionMatrix(int rows = 10, int columns = 10);

	bool isValidMove(const Position& newPosition) const;
	bool isValidPosition(const Position& position) const;

	bool isPreyPosition(const Position& newPosition) const;
	bool isZombiePosition(const Position& newPosition) const;
	bool isStoppingPosition(const Position& newPosition, const MyGame::ImageType currentImageType) const;

	void changeImagesTypeInMatrix(const QVector<Position>& positions, const MyGame::ImageType& imageType);
	void changeImageTypeInMatrix(const Position& position, const MyGame::ImageType& imageType);
	void generateFieldPartsRandomly();
	void removeActorFromPosition(const Position& position);

	QVector<QVector<MyGame::ImageType>> getPositionMatrix();
	Position positionAfterMove(const Position& currentPosition, const int& moveLength,
							   const MoveDestination& moveTarget, const MyGame::ImageType currentImageType) const;

	int getCountRows() const;
	int getCountColumns() const;

	QVector<QPair<Position, MyGame::ImageType>> getActorsPositions() const;

private:
	QVector<QVector<MyGame::ImageType>> positionMatrix;

	bool isGrass(const Position& position) const;
	bool isMoveInMatrixBorder(const Position newPosition) const;
	bool isFreeToMove(const Position newPosition) const;

	void setImageType(const Position& position, const MyGame::ImageType& imageType);
	void getRowAndColumn(int& row, int& column, const Position& position);
	void generateObject(MyGame::ImageType objectType, int count);
	void updateRowAndColumnByMoveTarget(int& newRow, int& newColumn, const MoveDestination& moveTarget) const;


};


