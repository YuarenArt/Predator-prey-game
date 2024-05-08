#pragma once

#include <QTest>

class Point2DTest : public QObject
{
    Q_OBJECT

public:
    Point2DTest() {};

private slots:
    void testConstructor();
    void testSetPoint();
    void testSetRow();
    void testSetColumn();
    void testGetRow();
    void testGetColumn();
    void testEqualityOperator();
};
