#pragma once

#include <QVector>
#include <stdexcept>


#include "../field_sprite_vector/field_sprite/FieldSprite.h" // import for ImageType enum
#include "../../position/Position.h"


class PositionMatrix
{
public:
	PositionMatrix(int rows = 10, int columns = 10);

	void changeImageTypeInMatrix(const QVector<Position>& positions, const ImageType& imageType);
	void changeImageTypeInMatrix(const Position& position, const ImageType& imageType);

	bool IsCorrectPosition(Position position);
	QVector<QVector<ImageType>> getPositionMatrix();
	void generateFieldPartsRandomly();

	int getCountRows() const;
	int getCountColumns() const;

private:
	QVector<QVector<ImageType>> positionMatrix;

	void setImageType(const Position& position, const ImageType& imageType);
	bool isGrass(Position position);
	void getRowAndColumn(int& row, int& column, const Position& position);
	void generateObject(ImageType objectType, int count);

};


