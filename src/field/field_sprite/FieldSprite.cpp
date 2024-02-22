#include "FieldSprite.h"

const QString FieldSprite::IMAGE_PATH_PREFIX = "./././resources/images";
const QString FieldSprite::IMAGE_PATH_SUFFIX = ".jpg";
const QString FieldSprite::IMAGE_FOLDER_GRASS = "/grass/grass";
const QString FieldSprite::IMAGE_FOLDER_FOREST = "/forest/forest";
const QString FieldSprite::IMAGE_FOLDER_PREY = "/prey/prey";
const QString FieldSprite::IMAGE_FOLDER_PREDATOR = "/predator/predator";
const QString FieldSprite::IMAGE_FOLDER_STONE = "/stone/stone";
const QString FieldSprite::IMAGE_FOLDER_ZOMBIE = "/zombie/zombie";

FieldSprite::FieldSprite(QWidget* parent, int imageId)
    : QWidget(parent), ui(new Ui::FieldSprite())
{
    ui->setupUi(this);
    setImage(imageId);
}

FieldSprite::~FieldSprite()
{
    delete ui;
}

void FieldSprite::setImage(int imageId)
{
    QString pathToImage = getPathToImage(imageId);
    QPixmap image = getImage(pathToImage);

    QSize widgetSize = this->size();
    image = image.scaled(widgetSize, Qt::KeepAspectRatio);

    QPalette palette;
    palette.setBrush(QPalette::Window, image);

    this->setAutoFillBackground(true);
    this->setPalette(palette);
}

QString FieldSprite::getPathToImage(int imageId)
{
    QString path = IMAGE_PATH_PREFIX;
    switch (imageId) {
    case Grass:
        path += IMAGE_FOLDER_GRASS + IMAGE_PATH_SUFFIX;
        break;
    case Forest:
        path += IMAGE_FOLDER_FOREST + IMAGE_PATH_SUFFIX;
        break;
    case Prey:
        path += IMAGE_FOLDER_PREY + IMAGE_PATH_SUFFIX;
        break;
    case Predator:
        path += IMAGE_FOLDER_PREDATOR + IMAGE_PATH_SUFFIX;
        break;
    case Stone:
        path += IMAGE_FOLDER_STONE + IMAGE_PATH_SUFFIX;
        break;
    case Zombie:
        path += IMAGE_FOLDER_ZOMBIE + IMAGE_PATH_SUFFIX;
        break;
    default:
        qDebug() << "Unknown image type:" << imageId;
        break;
    }
    return path;
}

QPixmap getImage(const QString& pathToImage)
{
    QPixmap image(pathToImage);
    return image;
}
