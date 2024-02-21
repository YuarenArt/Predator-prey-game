#pragma once

#include <QMainWindow>
#include "ui_PredatorPreyGame.h"
#include "field_sprite/FieldSprite.h"

const QString BACKGROUNDPATH = "./resources/images/mainBackground.jpg";

QT_BEGIN_NAMESPACE
namespace Ui { class PredatorPreyGameClass; };
QT_END_NAMESPACE

class PredatorPreyGame : public QMainWindow
{
	Q_OBJECT

public:
	PredatorPreyGame(QWidget *parent = nullptr);
	~PredatorPreyGame();

private:
	Ui::PredatorPreyGameClass *ui;
	//Class gamer

	void setMainBackgroundImage(QString pathToFile = BACKGROUNDPATH);

	void exitFullscreenMode();
	void enterFullscreenMode();
	void keyPressEvent(QKeyEvent* event) override;

};
