#include "FieldSpriteVector.h"
#include <QRandomGenerator>

FieldSpriteVector::FieldSpriteVector(QWidget* parent, int rows, int columns) 
    : QWidget(parent), ui(new Ui::FieldSpriteVector())
{
    ui->setupUi(this);
}

FieldSpriteVector::~FieldSpriteVector()
{
    delete ui;
}

FieldSpriteVector& FieldSpriteVector::operator=(const FieldSpriteVector& other)
{
    if (this != &other)
    {
        fieldSpriteVector.clear();

        for (const auto& innerVector : other.fieldSpriteVector)
        {
            QVector<FieldSprite> tempInnerVector;
            for (const auto& sprite : innerVector)
            {
                tempInnerVector.append(sprite);
            }
            fieldSpriteVector.append(tempInnerVector);
        }
    }
    return *this;
}

int FieldSpriteVector::getRowCount() {
    return fieldSpriteVector.size();
}

int FieldSpriteVector::getColumnsCount() {
    if (fieldSpriteVector.isEmpty()) {
        return 0;
    }
    return fieldSpriteVector.at(0).size();
}

void FieldSpriteVector::fillFieldWithMatrix(QVector<QVector<ImageType>> matrix) {

    for (int i = 0; i < matrix.size(); ++i) {
        QVector<FieldSprite> innerVector;
        for (int j = 0; j < matrix[0].size(); ++j) {
            FieldSprite sprite(this, matrix[i][j]);
            innerVector.append(sprite);
        }
        fieldSpriteVector.append(innerVector);
    }
}

void FieldSpriteVector::fillFieldWithRandom(int rows, int columns) {

    for (int i = 0; i < rows; ++i) {
        QVector<FieldSprite> innerVector;
        for (int j = 0; j < columns; ++j) {
            int randomIndex = QRandomGenerator::global()->bounded(6);
            ImageType randomImage = static_cast<ImageType>(randomIndex);
            FieldSprite sprite(this, randomImage);
            innerVector.append(sprite);
        }
        fieldSpriteVector.append(innerVector);
    }
}

void FieldSpriteVector::fillSpriteGrid() 
{
    int row = getRowCount();
    int columns = getColumnsCount();

    for (int i = 0; i < row; ++i) {
        for (int j = 0; j < columns; ++j) {
            FieldSprite& sprite = fieldSpriteVector[i][j];
            ui->spriteGrid->addWidget(&sprite, i, j);
        }
    }

}

void FieldSpriteVector::changeImageTypeInVector(int row, int column, ImageType imageType)
{
    fieldSpriteVector[row][column].changeImageId(imageType);
}
