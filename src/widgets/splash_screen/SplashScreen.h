#pragma once

#include <QSplashScreen>

const QString SPLASH_SCREEN_BACKGROUND_PATH = ":/PredatorPreyGame/resources/images/background/spashScreenBackground.jpg";

class SplashScreen : public QSplashScreen
{
    Q_OBJECT

public:
    SplashScreen();

signals:
    void splashFinished();
};
