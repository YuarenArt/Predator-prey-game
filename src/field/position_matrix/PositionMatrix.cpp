#include "PositionMatrix.h"

const int countPrey = 1;
const int countPredator = 1;
const int countZombie = 0;

PositionMatrix::PositionMatrix(int rows, int columns) 
	: positionMatrix(rows, QVector<ImageType>(columns, ImageType::Grass)) {}

void PositionMatrix::changeImageTypeInMatrix(const QVector<Position>& positions, const ImageType& imageType)
{
	for (auto position : positions) {
		changeImageTypeInMatrix(position, imageType);
	}
}

void PositionMatrix::changeImageTypeInMatrix(const Position& position, const ImageType& imageType)
{
	if (!IsCorrectPosition(position)) {
		qDebug() << "Position is out of range.";
		return ;
	}

	setImageType(position, imageType);
}

void PositionMatrix::setImageType(const Position& position, const ImageType& imageType)
{
	int row = position.getPosition().getRow();
	int column = position.getPosition().getColumn();

	try {
		positionMatrix[row][column] = imageType;
	}
	catch (const std::out_of_range& e) {
		qDebug() << "An exception occurred: " << e.what();
	}
}

int PositionMatrix::getCountRows() const 
{
	return positionMatrix.size();
}

int PositionMatrix::getCountColumns() const 
{
	if (positionMatrix.empty()) {
		return 0;
	}
	return positionMatrix[0].size();
}

bool PositionMatrix::IsCorrectPosition(Position position) 
{
	int row, column = 0;
	getRowAndColumn(row, column, position);

	if (row >= getCountRows() || row < 0) {
		return false;
	}

	if (column >= getCountColumns() || column < 0) {
		return false;
	}

	return true;
}

QVector<QVector<ImageType>> PositionMatrix::getPositionMatrix() {
	return positionMatrix;
}

void PositionMatrix::generateFieldPartsRandomly()
{
	int sizeOfField = getCountRows() * getCountColumns();
	int countForest = sizeOfField * 0.4;
	int countStone = sizeOfField * 0.1;

	QVector<int> countOfImageTypes = { countPrey, countPredator, countForest, countStone, countZombie };

	std::map<ImageType, int> typeForGenerate;
	ImageType type = Prey;

	for (auto countOfImageType : countOfImageTypes) {
		typeForGenerate.emplace(type++, countOfImageType);
	}

	for (auto& [key, value] : typeForGenerate) {
		generateObject(key, value);
	}
}

void PositionMatrix::generateObject(ImageType objectType, int count)
{
	int maxRow = getCountRows();
	int maxColumn = getCountColumns();

	int generatedCount = 0;

	while (generatedCount < count)
	{
		Position randomPosition = Position::generateRandomPosition(maxRow, maxColumn);

		if (isGrass(randomPosition)) {
			changeImageTypeInMatrix(randomPosition, objectType);
			generatedCount++;
		}
	}
}

bool PositionMatrix::isGrass(Position position)
{
	int row, column = 0;
	getRowAndColumn(row, column, position);

	return  positionMatrix[row][column] == Grass;
}

void PositionMatrix::getRowAndColumn(int& row, int& column, const Position& position) {
	row = position.getPosition().getRow();
	column = position.getPosition().getColumn();
}