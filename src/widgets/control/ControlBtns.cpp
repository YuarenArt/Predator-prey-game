#include "ControlBtns.h"

ControlBtns::ControlBtns(QWidget *parent)
	: QWidget(parent)
	, ui(new Ui::ControlBtns())
{
	ui->setupUi(this);
}

ControlBtns::~ControlBtns()
{
	delete ui;
}
