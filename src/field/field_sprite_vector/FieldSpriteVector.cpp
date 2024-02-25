#include "FieldSpriteVector.h"

FieldSpriteVector::FieldSpriteVector(QWidget* parent, int raw, int columns) 
	: QWidget(parent), ui(new Ui::FieldSpriteVector())
{


}

FieldSpriteVector::~FieldSpriteVector()
{
	delete ui;
}
