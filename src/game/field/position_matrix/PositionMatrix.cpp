#include "PositionMatrix.h"

#include <QObject>
#include <QDebug>
#include <QSet>

//TODO: refactor positionAfterMove and updateRowAndColumn due to const 

const int countPrey = 1;
const int countPredator = 1;
const int countZombie = 3;

const QSet<MyGame::ImageType> barrierTerrainSet = { MyGame::stone, MyGame::forest };
const QSet<MyGame::ImageType> stoppingSet = { MyGame::prey, MyGame::predator,MyGame::zombie }; // thats type stop if you step on them


PositionMatrix::PositionMatrix(int rows, int columns)
	: positionMatrix(rows, QVector<MyGame::ImageType>(columns, MyGame::ImageType::grass)) {}

// checks the ability to make at least one move in target direction
bool PositionMatrix::isValidMove(const Position& newPosition) const
{
	int currentRow = newPosition.getPosition().getRow();
	int currentColumn = newPosition.getPosition().getColumn();

	int maxRow = getCountRows() - 1;
	int maxColumn = getCountColumns() - 1;

	return isMoveInMatrixBorder(newPosition) && isFreeToMove(newPosition);
}

bool PositionMatrix::isValidPosition(const Position& position) const
{
	int row = position.getPosition().getRow();
	int column = position.getPosition().getColumn();
	return (row >= 0 && row < getCountRows() && column >= 0 && column < getCountColumns());
}

bool PositionMatrix::isBarrier(const Position& position) const
{
	int row = position.getPosition().getRow();
	int column = position.getPosition().getColumn();

	MyGame::ImageType type = positionMatrix[row][column];
	return barrierTerrainSet.find(type) != barrierTerrainSet.end();
}


// checks that move does not go beyond the boundaries of the matrix
bool PositionMatrix::isMoveInMatrixBorder(const Position newPosition) const
{
	int newRow = newPosition.getPosition().getRow();
	int newColumn = newPosition.getPosition().getColumn();

	int maxRow = getCountRows() - 1;
	int maxColumn = getCountColumns() - 1;

	return (newRow >= 0 && newRow <= maxRow) && (newColumn >= 0 && newColumn <= maxColumn);
}

// checks that the position is not occupied by the barrierTerrainSet
bool PositionMatrix::isFreeToMove(const Position newPosition) const
{
	int newRow = newPosition.getPosition().getRow();
	int newColumn = newPosition.getPosition().getColumn();

	MyGame::ImageType type = positionMatrix[newRow][newColumn];

	// not in set
	return barrierTerrainSet.find(type) == barrierTerrainSet.end();
}

Position PositionMatrix::positionAfterMove(const Position& currentPosition, const int& moveLength,
	const MoveDestination& moveTarget, const MyGame::ImageType currentImageType) const
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

		if (isStoppingPosition(newPosition, currentImageType))
		{
			break;
		}

	}

	return Position(currentRow, currentColumn);
}

// checks that the new position is prey's position
bool PositionMatrix::isPreyPosition(const Position& newPosition) const
{
	int row = newPosition.getPosition().getRow();
	int column = newPosition.getPosition().getColumn();
	bool isPreyPosition = positionMatrix[row][column] == MyGame::prey;

	return isPreyPosition;
}

bool PositionMatrix::isZombiePosition(const Position& newPosition) const
{
	int row = newPosition.getPosition().getRow();
	int column = newPosition.getPosition().getColumn();
	bool isZombiePosition = positionMatrix[row][column] == MyGame::zombie;

	return isZombiePosition;
}

bool PositionMatrix::isActorPosition(const Position& newPosition, const MyGame::ImageType imageType) const
{
	int row = newPosition.getPosition().getRow();
	int column = newPosition.getPosition().getColumn();

	bool isZombiePosition = positionMatrix[row][column] == imageType;

	return isZombiePosition;
}

