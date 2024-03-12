#include "PredatorPreyGame.h"

#include <QKeyEvent>
#include <QSizeGrip>
#include <QThread>

PredatorPreyGame::PredatorPreyGame(QWidget *parent)
	: QMainWindow(parent)
	, ui(new Ui::PredatorPreyGame())
{
	// Запланировать показ заставки с небольшой задержкой
	QTimer::singleShot(0, this, &PredatorPreyGame::showSplashScreen);

	ui->setupUi(this);
	setMainBackgroundImage();
	enterFullscreenMode();
	ui->controlWidget->setVisible(false);

	field = nullptr;
	ui->fieldLaout->addWidget(field);

	connect(ui->menuWidget->ui->newGameBtn, &QPushButton::clicked, this, &PredatorPreyGame::startNewGame);
	connect(ui->menuWidget->ui->exitBtn, &QPushButton::clicked, this, &PredatorPreyGame::close);
}

PredatorPreyGame::~PredatorPreyGame()
{
	delete ui;
	delete field;

}

void PredatorPreyGame::setMainBackgroundImage(QString pathToFile)
{
	QPixmap bkgnd(pathToFile);
	bkgnd = bkgnd.scaled(this->size(), Qt::IgnoreAspectRatio);
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

void PredatorPreyGame::createField()
{
	if (field != nullptr) {
		delete field;
		field = nullptr;
	}

	field = new Field(this, 10, 10); 
	ui->fieldLaout->addWidget(field);
}

void PredatorPreyGame::startNewGame()
{
	createField();
	hideMenu();
	showControl();
}

void PredatorPreyGame::clearField()
{
	field = nullptr;
}

void PredatorPreyGame::showSplashScreen()
{
	SplashScreen* splashScreen = new SplashScreen;
	splashScreen->showFullScreen();
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

