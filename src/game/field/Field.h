#pragma once

#include <QWidget>

#include "ui_Field.h"
#include "./position_matrix/PositionMatrix.h"
#include "./field_sprite_vector/FieldSpriteVector.h"
#include "actors/ActorsInterface.h";
#include "actors/predator/Predator.h";

QT_BEGIN_NAMESPACE
namespace Ui { class Field; };
QT_END_NAMESPACE


class Field : public QWidget
{
	Q_OBJECT

public:
	Field(QWidget* parent = nullptr, int rows = 10, int columns = 10, int maxMoves = 10);
	~Field();

	void turn(const MoveDestination& directionPlayerMove);

signals:
	void preyCaught();
	void preyEscape();

private:
	Ui::Field* ui;
	PositionMatrix positionMatrix;
	FieldSpriteVector fieldSpriteVector;
	QList<ActorsInterface*> actors;
	int movesCounter;
	const int maxMoves;

	void createFieldSpriteVector();

	void nextTurn();
	bool playerMove(const MoveDestination& direction);
	void changeImageTypeAfterMove(ActorsInterface& actor, const Position& newPosition);

	bool isEndOfgame();

};
