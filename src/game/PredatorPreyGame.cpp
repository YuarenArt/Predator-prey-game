#include "PredatorPreyGame.h"

#include <QKeyEvent>
#include <QSizeGrip>
#include <QThread>

#include "../widgets/control/ControlBtns.h";
#include "../widgets/splash_screen/SplashScreen.h"
#include "../widgets/menu/Menu.h"
#include "../widgets/end_of_game_widget/endOfGameWidget.h"
#include "./field/enums/enums.h"

PredatorPreyGame::PredatorPreyGame(QWidget *parent)
	: QMainWindow(parent)
	, ui(new Ui::PredatorPreyGame())
{
	// Shows the splachScrenn with short timeout
	QTimer::singleShot(0, this, &PredatorPreyGame::showSplashScreen);

	ui->setupUi(this);
	setMainBackgroundImage();
	enterFullscreenMode();
	ui->controlWidget->setVisible(false);

	advancedSettingsWidget = new AdvancedSettingsWidget;

	field = nullptr;
	ui->fieldLaout->addWidget(field);

	connect(ui->menuWidget->ui->newGameBtn, &QPushButton::clicked, this, &PredatorPreyGame::startNewGame);
	connect(ui->menuWidget->ui->exitBtn, &QPushButton::clicked, this, &PredatorPreyGame::close);
	connect(ui->menuWidget->ui->settingsBtn, &QPushButton::clicked, this, &PredatorPreyGame::showAdvancedSettings);
	
	connect(ui->controlWidget->ui->up, &QPushButton::clicked, this, &PredatorPreyGame::onPlayerMoveUp);
	connect(ui->controlWidget->ui->down, &QPushButton::clicked, this, &PredatorPreyGame::onPlayerMoveDown);
	connect(ui->controlWidget->ui->left, &QPushButton::clicked, this, &PredatorPreyGame::onPlayerMoveLeft);
	connect(ui->controlWidget->ui->right, &QPushButton::clicked, this, &PredatorPreyGame::onPlayerMoveRight);
	connect(ui->controlWidget->ui->upLeft, &QPushButton::clicked, this, &PredatorPreyGame::onPlayerMoveUpLeft);
	connect(ui->controlWidget->ui->upRight, &QPushButton::clicked, this, &PredatorPreyGame::onPlayerMoveUpRight);
	connect(ui->controlWidget->ui->downLeft, &QPushButton::clicked, this, &PredatorPreyGame::onPlayerMoveDownLeft);
	connect(ui->controlWidget->ui->downRight, &QPushButton::clicked, this, &PredatorPreyGame::onPlayerMoveDownRight);
}

PredatorPreyGame::~PredatorPreyGame()
{
	delete ui;
	delete field;
	delete advancedSettingsWidget;
}

void PredatorPreyGame::setMainBackgroundImage(QString pathToFile)
{
	QPixmap bkgnd(pathToFile);
	QPalette palette;
	palette.setBrush(QPalette::Window, bkgnd);
	this->setPalette(palette);
}

void PredatorPreyGame::exitFullscreenMode() {
	showNormal();
}

void PredatorPreyGame::enterFullscreenMode() {
	showFullScreen();
}

void PredatorPreyGame::keyPressEvent(QKeyEvent* event) {
	if (event->key() == Qt::Key_F11) {
		toggleFullscreenMode();
	}
	else if (event->key() == Qt::Key_Escape) {
		toggleMenuVisibility(); 
	}
	else if (event->key() == Qt::Key_F2) {
		if (field != nullptr) {
			toggleControlVisibility();
		}
	}
	else {
		QMainWindow::keyPressEvent(event);
	}
}

void PredatorPreyGame::toggleFullscreenMode() {
	if (isFullScreen()) {
		showNormal();
	}
	else {
		showFullScreen();
	}
}

void PredatorPreyGame::toggleMenuVisibility() {
	if (ui->menuWidget->isVisible()) {
		hideMenu(); 
	}
	else {
		showMenu();
	}
}

void PredatorPreyGame::toggleControlVisibility() {
	if (ui->controlWidget->isVisible()) {
		hideControl();
	}
	else {
		showControl();
	}
}

void PredatorPreyGame::startNewGame()
{
	createField();
	showField();
	hideMenu();
	showControl();
	hideSettings();
}

void PredatorPreyGame::createField()
{
	Difficult		  difficult = ui->settingsWidget->getDifficulty();
	MyGame::ImageType typeOfPlayer = ui->settingsWidget->getRole();

	clearField();
	
	unsigned int countRows   = advancedSettingsWidget->getCountRows();
	unsigned int countColums = advancedSettingsWidget->getCountColums();
	unsigned int countMoves  = advancedSettingsWidget->getCountMoves();

	field = new Field(this, countRows, countColums, countMoves, difficult, typeOfPlayer);
	ui->fieldLaout->addWidget(field);

	connect(field, &Field::preyCaught, this, &PredatorPreyGame::endOfGame);
	connect(field, &Field::preyEscape, this, &PredatorPreyGame::endOfGame);
}

void PredatorPreyGame::clearField()
{
	if (field != nullptr) {
		delete field;
		field = nullptr;
	}
}

void PredatorPreyGame::showSplashScreen()
{
	SplashScreen* splashScreen = new SplashScreen;
	splashScreen->showFullScreen();
}

void PredatorPreyGame::showEndOfGameWidget(MyGame::ImageType typeOfWinner)
{
	EndOfGameWidget* endOfGameWidget = new EndOfGameWidget(this, typeOfWinner, field->getPlayerType());
	endOfGameWidget->show();
}

void PredatorPreyGame::showMenu()
{
	ui->menuWidget->show();
}

void PredatorPreyGame::hideMenu()
{
	ui->menuWidget->hide();
}

void PredatorPreyGame::showControl()
{
	ui->controlWidget->show();
}

void PredatorPreyGame::hideControl()
{
	ui->controlWidget->hide();
}
 
void PredatorPreyGame::onPlayerMoveUp()
{
    field->turn(MoveDestination::Up);
}

void PredatorPreyGame::onPlayerMoveDown()
{
	field->turn(MoveDestination::Down);
}

void PredatorPreyGame::onPlayerMoveLeft()
{
	field->turn(MoveDestination::Left);
}

void PredatorPreyGame::onPlayerMoveRight()
{
	field->turn(MoveDestination::Right);
}

void PredatorPreyGame::onPlayerMoveUpLeft()
{
	field->turn(MoveDestination::UpLeft);
}

void PredatorPreyGame::onPlayerMoveDownLeft()
{
	field->turn(MoveDestination::DownLeft);
}

void PredatorPreyGame::onPlayerMoveDownRight()
{
	field->turn(MoveDestination::DownRight);
}

void PredatorPreyGame::onPlayerMoveUpRight()
{
	field->turn(MoveDestination::UpRight);
}

void PredatorPreyGame::endOfGame(MyGame::ImageType typeOfWinner)
{
	hideField();
	hideControl();
	showMenu();
	showSettings();

	showEndOfGameWidget(typeOfWinner);
}

void PredatorPreyGame::showAdvancedSettings()
{
	advancedSettingsWidget->show();
}

void PredatorPreyGame::showField()
{
	ui->field->show();
}

void PredatorPreyGame::hideField()
{
	ui->field->hide();
}

void PredatorPreyGame::hideSettings()
{
	ui->settingsWidget->hide();
}

void PredatorPreyGame::showSettings()
{
	ui->settingsWidget->show();
}

