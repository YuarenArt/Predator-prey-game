#include "Field.h"

Field::Field(QWidget *parent, int rows, int columns, int maxMoves)
	: QWidget(parent), ui(new Ui::Field()), maxMoves(maxMoves)
{
	ui->setupUi(this);

	movesCounter = 0;

	positionMatrix = PositionMatrix(rows, columns);
	positionMatrix.generateFieldPartsRandomly();

	createFieldSpriteVector();

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

// returns true if gameover:
// - prey is successfully escape
// - predator catch the prey
void Field::turn(const MoveDestination& directionPlayerMove) {
	if (playerMove(directionPlayerMove)) {
		
		if (movesCounter > maxMoves) {
			emit preyEscape();
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
			Position newPosition = npc->move();
			changeImageTypeAfterMove(*npc, newPosition);

			if (npc->getImageType() != Prey && positionMatrix.isPreyPosition(newPosition)) {
				emit preyCaught();
				break;
			}


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
			Position newPosition = positionMatrix.positionAfterMove(currentPosition, player->getMoveLength(), direction);

			if (currentPosition == newPosition) return false;

			if (player->getImageType() == Predator && positionMatrix.isPreyPosition(newPosition)) {
				emit preyCaught();
				break;
			}

			changeImageTypeAfterMove(*player, newPosition);
			movesCounter++;

			if (movesCounter > maxMoves) {
				emit preyEscape();
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

	positionMatrix.changeImageTypeInMatrix(oldPosition, Grass);
	positionMatrix.changeImageTypeInMatrix(newPosition, actor.getImageType());
	actor.setPosition(newPosition);
}


