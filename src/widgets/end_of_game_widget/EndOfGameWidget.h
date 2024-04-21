#pragma once

#include <QWidget>

#include "ui_endOfGameWidget.h"
#include "../../game/field/enums/enums.h"

QT_BEGIN_NAMESPACE
namespace Ui { class EndOfGameWidget; };
QT_END_NAMESPACE

class EndOfGameWidget : public QWidget
{
	Q_OBJECT

public:
	EndOfGameWidget(QWidget *parent, MyGame::ImageType typeOfWinner, MyGame::ImageType typeOfPlayer);
	~EndOfGameWidget();

private:
	Ui::EndOfGameWidget *ui;
	static QMap<MyGame::ImageType, QString> winMessages;
	static QMap<MyGame::ImageType, QString> loseMessages;

	void moveUpCenter();
	void createLabel(MyGame::ImageType typeOfWinner, MyGame::ImageType typeOfPlayer);
	void setWinPalette();

};
