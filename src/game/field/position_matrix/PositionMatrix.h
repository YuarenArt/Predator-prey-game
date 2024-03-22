#pragma once

#include <QVector>
#include <stdexcept>

#include "../enums/enums.h" 
#include "../../../position/Position.h"

class PositionMatrix
{
public:
	PositionMatrix(int rows = 10, int columns = 10);

	bool isValidMove(const Position& newPosition);
	bool isPreyPosition(const Position& newPosition);
	bool isStoppingPosition(const Position& newPosition);

	void changeImagesTypeInMatrix(const QVector<Position>& positions, const ImageType& imageType);
	void changeImageTypeInMatrix(const Position& position, const ImageType& imageType);
	void generateFieldPartsRandomly();

	QVector<QVector<ImageType>> getPositionMatrix();
	Position positionAfterMove(const Position& currentPosition, const int& moveLength, const MoveDestination& moveTarget);

	int getCountRows() const;
	int getCountColumns() const;

private:
	QVector<QVector<ImageType>> positionMatrix;

	bool isGrass(const Position& position);
	bool isMoveInMatrixBorder(const Position newPosition);
	bool isFreeToMove(const Position newPosition);

	void setImageType(const Position& position, const ImageType& imageType);
	void getRowAndColumn(int& row, int& column, const Position& position);
	void generateObject(ImageType objectType, int count);
	void updateRowAndColumnByMoveTarget(int& newRow, int& newColumn, const MoveDestination& moveTarget);

};


