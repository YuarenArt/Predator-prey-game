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

	menu = new Menu(this);
	ui->menuLaout->addWidget(menu);

	field = nullptr;
	ui->fieldLaout->addWidget(field);

	connect(menu->ui->newGameBtn, &QPushButton::clicked, this, &PredatorPreyGame::startNewGame);
	connect(menu->ui->exitBtn, &QPushButton::clicked, this, &PredatorPreyGame::close);
}

PredatorPreyGame::~PredatorPreyGame()
{
	delete ui;
	delete menu;
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
	if (menu->isVisible()) {
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
	ui->menu->show();
}

void PredatorPreyGame::hideMenu()
{
	ui->menu->hide();
}

