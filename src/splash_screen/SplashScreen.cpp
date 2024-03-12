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

    // ������� ����� ��� �������� ���� � ��������� ��
    QLabel* titleLabel = new QLabel("Predator-prey game", this);
    titleLabel->setStyleSheet("font-size: 96px; color: white;");
    titleLabel->setAlignment(Qt::AlignCenter);

    // ������� layout � ��������� � ���� titleLabel
    QVBoxLayout* layout = new QVBoxLayout(this); // ��������� layout ��������������� � SplashScreen
    layout->addWidget(titleLabel);
    layout->setAlignment(Qt::AlignCenter);

    // ������������ ����������� ��������, ����� ��� ��������������� ������� ����
    splashImage = splashImage.scaled(this->size(), Qt::IgnoreAspectRatio, Qt::SmoothTransformation);

    // ������������� �������� ��� ��� ����
    QPalette palette;
    palette.setBrush(QPalette::Window, QBrush(splashImage));
    this->setPalette(palette);

    // ���������, ��� ���� ������ ���������� ������ ������ ����
    setWindowFlags(Qt::WindowStaysOnTopHint | Qt::FramelessWindowHint); // ��������� ���� ��� �������� ���� ��� �����

    // ������������� ��������� �������� ����� 3 �������
    QTimer::singleShot(3000, this, &SplashScreen::close);
}