#include "Point2D.h"

#include "QDebug"

Point2D::Point2D(int row, int column)
{
    setPoint(row, column);
}

Point2D::Point2D() : row(0), column(0) { }

void Point2D::setPoint(int row, int column) 
{
    setRow(row);
    setColumn(column);
}

void Point2D::setRow(int row)
{
    if (row < 0) {
        qDebug() << "Invalid row value:" << row << ". Using default value: 0.";
        row = 0;
    }
    this->row = row;
}

void Point2D::setColumn(int column)
{
    if (column < 0) {
        qDebug() << "Invalid column value:" << column << ". Using default value: 0.";
        column = 0;
    }
    this->column = column;
}

int Point2D::getRow() const
{
    if (row < 0) {
        qDebug() << "Invalid row value:" << row << ". Using default value: 0.";
        return 0;
    }
    return row;
}

int Point2D::getColumn() const
{
    if (column < 0) {
        qDebug() << "Invalid column value:" << column << ". Using default value: 0.";
        return 0;
    }
    return column;
}

bool Point2D::operator==(const Point2D& rhs) const {
    return (row == rhs.row && column == rhs.column);
}