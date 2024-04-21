#pragma once

#include <QMainWindow>

#include "ui_PredatorPreyGame.h"
#include "field/Field.h"
#include "../widgets/advanced_settings_widget/AdvancedSettingsWidget.h"

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

	void endOfGame(MyGame::ImageType typeOfWinner);
	void showAdvancedSettings();

private:
	Ui::PredatorPreyGame   *ui;
	Field                  *field;
	AdvancedSettingsWidget *advancedSettingsWidget;

	void setMainBackgroundImage(QString pathToFile = BACKGROUNDPATH);

	void exitFullscreenMode();
	void enterFullscreenMode();
	void keyPressEvent(QKeyEvent* event) override;
	void toggleFullscreenMode();
	void toggleMenuVisibility();
	void toggleControlVisibility();
	void createField();
	void clearField();

	void startNewGame();

	void showSplashScreen();
	void showEndOfGameWidget(MyGame::ImageType typeOfWinner);
	void showMenu();
	void hideMenu();
	void showControl();
	void hideControl();
	void showField();
	void hideField();
	void hideSettings();
	void showSettings();

};
