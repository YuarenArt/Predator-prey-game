#include "Menu.h"

Menu::Menu(QWidget *parent)
	: QWidget(parent)
	, ui(new Ui::Menu())
{
	ui->setupUi(this);
	ui->menuLaout->setAlignment(Qt::AlignTop);
}

Menu::~Menu()
{
	delete ui;
}
