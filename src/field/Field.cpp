#include "Field.h"

Field::Field(QWidget *parent, int rows, int columns)
	: QWidget(parent), ui(new Ui::Field())
{
	ui->setupUi(this);

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
