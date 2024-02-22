#pragma once

#include <QWidget>
#include "ui_Menu.h"

QT_BEGIN_NAMESPACE
namespace Ui { class Menu; };
QT_END_NAMESPACE

class Menu : public QWidget
{
	Q_OBJECT

public:
	Menu(QWidget *parent = nullptr);
	~Menu();

private:
	Ui::Menu *ui;
};
