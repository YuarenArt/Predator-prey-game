#pragma once

#include <QWidget>
#include "ui_ControlBtns.h"

QT_BEGIN_NAMESPACE
namespace Ui { class ControlBtns; };
QT_END_NAMESPACE

class ControlBtns : public QWidget
{
	Q_OBJECT

public:
	ControlBtns(QWidget *parent = nullptr);
	~ControlBtns();

private:
	Ui::ControlBtns *ui;
};
