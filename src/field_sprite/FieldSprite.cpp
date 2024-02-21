#include "FieldSprite.h"

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
    QString path = "././resources/images";
    switch (imageId) {
    case Grass:
        path += "/grass/grass.jpg";
        break;
    case Forest:
        path += "/forest/forest.jpg";
        break;
    case Prey:
        path += "/prey/prey.jpg";
        break;
    case Predator:
        path += "/predator/predator.jpg";
        break;
    case Stone:
        path += "/stone/stone.jpg";
        break;
    case Zombie:
        path += "/zombie/zombie.jpg";
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
