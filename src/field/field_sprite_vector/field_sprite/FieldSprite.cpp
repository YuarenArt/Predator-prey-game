#include "FieldSprite.h"

const QString FieldSprite::IMAGE_PATH_PREFIX = "././././resources/images";
const QString FieldSprite::IMAGE_PATH_SUFFIX = ".jpg";
const QString FieldSprite::IMAGE_FOLDER_GRASS = "/grass/grass";
const QString FieldSprite::IMAGE_FOLDER_FOREST = "/forest/forest";
const QString FieldSprite::IMAGE_FOLDER_PREY = "/prey/prey";
const QString FieldSprite::IMAGE_FOLDER_PREDATOR = "/predator/predator";
const QString FieldSprite::IMAGE_FOLDER_STONE = "/stone/stone";
const QString FieldSprite::IMAGE_FOLDER_ZOMBIE = "/zombie/zombie";

QMap<ImageType, QPixmap> FieldSprite::imageCache;

FieldSprite::FieldSprite(QWidget* parent, ImageType imageType)
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
        QString pathToImage = getPathToImage(imageType);
        QPixmap image = getImage(pathToImage);
        imageCache.insert(imageType, image);
    }

    QPixmap cachedImage = imageCache.value(imageType);
    cachedImage = cachedImage.scaled(this->size(), Qt::IgnoreAspectRatio);

    QPalette palette;
    palette.setBrush(QPalette::Window, cachedImage);

    this->setAutoFillBackground(true);
    this->setPalette(palette);
}

void FieldSprite::changeImageId(ImageType newImageType)
{
    imageType = newImageType;
}

QString FieldSprite::getPathToImage(ImageType imageType) {

    QString path = IMAGE_PATH_PREFIX;
    switch (imageType) {
    case ImageType::Grass:
        path += IMAGE_FOLDER_GRASS + IMAGE_PATH_SUFFIX;
        break;
    case ImageType::Forest:
        path += IMAGE_FOLDER_FOREST + IMAGE_PATH_SUFFIX;
        break;
    case ImageType::Prey:
        path += IMAGE_FOLDER_PREY + IMAGE_PATH_SUFFIX;
        break;
    case ImageType::Predator:
        path += IMAGE_FOLDER_PREDATOR + IMAGE_PATH_SUFFIX;
        break;
    case ImageType::Stone:
        path += IMAGE_FOLDER_STONE + IMAGE_PATH_SUFFIX;
        break;
    case ImageType::Zombie:
        path += IMAGE_FOLDER_ZOMBIE + IMAGE_PATH_SUFFIX;
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
    setImage();
}

QPixmap getImage(const QString& pathToImage)
{
    QPixmap image(pathToImage);
    return image;
}
