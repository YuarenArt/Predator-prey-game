#include "AdvancedSettingsWidget.h"

const QString COLUMN_COUNT_ERROR = "Invalid value for column count";
const QString ROW_COUNT_ERROR = "Invalid value for row count";
const QString MOVE_COUNT_ERROR = "Invalid value for move count";
const unsigned int DEFAULT_COUNT = 10;

AdvancedSettingsWidget::AdvancedSettingsWidget(QWidget *parent)
	: QWidget(parent)
	, ui(new Ui::AdvancedSettingsWidget())
{
	ui->setupUi(this);

	setWindowFlags(Qt::WindowStaysOnTopHint);
	setWindowFlags(Qt::FramelessWindowHint);

	connect(ui->okButton, &QPushButton::clicked, this, &QWidget::close);
}

AdvancedSettingsWidget::~AdvancedSettingsWidget()
{
	delete ui;
}

unsigned int AdvancedSettingsWidget::getCount(QSpinBox* spinBox, const QString& errorMessage)
{
	bool ok;
	int value = spinBox->value();
	if (value > 0) {
		return value;
	}
	else {
		qDebug() << "Error:" << errorMessage;
		return DEFAULT_COUNT;
	}
}

unsigned int AdvancedSettingsWidget::getCountColums()
{
	return getCount(ui->columnsCount, COLUMN_COUNT_ERROR);
}

unsigned int AdvancedSettingsWidget::getCountRows()
{
	return getCount(ui->rowsCount, ROW_COUNT_ERROR);
}

unsigned int AdvancedSettingsWidget::getCountMoves()
{
	return getCount(ui->movesCount, MOVE_COUNT_ERROR);
}
