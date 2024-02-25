#pragma once

#include <QMainWindow>

#include "ui_PredatorPreyGame.h"
#include "field/field_sprite/FieldSprite.h"
#include "splash_screen/SplashScreen.h"
#include "widgets/menu/Menu.h"
#include "field/field_sprite_vector/FieldSpriteVector.h"

const QString BACKGROUNDPATH = "./resources/images/mainBackground.jpg";

QT_BEGIN_NAMESPACE
namespace Ui { class PredatorPreyGame; };
QT_END_NAMESPACE

class PredatorPreyGame : public QMainWindow
{
	Q_OBJECT

public:
	PredatorPreyGame(QWidget *parent = nullptr);
	~PredatorPreyGame();

private:
	Ui::PredatorPreyGame* ui;
	Menu* menu;
	//Class gamer

	void setMainBackgroundImage(QString pathToFile = BACKGROUNDPATH);

	void exitFullscreenMode();
	void enterFullscreenMode();
	void keyPressEvent(QKeyEvent* event) override;

};
