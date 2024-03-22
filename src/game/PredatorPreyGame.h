#pragma once

#include <QMainWindow>

#include "ui_PredatorPreyGame.h"
#include "field/Field.h"



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

private slots:
	void onPlayerMoveUp();
	void onPlayerMoveDown();
	void onPlayerMoveLeft();
	void onPlayerMoveRight();
	void onPlayerMoveUpLeft();
	void onPlayerMoveDownLeft();
	void onPlayerMoveDownRight();
	void onPlayerMoveUpRight();

	void onPreyCaught();
	void endOfGame();

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
