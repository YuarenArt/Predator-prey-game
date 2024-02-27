#pragma once

#include <QWidget>
#include <Qvector>


#include "ui_FieldSpriteVector.h"
#include "field_sprite/FieldSprite.h"

QT_BEGIN_NAMESPACE
namespace Ui { class FieldSpriteVector; };
QT_END_NAMESPACE

class FieldSpriteVector : public QWidget
{
	Q_OBJECT

public:
	FieldSpriteVector(QWidget *parent = nullptr, int rows = 10, int columns = 10);
	~FieldSpriteVector();

	int getRowCount();
	int getColumnsCount();

	void fillFieldWithMatrix(QVector<QVector<ImageType>> matrix);
	void fillFieldWithRandom(int rows, int columns);
	void fillSpriteGrid();

private:
	Ui::FieldSpriteVector* ui;
	QVector<QVector<FieldSprite>> fieldSpriteVector;

};