// cheks that the new position on of the stoping: prey, predator, zombie
bool PositionMatrix::isStoppingPosition(const Position& newPosition, const MyGame::ImageType currentImageType) const
{
	int newRow = newPosition.getPosition().getRow();
	int newColumn = newPosition.getPosition().getColumn();

	MyGame::ImageType type = positionMatrix[newRow][newColumn];

	// not in set
	return stoppingSet.find(type) != stoppingSet.end();
}

void PositionMatrix::changeImagesTypeInMatrix(const QVector<Position>& positions, const MyGame::ImageType& imageType)
{
	for (auto position : positions) {
		changeImageTypeInMatrix(position, imageType);
	}
}

void PositionMatrix::changeImageTypeInMatrix(const Position& position, const MyGame::ImageType& imageType)
{
	if (!isMoveInMatrixBorder(position)) {
		qDebug() << "Position is out of range.";
		return;
	}

	setImageType(position, imageType);
}

void PositionMatrix::setImageType(const Position& position, const MyGame::ImageType& imageType)
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

QVector<QVector<MyGame::ImageType>> PositionMatrix::getPositionMatrix() {
	return positionMatrix;
}

// generates random objects in matrix due to its count
// TODO исправить способ генерации, так как не удобно использовать и менять
void PositionMatrix::generateFieldPartsRandomly()
{
	int sizeOfField = getCountRows() * getCountColumns();
	int countForest = sizeOfField * 0.4 * 0;
	int countStone = sizeOfField * 0.1;

	QVector<int> countOfImageTypes = { countPrey, countPredator, countForest, countStone, countZombie };

	std::map<MyGame::ImageType, int> typeForGenerate;
	MyGame::ImageType type = MyGame::prey;

	for (auto countOfImageType : countOfImageTypes) {
		typeForGenerate.emplace(type++, countOfImageType);
	}

	for (auto& [key, value] : typeForGenerate) {
		generateObject(key, value);
	}
}

void PositionMatrix::removeActorFromPosition(const Position& position) {

	if (isValidPosition(position)) {
		int row = position.getPosition().getRow();
		int column = position.getPosition().getColumn();
		positionMatrix[row][column] = MyGame::grass;
	}

}

Position PositionMatrix::findNearestActor(const Position& position, const MyGame::ImageType actorType) const {
	int minDistance = INT_MAX;
	Position nearestActorPosition;

	for (int row = 0; row < getCountRows(); ++row) {
		for (int column = 0; column < getCountColumns(); ++column) {
			if (positionMatrix[row][column] == actorType) {
				int distance = std::abs(row - position.getPosition().getRow()) + std::abs(column - position.getPosition().getColumn());
				if (distance < minDistance) {
					minDistance = distance;
					nearestActorPosition = Position(row, column);
				}
			}
		}
	}

	return nearestActorPosition;
}

void PositionMatrix::generateObject(MyGame::ImageType objectType, int count)
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

void PositionMatrix::updateRowAndColumnByMoveTarget(int& newRow, int& newColumn, const MoveDestination& moveTarget) const
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

bool PositionMatrix::isGrass(const Position& position) const
{
	int row = position.getPosition().getRow();
	int column = position.getPosition().getColumn();

	return positionMatrix[row][column] == MyGame::grass;
}

void PositionMatrix::getRowAndColumn(int& row, int& column, const Position& position)
{
	row = position.getPosition().getRow();
	column = position.getPosition().getColumn();
}

QVector<QPair<Position, MyGame::ImageType>> PositionMatrix::getActorsPositions() const {
	QVector<QPair<Position, MyGame::ImageType>> stoppingPositions;

	for (int row = 0; row < getCountRows(); ++row) {
		for (int column = 0; column < getCountColumns(); ++column) {
			MyGame::ImageType type = positionMatrix[row][column];

			if (stoppingSet.contains(type)) {
				Position position(row, column);
				stoppingPositions.append(qMakePair(position, type));
			}
		}
	}

	return stoppingPositions;
}