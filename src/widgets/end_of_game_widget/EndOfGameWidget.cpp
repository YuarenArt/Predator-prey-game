#include "endOfGameWidget.h"
#include <QScreen>

const QString winPredator = 
QObject::tr("<p style='font-size: 20px; color: green;'><b>Yay! &#x1F603; </b>You caught the prey!</p>");

const QString losePredator = 
QObject::tr("<p style='font-size: 20px; color: darkred;'><b>Unfortunately, &#x1F61E; </b>your prey has escaped...</p>");

const QString winPrey = 
QObject::tr("<p style='font-size: 20px; color: green;'><b>Great! &#x1F60E; </b>You managed to escape from the predator!</p>");

const QString losePrey = 
QObject::tr("<p style='font-size: 20px; color: darkred;'><b>Sorry, &#x1F615; </b>you were caught by the predator...</p>");

const QString preyCaughtByZombie =
QObject::tr("<p style='font-size: 20px; color: darkred;'><b>Oh no! &#x1F637; </b>You were caught by a zombie!</p>");

const QString predatorLostPrey = 
QObject::tr("<p style='font-size: 20px; color: darkred;'><b>Darn! &#x1F625; </b>Your prey was caught by a zombie...</p>");


QMap<MyGame::ImageType, QString> EndOfGameWidget::winMessages = {
    {MyGame::predator, winPredator},
    {MyGame::prey, winPrey}
};

QMap<MyGame::ImageType, QString> EndOfGameWidget::loseMessages = {
    {MyGame::predator, losePredator},
    {MyGame::prey, losePrey},
    {MyGame::zombie, predatorLostPrey} 
};

EndOfGameWidget::EndOfGameWidget(QWidget* parent, MyGame::ImageType typeOfWinner, MyGame::ImageType typeOfPlayer)
    : QWidget(parent)
    , ui(new Ui::EndOfGameWidget())
{
    ui->setupUi(this);
    ui->label->setWordWrap(true);
    ui->label->setStyleSheet("p { margin-bottom: 5px; }");

    setWindowFlags(Qt::WindowStaysOnTopHint);
    setWindowFlags(Qt::FramelessWindowHint);
    setWinPalette();

    moveUpCenter();
    createLabel(typeOfWinner, typeOfPlayer);

    connect(ui->okButton, &QPushButton::clicked, this, &QWidget::close);
}

EndOfGameWidget::~EndOfGameWidget()
{
    delete ui;
}

void EndOfGameWidget::moveUpCenter()
{
    QScreen* screen = QGuiApplication::primaryScreen();
    QRect screenGeometry = screen->geometry();

    int x = (screenGeometry.width() - width()) / 2;
    move(x, 30);
}

void EndOfGameWidget::createLabel(MyGame::ImageType typeOfWinner, MyGame::ImageType typeOfPlayer)
{
    QString message;
    if (typeOfWinner == typeOfPlayer) {
        message = winMessages.value(typeOfPlayer);
    }
    else if (typeOfWinner == MyGame::zombie) {
        message = (typeOfPlayer == MyGame::prey) ? preyCaughtByZombie : loseMessages.value(MyGame::zombie);
    }
    else {
        message = loseMessages.value(typeOfPlayer);
    }
    ui->label->setTextFormat(Qt::RichText);
    ui->label->setText(message);
}

void EndOfGameWidget::setWinPalette()
{
    QPalette palette;
    palette.setColor(QPalette::Window, Qt::white);
    setPalette(palette);
    setAutoFillBackground(true);
}