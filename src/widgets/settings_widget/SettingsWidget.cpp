#include "SettingsWidget.h"

SettingsWidget::SettingsWidget(QWidget* parent)
    : QWidget(parent)
    , ui(new Ui::SettingsWidget)
{
    ui->setupUi(this);

    // Создаем группу радиокнопок сложности
    QButtonGroup* difficultyButtonGroup = new QButtonGroup(this);
    difficultyButtonGroup->addButton(ui->normalDifficultyRadioButton, 0);
    difficultyButtonGroup->addButton(ui->hardDifficultyRadioButton, 1);

    // Создаем группу радиокнопок ролей
    QButtonGroup* roleButtonGroup = new QButtonGroup(this);
    roleButtonGroup->addButton(ui->preyRoleRadioButton, 0);
    roleButtonGroup->addButton(ui->predatorRoleRadioButton, 1);

    // Выбираем значения по умолчанию
    ui->normalDifficultyRadioButton->setChecked(true);
    ui->predatorRoleRadioButton->setChecked(true);
}

SettingsWidget::~SettingsWidget()
{
    delete ui;
}

Difficult SettingsWidget::getDifficulty() const
{
    if (ui->normalDifficultyRadioButton->isChecked()) {
        return Difficult::standart;
    }
    else if (ui->hardDifficultyRadioButton->isChecked()) {
        return Difficult::hard;
    }
    return Difficult::standart;
}

MyGame::ImageType SettingsWidget::getRole() const
{
    if (ui->preyRoleRadioButton->isChecked()) {
        return MyGame::ImageType::prey;
    }
    else if (ui->predatorRoleRadioButton->isChecked()) {
        return MyGame::ImageType::predator;
    }
    return MyGame::ImageType::prey;
}
