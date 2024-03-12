#pragma once

#include <QWidget>

#include "ui_Field.h"
#include "./position_matrix/PositionMatrix.h"
#include "./field_sprite_vector/FieldSpriteVector.h"

QT_BEGIN_NAMESPACE
namespace Ui { class Field; };
QT_END_NAMESPACE

class Field : public QWidget
{
	Q_OBJECT

public:
	Field(QWidget* parent = nullptr, int rows = 10, int columns = 10);
	~Field();

	

private:
	Ui::Field* ui;
	PositionMatrix positionMatrix;
	FieldSpriteVector fieldSpriteVector;

	void createFieldSpriteVector();

};
