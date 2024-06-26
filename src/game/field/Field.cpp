#include "Field.h"

Field::Field(QWidget* parent, int rows, int columns, int maxMoves, Difficult difficult, MyGame::ImageType typeOfplayer) :
	
	QWidget(parent), ui(new Ui::Field()), maxMoves(maxMoves), gameSettings{ difficult, typeOfplayer, maxMoves }
{
	ui->setupUi(this);

	movesCounter = 0;

	positionMatrix = PositionMatrix(rows, columns);
	positionMatrix.generateFieldPartsRandomly();

	createFieldSpriteVector();
	createActors();
	setPlayer();

}

Field::~Field()
{
	delete ui;
}

void Field::createFieldSpriteVector()
{
	fieldSpriteVector = FieldSpriteVector(this, positionMatrix.getCountRows(), positionMatrix.getCountColumns());

	fieldSpriteVector.fillFieldWithMatrix(positionMatrix.getPositionMatrix());

	ui->LayoutFieldSpriteVector->addWidget(&fieldSpriteVector);
	fieldSpriteVector.fillSpriteGrid();
}


// TODO сделать абстрактную фабрику
void Field::createActors()
{
	QVector<QPair<Position, MyGame::ImageType>> actorsPositions = positionMatrix.getActorsPositions();

	for (const auto& actorPosition : actorsPositions)
	{
		const Position&		     position = actorPosition.first;
		const MyGame::ImageType& imageType = actorPosition.second;
		Difficult difficult = gameSettings.getDifficult();

		if (imageType == MyGame::predator)
		{
			Predator* predator = new Predator(position, difficult);
			actors.append(predator);
		}
		else if (imageType == MyGame::prey)
		{
			Prey* prey = new Prey(position, difficult);
			actors.append(prey);
		}
		else if (imageType == MyGame::zombie)
		{
			Zombie* zombie = new Zombie(position, difficult);
			actors.append(zombie);
		}
	}

	for (auto actor : actors) {
		connect(actor, &ActorsInterface::removeActor, this, &Field::handleRemoveActor);
	}
}

void Field::setPlayer()
{
	MyGame::ImageType playerImageType = gameSettings.getTypeOfPlayer();

	for (auto& actor : actors) {
		if (actor->getImageType() == playerImageType) {
			actor->setPlayble();
		}
	}
}

void Field::removeActor(const Position& position, MyGame::ImageType type) {

	for (int i = 0; i < actors.size(); ++i) {
		if (actors[i]->getPosition() == position && actors[i]->getImageType() == type) {
			delete actors[i];
			actors.removeAt(i);
			break;
		}
	}
}

void Field::turn(const MoveDestination& directionPlayerMove) {
	if (isGameOver) {
		return;
	}

	if (playerMove(directionPlayerMove)) {
		if (movesCounter > maxMoves) {
			emit preyEscape(MyGame::prey);
			return;
		}

		nextTurn();
	}
}

void Field::nextTurn() {
	if (isGameOver) {
		return;
	}

	for (auto npc : actors) {
		if (!npc->isPlayer()) {
			Position newPosition = npc->move(gameSettings.getDifficult(), positionMatrix);

			checkPreyCaught(*npc, newPosition);

			if (isGameOver) {
				break;
			}

			changeImageTypeAfterMove(*npc, newPosition);
		}
	}
}

// returns true if move is successful
bool Field::playerMove(const MoveDestination& direction)
{
    for (auto player : actors)
    {
		if (player->isPlayer() && player->isValidMoveDirection(direction))
		{
			Position currentPosition = player->getPosition();
			Position newPosition = player->playerMove(direction, positionMatrix);

			if (currentPosition == newPosition) return false;

			checkPreyEscape();
            checkPreyCaught(*player, newPosition);

			if (positionMatrix.isActorPosition(newPosition, MyGame::zombie)) {
				removeActor(newPosition, MyGame::ImageType::zombie);
				positionMatrix.removeActorFromPosition(newPosition);
			}
			else if (positionMatrix.isActorPosition(newPosition, MyGame::predator)) {
				removeActor(newPosition, MyGame::ImageType::predator);
				positionMatrix.removeActorFromPosition(newPosition);
			}

			changeImageTypeAfterMove(*player, newPosition);
			movesCounter++;

			return true;
		}
    }
    return false;
}

void Field::changeImageTypeAfterMove(ActorsInterface& actor, const Position& newPosition)
{
	Position oldPosition = actor.getPosition();

	positionMatrix.changeImageTypeInMatrix(oldPosition, MyGame::grass);
	positionMatrix.changeImageTypeInMatrix(newPosition, actor.getImageType());

	fieldSpriteVector.changeImageTypeInVector(oldPosition, MyGame::grass);
	fieldSpriteVector.changeImageTypeInVector(newPosition, actor.getImageType());

	actor.setPosition(newPosition);
}

MyGame::ImageType Field::getPlayerType()
{
	return gameSettings.getTypeOfPlayer();
}

void Field::checkPreyEscape() {
	if (movesCounter > maxMoves) {
		emit preyEscape(MyGame::prey);
		isGameOver = true;
	}
}

void Field::checkPreyCaught(ActorsInterface& actor, const Position& newPosition) {
	if (actor.getImageType() != MyGame::prey && positionMatrix.isActorPosition(newPosition, MyGame::prey)) {
		emit preyCaught(actor.getImageType());
		isGameOver = true;
	}
	else if (actor.getImageType() == MyGame::prey && positionMatrix.isActorPosition(newPosition, MyGame::predator)) {
		emit preyCaught(MyGame::predator);
		isGameOver = true;
	}
	else if (actor.getImageType() == MyGame::prey && positionMatrix.isActorPosition(newPosition, MyGame::zombie)) {
		emit preyCaught(MyGame::zombie);
		isGameOver = true;
	}
	else if (actor.getImageType() == MyGame::predator && positionMatrix.isActorPosition(newPosition, MyGame::prey)) {
		emit preyCaught(MyGame::predator);
		isGameOver = true;
	}
	else if (actor.getImageType() == MyGame::zombie && positionMatrix.isActorPosition(newPosition, MyGame::predator)) {
		emit preyCaught(MyGame::zombie);
		isGameOver = true;
	}
}
