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

ImageType& operator++(ImageType& type);
ImageType operator++(ImageType& type, int);


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

	void changeImageId(ImageType imageType);

protected:
	void resizeEvent(QResizeEvent* event) override;

private:
	Ui::FieldSprite *ui;
	ImageType imageType;

	QString getPathToImage(ImageType imageType = ImageType::Grass);
	void setImageWithWindowSize();
	void addToImageCache(ImageType imageType);
	void setImage();

	static QMap<ImageType, QPixmap> imageCache;

	static const QString PATH_TO_GRASS;
	static const QString PATH_TO_FOREST;
	static const QString PATH_TO_STONE;
	static const QString PATH_TO_PREY;
	static const QString PATH_TO_PREDATOR;
	static const QString PATH_TO_ZOMBIE;
};

QPixmap getImage(const QString& pathToImage);