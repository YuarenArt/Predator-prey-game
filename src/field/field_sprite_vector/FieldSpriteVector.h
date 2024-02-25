#pragma once

#include <QWidget>
#include <Qvector>

#include "ui_FieldSpriteVector.h"
#include "/Users/HP/source/repos/Predator-prey game/src/field/field_sprite/FieldSprite.h"

QT_BEGIN_NAMESPACE
namespace Ui { class FieldSpriteVector; };
QT_END_NAMESPACE

class FieldSpriteVector : public QWidget
{
	Q_OBJECT

public:
	FieldSpriteVector(QWidget *parent = nullptr, int raw = 10, int columns = 10);
	~FieldSpriteVector();

private:
	Ui::FieldSpriteVector *ui;
	QVector<QVector<FieldSprite>> fieldSpriteVector;

};
