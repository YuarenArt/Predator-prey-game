#include "Point2DTest.h"
#include "../../../../position/point2D/point2D.h"

#include <QVector>

// Define the vector of test points as a static member variable of the test class
const QVector<Point2D> testPoints = {
    Point2D(-4,  2),
    Point2D(3,   4),
    Point2D(-1, -1),
    Point2D(0,   0),
    Point2D(1,  -1)
};

QVector<int> expectedRows = { 0, 3, 0, 0, 1 };
QVector<int> expectedColumns = { 2, 4, 0, 0, 0 };

void Point2DTest::testConstructor() {
    for (int i = 0; i < testPoints.size(); i++) {
        QCOMPARE(testPoints[i].getRow(), expectedRows[i]);
        QCOMPARE(testPoints[i].getColumn(), expectedColumns[i]);
    }
}

void Point2DTest::testSetPoint() {
    QVector<QPair<int, int>> setPoints = { {5, 6}, {-1, -1}, {0, 0}, {1, -1} };
    QVector<int> expectedRows = { 5, 0, 0, 1 };
    QVector<int> expectedColumns = { 6, 0, 0, 0 };

    for (int i = 0; i < setPoints.size(); i++) {
        Point2D point(testPoints[0]);
        point.setPoint(setPoints[i].first, setPoints[i].second);
        QCOMPARE(point.getRow(), expectedRows[i]);
        QCOMPARE(point.getColumn(), expectedColumns[i]);
    }
}

void Point2DTest::testSetRow() {
    QVector<int> setRows = { 7, -1, 1 };
    QVector<int> expectedRows = { 7, 0, 1 };

    for (int i = 0; i < setRows.size(); i++) {
        Point2D point(testPoints[0]);
        point.setRow(setRows[i]);
        QCOMPARE(point.getRow(), expectedRows[i]);
    }
}

void Point2DTest::testSetColumn() {
    QVector<int> setColumns = { 8, -1, 1 };
    QVector<int> expectedColumns = { 8, 0, 1 };

    for (int i = 0; i < setColumns.size(); i++) {
        Point2D point(testPoints[0]);
        point.setColumn(setColumns[i]);
        QCOMPARE(point.getColumn(), expectedColumns[i]);
    }
}

void Point2DTest::testGetRow() {
    for (int i = 0; i < testPoints.size(); i++) {
        QCOMPARE(testPoints[i].getRow(), expectedRows[i]);
    }
}

void Point2DTest::testGetColumn() {
    for (int i = 0; i < testPoints.size(); i++) {
        QCOMPARE(testPoints[i].getColumn(), expectedColumns[i]);
    }
}

void Point2DTest::testEqualityOperator() {
    Point2D point1(13, 14);
    Point2D point2(13, 14);
    Point2D point3(15, 14);

    QVERIFY(point1 == point2);
    QVERIFY(!(point1 == point3));
}
