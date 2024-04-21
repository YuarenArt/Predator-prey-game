#pragma once

#include <QWidget>
#include "ui_AdvancedSettingsWidget.h"

QT_BEGIN_NAMESPACE
namespace Ui { class AdvancedSettingsWidget; };
QT_END_NAMESPACE



class AdvancedSettingsWidget : public QWidget
{
	Q_OBJECT

public:
	AdvancedSettingsWidget(QWidget *parent = nullptr);
	~AdvancedSettingsWidget();

	unsigned int getCountColums();
	unsigned int getCountRows();
	unsigned int getCountMoves();

private:

	Ui::AdvancedSettingsWidget *ui;
	unsigned int getCount(QSpinBox* spinBox, const QString& errorMessage);
};
