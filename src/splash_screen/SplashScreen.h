#pragma once

#include <QMainWindow>
#include <QLabel>
#include <QWidget>
#include <QTimer>
#include <QPixmap>

#include "ui_SplashScreen.h"

const QString SPLASHSCREENBACKGROUNDPATH = "././resources/images/background/spashScreenBackground.jpg";

class SplashScreen : public QMainWindow
{
    Q_OBJECT

public:
    SplashScreen(QWidget* parent = nullptr);

signals:
    void splashFinished();
};
