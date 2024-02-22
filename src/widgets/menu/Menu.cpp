#include "Menu.h"

Menu::Menu(QWidget *parent)
	: QWidget(parent)
	, ui(new Ui::Menu())
{
	ui->setupUi(this);
}

Menu::~Menu()
{
	delete ui;
}
