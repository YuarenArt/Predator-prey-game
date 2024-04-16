#pragma once

#include <QWidget>
#include <QComboBox>
#include <QRadioButton>
#include <QButtonGroup>
#include <QVBoxLayout>
#include <QLabel>

#include "ui_SettingsWidget.h"
#include "../../game/field/enums/enums.h"

QT_BEGIN_NAMESPACE
namespace Ui { class SettingsWidget; };
QT_END_NAMESPACE

class SettingsWidget : public QWidget
{
    Q_OBJECT

public:
    SettingsWidget(QWidget* parent = nullptr);
    ~SettingsWidget();

    Difficult         getDifficulty() const;
    MyGame::ImageType getRole() const;

private:
    Ui::SettingsWidget* ui;
};
