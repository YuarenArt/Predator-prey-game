#pragma once

#include <QWidget>
#include <QPixmap>
#include <QString>
#include <QObject>

#include "ui_FieldSprite.h"

enum Image
{
	Grass,
	Prey,
	Predator,
	Forest,
	Stone,
	Zombie
};

QT_BEGIN_NAMESPACE
namespace Ui { class FieldSprite; };
QT_END_NAMESPACE

class FieldSprite : public QWidget
{
	Q_OBJECT

public:
	FieldSprite(QWidget *parent = nullptr, int imageId = 0);
	~FieldSprite();

private:
	Ui::FieldSprite *ui;

	void setImage(int imageId = 0);
	QString getPathToImage(int imageId = 0);

	static const QString IMAGE_PATH_PREFIX; 
	static const QString IMAGE_PATH_SUFFIX; 
	static const QString IMAGE_FOLDER_GRASS; 
	static const QString IMAGE_FOLDER_FOREST; 
	static const QString IMAGE_FOLDER_PREY; 
	static const QString IMAGE_FOLDER_PREDATOR; 
	static const QString IMAGE_FOLDER_STONE; 
	static const QString IMAGE_FOLDER_ZOMBIE; 
};

QPixmap getImage(const QString& pathToImage);