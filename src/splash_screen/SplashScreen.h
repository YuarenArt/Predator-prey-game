#pragma once

#include <QMainWindow>
#include <QLabel>
#include <QWidget>
#include <QTimer>
#include <QPixmap>

const QString SPLASH_SCREEN_BACKGROUND_PATH = ":/PredatorPreyGame/resources/images/background/spashScreenBackground.jpg";

class SplashScreen : public QWidget
{
    Q_OBJECT

public:
    SplashScreen(QWidget* parent = nullptr);

signals:
    void splashFinished();
};
