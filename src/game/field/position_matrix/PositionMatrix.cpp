#include "PositionMatrix.h"

#include <QObject>
#include <QDebug>
#include <QSet>

const int countPrey = 1;
const int countPredator = 1;
const int countZombie = 0;

const QSet<ImageType> barrierTerrainSet = { Stone, Forest };
const QSet<ImageType> stoppingSet = { Prey, Predator, Zombie }; // thats type stop if you step on them


PositionMatrix::PositionMatrix(int rows, int columns) 
	: positionMatrix(rows, QVector<ImageType>(columns, ImageType::Grass)) {}

// checks the ability to make at least one move in target direction
bool PositionMatrix::isValidMove(const Position& newPosition)
{
	int currentRow = newPosition.getPosition().getRow();
	int currentColumn = newPosition.getPosition().getColumn();

	int maxRow = getCountRows() - 1;
	int maxColumn = getCountColumns() - 1;

	return isMoveInMatrixBorder(newPosition) && isFreeToMove(newPosition);
}

// checks that move does not go beyond the boundaries of the matrix
bool PositionMatrix::isMoveInMatrixBorder(const Position newPosition)
{
	int newRow = newPosition.getPosition().getRow();
	int newColumn = newPosition.getPosition().getColumn();

	int maxRow = getCountRows() - 1;
	int maxColumn = getCountColumns() - 1;

	return (newRow >= 0 && newRow <= maxRow) && (newColumn >= 0 && newColumn <= maxColumn);
}

// checks that the position is not occupied by the barrierTerrainSet
bool PositionMatrix::isFreeToMove(const Position newPosition)
{
	int newRow = newPosition.getPosition().getRow();
	int newColumn = newPosition.getPosition().getColumn();

	ImageType type = positionMatrix[newRow][newColumn];

	// not in set
	return barrierTerrainSet.find(type) == barrierTerrainSet.end();
}

Position PositionMatrix::positionAfterMove(const Position& currentPosition, const int& moveLength, const MoveDestination& moveTarget)
{
	int currentRow = currentPosition.getPosition().getRow();
	int currentColumn = currentPosition.getPosition().getColumn();

	int newRow = currentRow;
	int newColumn = currentColumn;

	for (int countMove = 0; countMove < moveLength; countMove++) {

		updateRowAndColumnByMoveTarget(newRow, newColumn, moveTarget);
		Position newPosition(newRow, newColumn);

		if (!isValidMove(newPosition)) break;

		currentRow = newRow;
		currentColumn = newColumn;

		if (isStoppingPosition(newPosition)) break;
	}

	return Position(currentRow, currentColumn);
}

// checks that the new position is prey's position
bool PositionMatrix::isPreyPosition(const Position& newPosition)
{
	int row = newPosition.getPosition().getRow();
	int column = newPosition.getPosition().getColumn();
	bool isPreyPosition = positionMatrix[row][column] == Prey;

	return isPreyPosition;
}

// cheks that the new position on of the stoping: prey, predator, zombie
bool PositionMatrix::isStoppingPosition(const Position& newPosition)
{
	int newRow = newPosition.getPosition().getRow();
	int newColumn = newPosition.getPosition().getColumn();

	ImageType type = positionMatrix[newRow][newColumn];

	// not in set
	return stoppingSet.find(type) == stoppingSet.end();
}

void PositionMatrix::changeImagesTypeInMatrix(const QVector<Position>& positions, const ImageType& imageType)
{
	for (auto position : positions) {
		changeImageTypeInMatrix(position, imageType);
	}
}

void PositionMatrix::changeImageTypeInMatrix(const Position& position, const ImageType& imageType)
{
	if (!isMoveInMatrixBorder(position)) {
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

QVector<QVector<ImageType>> PositionMatrix::getPositionMatrix() {
	return positionMatrix;
}

// generates random objects in matrix due to its count
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

void PositionMatrix::updateRowAndColumnByMoveTarget(int& newRow, int& newColumn, const MoveDestination& moveTarget)
{
	switch (moveTarget) {
	case MoveDestination::Up:
		newRow--;
		break;
	case MoveDestination::Down:
		newRow++;
		break;
	case MoveDestination::Left:
		newColumn--;
		break;
	case MoveDestination::Right:
		newColumn++;
		break;
	case MoveDestination::UpLeft:
		newRow--;
		newColumn--;
		break;
	case MoveDestination::UpRight:
		newRow--;
		newColumn++;
		break;
	case MoveDestination::DownLeft:
		newRow++;
		newColumn--;
		break;
	case MoveDestination::DownRight:
		newRow++;
		newColumn++;
		break;
	default:
		break;
	}
}

bool PositionMatrix::isGrass(const Position& position)
{
	int row = position.getPosition().getRow();
	int column = position.getPosition().getColumn();

	return positionMatrix[row][column] == Grass;
}

void PositionMatrix::getRowAndColumn(int& row, int& column, const Position& position) {
	row = position.getPosition().getRow();
	column = position.getPosition().getColumn();
}