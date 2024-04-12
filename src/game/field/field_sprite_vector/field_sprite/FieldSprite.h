#pragma once

#include <QWidget>
#include <QPixmap>
#include <QString>
#include <QObject>
#include <QMap>

#include "ui_FieldSprite.h"
#include "../../enums/enums.h"


QT_BEGIN_NAMESPACE
namespace Ui { class FieldSprite; };
QT_END_NAMESPACE

class FieldSprite : public QWidget
{
	Q_OBJECT

public:
	FieldSprite(QWidget *parent = nullptr, MyGame::ImageType imageType = MyGame::ImageType::grass);
	~FieldSprite();
	FieldSprite(const FieldSprite& other);
	FieldSprite& operator=(const FieldSprite& other);

	void changeImageId(MyGame::ImageType imageType);

protected:
	void resizeEvent(QResizeEvent* event) override;

private:
	Ui::FieldSprite  *ui;
	MyGame::ImageType imageType;

	QString getPathToImage(MyGame::ImageType imageType = MyGame::ImageType::grass);
	void    setImageWithWindowSize();
	void    addToImageCache(MyGame::ImageType imageType);
	void    setImage();

	static QMap<MyGame::ImageType, QPixmap> imageCache;

	static const QString PATH_TO_GRASS;
	static const QString PATH_TO_FOREST;
	static const QString PATH_TO_STONE;
	static const QString PATH_TO_PREY;
	static const QString PATH_TO_PREDATOR;
	static const QString PATH_TO_ZOMBIE;
};

QPixmap getImage(const QString& pathToImage);