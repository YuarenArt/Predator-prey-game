#include "PredatorPreyGame.h"

#include <QKeyEvent>
#include <QSizeGrip>

PredatorPreyGame::PredatorPreyGame(QWidget *parent)
	: QMainWindow(parent)
	, ui(new Ui::PredatorPreyGameClass())
{
	ui->setupUi(this);

	setMainBackgroundImage();

	enterFullscreenMode();

}

PredatorPreyGame::~PredatorPreyGame()
{
	delete ui;
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
		enterFullscreenMode();
	}
	else if (event->key() == Qt::Key_Escape) {
		exitFullscreenMode();
	}
	else {
		QMainWindow::keyPressEvent(event);
	}
}


