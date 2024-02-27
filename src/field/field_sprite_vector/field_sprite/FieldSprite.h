#pragma once

#include <QWidget>
#include <QPixmap>
#include <QString>
#include <QObject>
#include <QMap>

#include "ui_FieldSprite.h"



enum ImageType
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
	FieldSprite(QWidget *parent = nullptr, ImageType imageType = ImageType::Grass);
	~FieldSprite();
	FieldSprite(const FieldSprite& other);
	FieldSprite& operator=(const FieldSprite& other);

	void setImage();
	void changeImageId(ImageType imageType);

protected:
	void resizeEvent(QResizeEvent* event) override;

private:
	Ui::FieldSprite *ui;
	ImageType imageType;

	QString getPathToImage(ImageType imageType = ImageType::Grass);

	static QMap<ImageType, QPixmap> imageCache;

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