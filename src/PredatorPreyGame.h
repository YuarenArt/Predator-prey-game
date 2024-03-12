#pragma once

#include <QMainWindow>

#include "ui_PredatorPreyGame.h"
#include "splash_screen/SplashScreen.h"
#include "widgets/menu/Menu.h"
#include "field/Field.h"
#include "widgets/control/ControlBtns.h";


const QString BACKGROUNDPATH = ":/PredatorPreyGame/resources/images/background/mainBackground.jpg";

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
	Field* field;

	void setMainBackgroundImage(QString pathToFile = BACKGROUNDPATH);

	void exitFullscreenMode();
	void enterFullscreenMode();
	void keyPressEvent(QKeyEvent* event) override;
	void toggleFullscreenMode();
	void toggleMenuVisibility();
	void createField();

	void startNewGame();
	void clearField();
	void showSplashScreen();
	void showMenu();
	void hideMenu();

	void showControl();

	void hideControl();

};
