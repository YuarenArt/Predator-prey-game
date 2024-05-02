#include "SplashScreen.h"

#include <QGuiApplication>
#include <QScreen>
#include <QVBoxLayout>
#include <QLabel>
#include <QTimer>

SplashScreen::SplashScreen() : QSplashScreen(QPixmap(SPLASH_SCREEN_BACKGROUND_PATH), Qt::WindowStaysOnTopHint)
{
    QPixmap pixmap(SPLASH_SCREEN_BACKGROUND_PATH);
    if (pixmap.isNull()) {
        qDebug() << "Failed to load splash image";
    }
    else {
        qDebug() << "Splash image loaded successfully";
    }
    QRect screenGeometry = QGuiApplication::primaryScreen()->geometry();
    pixmap = pixmap.scaled(screenGeometry.size(), Qt::IgnoreAspectRatio, Qt::SmoothTransformation);

    QLabel* label = new QLabel("Predator-Prey Game", this);
    label->setStyleSheet("font-size: 72px; color: white");
    label->move(screenGeometry.center().x()-300, screenGeometry.center().y()-120);


    setPixmap(pixmap);
    QTimer::singleShot(3000, this, &SplashScreen::close);
}