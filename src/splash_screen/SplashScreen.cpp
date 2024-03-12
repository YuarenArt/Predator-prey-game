#include "SplashScreen.h"

#include <QGuiApplication>
#include <QScreen>
#include <QVBoxLayout>


SplashScreen::SplashScreen(QWidget* parent) : QWidget(parent)
{
    QPixmap splashImage(SPLASH_SCREEN_BACKGROUND_PATH);
    if (splashImage.isNull()) {
        qDebug() << "Failed to load splash image";
    }
    else {
        qDebug() << "Splash image loaded successfully";
    }

    // Создаем метку для названия игры и стилизуем ее
    QLabel* titleLabel = new QLabel("Predator-prey game", this);
    titleLabel->setStyleSheet("font-size: 96px; color: white;");
    titleLabel->setAlignment(Qt::AlignCenter);

    // Создаем layout и добавляем в него titleLabel
    QVBoxLayout* layout = new QVBoxLayout(this); // Применяем layout непосредственно к SplashScreen
    layout->addWidget(titleLabel);
    layout->setAlignment(Qt::AlignCenter);

    // Масштабируем изображение заставки, чтобы оно соответствовало размеру окна
    splashImage = splashImage.scaled(this->size(), Qt::IgnoreAspectRatio, Qt::SmoothTransformation);

    // Устанавливаем заставку как фон окна
    QPalette palette;
    palette.setBrush(QPalette::Window, QBrush(splashImage));
    this->setPalette(palette);

    // Указываем, что окно должно оставаться поверх других окон
    setWindowFlags(Qt::WindowStaysOnTopHint | Qt::FramelessWindowHint); // Добавляем флаг для создания окна без рамки

    // Автоматически закрываем заставку через 3 секунды
    QTimer::singleShot(3000, this, &SplashScreen::close);
}