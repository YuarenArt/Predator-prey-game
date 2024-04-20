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
	EndOfGameWidget(QWidget *parent = nullptr, bool isWin = true, MyGame::ImageType typeOfPlayer = MyGame::predator);
	~EndOfGameWidget();

private:
	Ui::EndOfGameWidget *ui;
	static QMap<MyGame::ImageType, QString> winMessages;
	static QMap<MyGame::ImageType, QString> loseMessages;

	void moveUpCenter();
	void createLabel(bool isWin = true, MyGame::ImageType typeOfPlayer = MyGame::predator);

};
