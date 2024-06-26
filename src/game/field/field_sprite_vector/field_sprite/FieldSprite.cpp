#include "FieldSprite.h"

const QString FieldSprite::PATH_TO_GRASS = ":/PredatorPreyGame/resources/images/grass/grass.jpg";
const QString FieldSprite::PATH_TO_FOREST = ":/PredatorPreyGame/resources/images/forest/forest.jpg";
const QString FieldSprite::PATH_TO_STONE = ":/PredatorPreyGame/resources/images/stone/stone.jpg";
const QString FieldSprite::PATH_TO_PREY = ":/PredatorPreyGame/resources/images/prey/prey.jpg";
const QString FieldSprite::PATH_TO_PREDATOR = ":/PredatorPreyGame/resources/images/predator/predator.jpg";
const QString FieldSprite::PATH_TO_ZOMBIE = ":/PredatorPreyGame/resources/images/zombie/zombie.jpg";

QMap<MyGame::ImageType, QPixmap> FieldSprite::imageCache;

FieldSprite::FieldSprite(QWidget* parent, MyGame::ImageType imageType)
    : QWidget(parent), ui(new Ui::FieldSprite()), imageType(imageType)
{
    ui->setupUi(this);
    setImage();
}

FieldSprite::~FieldSprite()
{
    delete ui;
}

FieldSprite::FieldSprite(const FieldSprite& other)
    : QWidget(nullptr), ui(new Ui::FieldSprite)
{
    ui->setupUi(this);
    imageType = other.imageType;
    setImage();

}

FieldSprite& FieldSprite::operator=(const FieldSprite& other) {
    if (this != &other) {
        imageType = other.imageType;
        setImage(); 
    }
    return *this;
}

void FieldSprite::setImage()
{
    if (!imageCache.contains(imageType)) {
        addToImageCache(imageType);
    }

    setImageWithWindowSize();
}

void  FieldSprite::addToImageCache(MyGame::ImageType imageType) {
    QString pathToImage = getPathToImage(imageType);
    QPixmap image = getImage(pathToImage);
    imageCache.insert(imageType, image);
}

void FieldSprite::setImageWithWindowSize()
{
    QPixmap cachedImage = imageCache.value(imageType);
    cachedImage = cachedImage.scaled(this->size(), Qt::IgnoreAspectRatio, Qt::SmoothTransformation);

    QPalette palette;
    palette.setBrush(QPalette::Window, cachedImage);

    this->setAutoFillBackground(true);
    this->setPalette(palette);

}

void FieldSprite::changeImageId(MyGame::ImageType newImageType)
{
    imageType = newImageType;
    setImage();
}

QString FieldSprite::getPathToImage(MyGame::ImageType imageType) {
    QString path;

    using namespace MyGame;

    switch (imageType) {
    case ImageType::grass:
        path = PATH_TO_GRASS;
        break;
    case ImageType::forest:
        path = PATH_TO_FOREST;
        break;
    case ImageType::prey:
        path = PATH_TO_PREY;
        break;
    case ImageType::predator:
        path = PATH_TO_PREDATOR;
        break;
    case ImageType::stone:
        path = PATH_TO_STONE;
        break;
    case ImageType::zombie:
        path = PATH_TO_ZOMBIE;
        break;
    default:
        qDebug() << "Unknown image type:" << static_cast<int>(imageType);
        break;
    }
    return path;
}

void FieldSprite::resizeEvent(QResizeEvent* event)
{
    QWidget::resizeEvent(event);
    setImageWithWindowSize();
}

QPixmap getImage(const QString& pathToImage)
{
    QPixmap image(pathToImage);
    return image;
}
