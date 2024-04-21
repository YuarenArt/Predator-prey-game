#pragma once

#include <QWidget>

#include "ui_Field.h"

#include "position_matrix/PositionMatrix.h"
#include "field_sprite_vector/FieldSpriteVector.h"
#include "actors/ActorsInterface.h";
#include "actors/predator/Predator.h";
#include "actors/prey/Prey.h";
#include "actors/zombie/Zombie.h";
#include "game_settings/GameSettings.h"

QT_BEGIN_NAMESPACE
namespace Ui { class Field; };
QT_END_NAMESPACE


class Field : public QWidget
{
	Q_OBJECT

public:
	Field(QWidget* parent = nullptr, int rows = 10, int columns = 10, int maxMoves = 10, 
		  Difficult difficult = standart, MyGame::ImageType typeOfplayer = MyGame::predator);
	~Field();

	void turn(const MoveDestination& directionPlayerMove);
	MyGame::ImageType getPlayerType();

signals:
	void preyCaught(MyGame::ImageType typeOfWinner);
	void preyEscape(MyGame::ImageType typeOfWinner);


private slots:
	void handleRemoveActor(const Position& position, MyGame::ImageType type) {
		removeActor(position, type);
	}

private:
	Ui::Field*              ui;
	PositionMatrix          positionMatrix;
	FieldSpriteVector       fieldSpriteVector;
	QList<ActorsInterface*> actors;
	GameSettings            gameSettings;
	int                     movesCounter;
	const int               maxMoves;

	void createFieldSpriteVector();
	void createActors();
	void setPlayer();
	void removeActor(const Position& position, MyGame::ImageType type);

	void nextTurn();
	bool playerMove(const MoveDestination& direction);
	void changeImageTypeAfterMove(ActorsInterface& actor, const Position& newPosition);

	bool isEndOfgame();

};
