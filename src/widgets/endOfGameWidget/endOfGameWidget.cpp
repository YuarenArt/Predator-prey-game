#include "endOfGameWidget.h"

#include <QScreen>

const QString winPredator = QObject::tr("<p style='font-size: 20px; color: green;'><b>Yay! &#x1F603; </b>You caught the prey!</p>");
const QString losePredator = QObject::tr("<p style='font-size: 20px; color: darkred;'><b>Unfortunately, &#x1F61E; </b>your prey has escaped...</p>");
const QString winPrey = QObject::tr("<p style='font-size: 20px; color: green;'><b>Great! &#x1F60E; </b>You managed to escape from the predator!</p>");
const QString losePrey = QObject::tr("<p style='font-size: 20px; color: darkred;'><b>Sorry, &#x1F615; </b>you were caught by the predator...</p>");

QMap<MyGame::ImageType, QString> EndOfGameWidget::winMessages = {
	{MyGame::predator, winPredator},
	{MyGame::prey, winPrey}
};

QMap<MyGame::ImageType, QString> EndOfGameWidget::loseMessages = {
	{MyGame::predator, losePredator},
	{MyGame::prey, losePrey}
};

EndOfGameWidget::EndOfGameWidget(QWidget* parent, bool isWin, MyGame::ImageType typeOfPlayer)
	: QWidget(parent)
	, ui(new Ui::EndOfGameWidget())
{
	ui->setupUi(this);
	ui->label->setWordWrap(true);
	ui->label->setStyleSheet("p { margin-bottom: 5px; }");

	setWindowFlags(Qt::WindowStaysOnTopHint);
	setWindowFlags(Qt::FramelessWindowHint);
	setWinPallete();

	moveUpCenter();
	createLabel(isWin, typeOfPlayer);

	connect(ui->okButton, &QPushButton::clicked, this, &QWidget::close);
}

EndOfGameWidget::~EndOfGameWidget()
{
	delete ui;
}

void EndOfGameWidget::moveUpCenter()
{
	QScreen* screen = QGuiApplication::primaryScreen();
	QRect  screenGeometry = screen->geometry();

	int x = (screenGeometry.width() - width()) / 2;
	move(x, 30);
}

void EndOfGameWidget::createLabel(bool isWin, MyGame::ImageType typeOfPlayer)
{
	QString message = isWin ? winMessages.value(typeOfPlayer) : loseMessages.value(typeOfPlayer);
	ui->label->setTextFormat(Qt::RichText);
	ui->label->setText(message);

}

void EndOfGameWidget::setWinPallete()
{
	QPalette palette;
	palette.setColor(QPalette::Window, Qt::white);
	setPalette(palette);
	setAutoFillBackground(true);
}
