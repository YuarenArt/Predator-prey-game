#include "SplashScreen.h"

#include <QGuiApplication>
#include <QScreen>
#include <QVBoxLayout>


SplashScreen::SplashScreen(QWidget* parent) : QMainWindow(parent)
{
    QPixmap splashImage(SPLASHSCREENBACKGROUNDPATH);
    if (splashImage.isNull()) {
        qDebug() << "Failed to load splash image";
    }
    else {
        qDebug() << "Splash image loaded successfully";
    }

    QLabel* titleLabel = new QLabel("Predator-prey game", this);
    titleLabel->setStyleSheet("font-size: 96px; color: white;");
    titleLabel->setAlignment(Qt::AlignCenter);

    QVBoxLayout* layout = new QVBoxLayout();
    layout->addWidget(titleLabel);
    layout->setAlignment(Qt::AlignCenter);

    QWidget* centralWidget = new QWidget(this);
    centralWidget->setLayout(layout);
    setCentralWidget(centralWidget);

    splashImage = splashImage.scaled(this->size(), Qt::IgnoreAspectRatio, Qt::SmoothTransformation);

    QPalette palette;
    palette.setBrush(QPalette::Window, splashImage);
    this->setPalette(palette);

    setWindowFlags(Qt::WindowStaysOnTopHint);

    QTimer::singleShot(3000, this, &SplashScreen::close);
}