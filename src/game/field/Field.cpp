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

void Field::createActors()
{
	QVector<QPair<Position, MyGame::ImageType>> actorsPositions = positionMatrix.getActorsPositions();

	for (const auto& actorPosition : actorsPositions)
	{
		const Position&		     position = actorPosition.first;
		const MyGame::ImageType& imageType = actorPosition.second;

		if (imageType == MyGame::predator)
		{
			Predator* predator = new Predator(position);
			actors.append(predator);
		}
		else if (imageType == MyGame::prey)
		{
			Prey* prey = new Prey(position);
			actors.append(prey);
		}
		else if (imageType == MyGame::zombie)
		{
			Zombie* zombie = new Zombie(position);
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
	if (playerMove(directionPlayerMove)) {
		
		if (movesCounter > maxMoves) {
			emit preyEscape(true);
			return ;
		}

		nextTurn();
	}
}

void Field::nextTurn()
{
	for (auto npc : actors)
	{
		if (!npc->isPlayer())
		{
			Position newPosition = npc->move(gameSettings.getDifficult(), positionMatrix);

			if (npc->getImageType() != MyGame::prey && positionMatrix.isPreyPosition(newPosition)) {
				emit preyCaught(true);
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
			Position newPosition = positionMatrix.positionAfterMove(currentPosition, player->getMoveLength(), direction, player->getImageType());

			if (currentPosition == newPosition) return false;

			if (player->getImageType() == MyGame::predator && positionMatrix.isPreyPosition(currentPosition)) {
				emit preyCaught(true);
				break;
			}

			if (player->getImageType() == MyGame::predator && positionMatrix.isPreyPosition(newPosition)) {
				emit preyCaught(true);
				break;
			}

			if (positionMatrix.isZombiePosition(newPosition)) {

				removeActor(newPosition, MyGame::ImageType::zombie);
				positionMatrix.removeActorFromPosition(newPosition);
			}

			changeImageTypeAfterMove(*player, newPosition);
			movesCounter++;

			if (movesCounter > maxMoves) {
				emit preyEscape(false);
				break;
			}

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
